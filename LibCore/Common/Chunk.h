#ifndef __libcore_chunk_h__
#define __libcore_chunk_h__ 
#include "Common/Common.h" 

namespace LibCore
{ 
	class DLL_EXPORT Chunk
	{
	public: 
		Chunk() : m_unSize(0) , m_unDataLen(0) , m_pBuf(NULL) , m_bMustRelease(TRUE){}
		Chunk(void * pBuf , UINT32 unChunkSize , BOOL bMustRelease = TRUE);
		Chunk(UINT32 unChunkSize);
		Chunk(const Chunk & objChunk);
		~Chunk();

	public:
		Chunk	&  operator = (const Chunk & objChunk);

	public:
		virtual Chunk   &  Insert(void * pPos , void * pBegin , UINT32 unLen);
		virtual Chunk   &  Pushback (void * pBegin , UINT32 unLen); 
		virtual Chunk   &  Erase(void * pBegin , void * pEnd);
		virtual Chunk   &  Reverse(UINT32 unSize);
		virtual void	*  Create(UINT32 unSize);
		virtual void    *  Begin( void );
		virtual void    *  End( void );
		virtual void       Clear( void );
		virtual void       Release( void );

	public:
		void    *  GetBuf() const { return m_pBuf; }
		void       SetBuf(void * pBuf){ m_pBuf = (char *)pBuf; }
		UINT32     GetSize() const { return m_unSize; }
		void       SetSize(UINT32 unChunkSize){ m_unSize = unChunkSize; }
		UINT32     GetDataLen() const { return m_unDataLen; }
		void	   SetDataLen(UINT32 val) { m_unDataLen = val; }
		BOOL	   IsForceCopy() { return m_bMustRelease; }

	private:
		UINT32     FitSize(UINT32 unSize);

	private:
		void    *  m_pBuf;
		UINT32     m_unSize;
		UINT32     m_unDataLen;
		BOOL       m_bMustRelease;
	};

	template<UINT32 unSize> 
	class StackChunk : public Chunk
	{ 
	public:  
		StackChunk()
			: Chunk((void*)m_szBuffer , unSize , FALSE)
		{

		}

	private:
		char  m_szBuffer[unSize];
	};
}
#define LibCore_Chunk LibCore::Chunk
#endif
