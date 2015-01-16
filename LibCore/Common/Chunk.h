#ifndef __libcore_chunk_h__
#define __libcore_chunk_h__ 
#include "MsgCommon.h" 

namespace LibCore
{ 
	class DLL_EXPORT Chunk
	{
	public: 
		Chunk() : m_unSize(0) , m_unDataLen(0) , m_pBuf(NULL){}
		Chunk(void * pBuf , UINT32 unChunkSize);
		~Chunk();

	public:
		Chunk   &  Pushback(void * pBegin , UINT32 unLen);
		Chunk   &  Insert(void * pPos , void * pBegin , UINT32 unLen);
		Chunk   &  Reverse(UINT32 unSize);
		void	*  Create(UINT32 unSize);
		void       Release( void );
		char    *  End( void );
		char    *  Begin( void );

	public:
		char    *  GetBuf(){ return m_pBuf; }
		void       SetBuf(void * pBuf){ m_pBuf = (char *)pBuf; }
		UINT32     GetSize(){ return m_unSize; }
		void       SetSize(UINT32 unChunkSize){ m_unSize = unChunkSize; }
		UINT32     GetDataLen() const { return m_unDataLen; }
		void	   SetDataLen(UINT32 val) { m_unDataLen = val; }

	private:
		UINT32     FitSize(UINT32 unSize);

	private:
		char    *  m_pBuf;
		UINT32     m_unSize;
		UINT32     m_unDataLen;
	};

}
#endif