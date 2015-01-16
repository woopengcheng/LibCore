#ifndef __libcore_c_stream_h__
#define __libcore_c_stream_h__
#include "Common.h"
#include "Chunk.h"
#include "Marshal.h"

namespace LibCore
{
	class DLL_EXPORT CStream
	{
	public:
		CStream()
			: m_nCurPos(0)
		{

		}
		~CStream(){}

	public:
		template<typename T>
		CStream & Pushback(T  t)
		{
			m_objChunk.Pushback(&t , sizeof(t));

			return * this;
		}

		template<typename T>
		CStream & Pop(T & t)
		{
			MsgAssert_Re (m_nCurPos + sizeof(t) <= m_objChunk.GetDataLen() , *this , "CStream pop error.");

			t = *(T*)( (char *)m_objChunk.Begin() + m_nCurPos);
			m_nCurPos += sizeof(t);

			return * this;
		}

	public:
		CStream & operator << (char t)				{ return Pushback(t);} 
		CStream & operator << (UINT8 t)				{ return Pushback(t);} 
		CStream & operator << (bool t)				{ return Pushback(t);} 
		CStream & operator << (INT16 t)				{ return Pushback(t);} 
		CStream & operator << (UINT16 t)			{ return Pushback(t);} 
		CStream & operator << (INT32 t)				{ return Pushback(t);} 
		CStream & operator << (UINT32 t)			{ return Pushback(t);} 
		CStream & operator << (INT64 t)				{ return Pushback(t);} 
		CStream & operator << (UINT64 t)			{ return Pushback(t);} 
		CStream & operator << (float t)				{ return Pushback(t);} 
		CStream & operator << (double t)			{ return Pushback(t);} 
		CStream & operator << (Marshal & t)			{ return t.marshal(*this); } 
		CStream & operator << (Chunk & t);	

		template<typename T> CStream & operator << (std::basic_string<T> & t)
		{

		}

	public:
		CStream & operator >> (char t)				{ return Pop(t);} 
		CStream & operator >> (UINT8 t)				{ return Pop(t);} 
		CStream & operator >> (bool t)				{ return Pop(t);} 
		CStream & operator >> (INT16 t)				{ return Pop(t);} 
		CStream & operator >> (UINT16 t)			{ return Pop(t);} 
		CStream & operator >> (INT32 t)				{ return Pop(t);} 
		CStream & operator >> (UINT32 t)			{ return Pop(t);} 
		CStream & operator >> (INT64 t)				{ return Pop(t);} 
		CStream & operator >> (UINT64 t)			{ return Pop(t);} 
		CStream & operator >> (float t)				{ return Pop(t);} 
		CStream & operator >> (double t)			{ return Pop(t);} 
		CStream & operator >> (Marshal & t)			{ return t.unMarshal(*this); } 
		CStream & operator >> (Chunk & t);

	protected:
		INT32   m_nCurPos;   //5 记录当前流的位置.
		Chunk   m_objChunk;
	};
}


#endif