#include "Chunk.h"
#include "LibCore.h"

namespace LibCore
{ 

	Chunk::Chunk(void * pBuf , UINT32 unChunkSize)
		: m_unSize(unChunkSize)
		, m_unDataLen(unChunkSize)
		, m_pBuf(NULL)
	{
		if (unChunkSize)
		{
			Reverse(unChunkSize); 
			memcpy(m_pBuf , pBuf , unChunkSize);
		}
	}

	Chunk::~Chunk()
	{
		Release();
	}

	Chunk & Chunk::Reverse(UINT32 unSize)
	{
		if (unSize == 0)
		{ 
			return *this;
		}

		unSize = FitSize(unSize);

		if (unSize > m_unSize)
		{
			void * pBuf = Create(unSize);
			memcpy(pBuf , m_pBuf , m_unSize);

			Release();
			m_unSize = unSize;
			m_pBuf = pBuf;
		}

		return *this;
	}

	UINT32 Chunk::FitSize(UINT32 unSize)
	{
		UINT32 unTmp = 8;
		while (unSize > unTmp)
		{
			unTmp <<= 1;
		}

		return unTmp;
	}

	void	* Chunk::Create(UINT32 unSize)
	{ 
		void * pBuf = new char[unSize];

		return pBuf;
	}

	Chunk   & Chunk::Insert(void * pPos , void * pBegin , UINT32 unLen)
	{
		Reverse(m_unSize + unLen);

		PtrDiff off = (char *)pPos - (char *)m_pBuf;
		pPos = (char *)m_pBuf + off;

		UINT32 unAdjust = m_unSize - (UINT32)off;  //5 这里是万一向中间内存块插入
		if (unAdjust)
		{
			FastMemmove((char *)pPos + unLen , pPos , unAdjust);
		}

		FastMemmove((char *)pPos , pBegin , unLen);
		m_unDataLen += unLen;

		return *this;
	}

	void Chunk::Release(void)
	{
		if (m_unSize != 0 && m_pBuf)
		{
			SAFE_DELETE(m_pBuf);
		}
	}

	Chunk   & Chunk::Pushback(void * pBegin , UINT32 unLen)
	{
		Reverse(m_unSize + unLen);

		FastMemmove((char *)m_pBuf + m_unDataLen , pBegin , unLen);
		m_unDataLen += unLen;

		return *this;
	}

	void    * Chunk::End(void)
	{
		return (char *)m_pBuf + m_unDataLen;
	}

	void    * Chunk::Begin(void)
	{
		return m_pBuf;
	}

}