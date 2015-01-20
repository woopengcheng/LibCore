#ifndef __libcore_chunk_h__
#define __libcore_chunk_h__ 
#include "Common/Common.h" 

namespace LibCore
{ 
	class DLL_EXPORT Chunk
	{
	public: 
		Chunk() : m_unSize(0) , m_unDataLen(0) , m_pBuf(NULL){}
		Chunk(void * pBuf , UINT32 unChunkSize);
		Chunk(const Chunk & objChunk);
		~Chunk();

	public:
		Chunk	&  operator = (const Chunk & objChunk);

	public:
		Chunk   &  Insert(void * pPos , void * pBegin , UINT32 unLen);
		Chunk   &  Pushback(void * pBegin , UINT32 unLen); 
		Chunk   &  Erase(void * pBegin , void * pEnd);
		Chunk   &  Reverse(UINT32 unSize);
		void	*  Create(UINT32 unSize);
		void       Release( void );
		void    *  Begin( void );
		void    *  End( void );

	public:
		void    *  GetBuf() const { return m_pBuf; }
		void       SetBuf(void * pBuf){ m_pBuf = (char *)pBuf; }
		UINT32     GetSize() const { return m_unSize; }
		void       SetSize(UINT32 unChunkSize){ m_unSize = unChunkSize; }
		UINT32     GetDataLen() const { return m_unDataLen; }
		void	   SetDataLen(UINT32 val) { m_unDataLen = val; }

	private:
		UINT32     FitSize(UINT32 unSize);

	private:
		void    *  m_pBuf;
		UINT32     m_unSize;
		UINT32     m_unDataLen;
	};

}
#endif