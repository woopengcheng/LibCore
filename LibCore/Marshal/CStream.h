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
			, m_nTransactionPos(0)
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
			STATIC_ASSERT(sizeof(t) == 1);  //5 测试是否是单字节.utf16和utf32.单独处理
			UINT32 unBytes = t.length() * sizeof(T);
			Pushback(unBytes);
			m_objChunk.Insert(m_objChunk.End() , t.c_str() , unBytes);
		}

		template<typename T1 , typename T2> CStream & operator << (std::pair<T1 , T2> & t)
		{
			return *this << t.first << t.second;
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

		template<typename T> CStream & operator >> (std::basic_string<T> & t)
		{
			STATIC_ASSERT(sizeof(t) == 1);  //5 测试是否是单字节.utf16和utf32.单独处理
			
			UINT32 unBytes = 0;
			Pop(unBytes);

			MsgAssert_Re(!(unBytes % sizeof(unBytes)) , *this , "unMarshal invalid length.");
			MsgAssert_Re(!(unBytes > m_objChunk.GetDataLen() - m_nCurPos) , *this , "unMarshal invalid length.");
			
			t.assign((T*)((char *)m_objChunk.Begin() + m_nCurPos) , unBytes / sizeof(T));
		}

		template<typename T1 , typename T2> CStream & operator << (std::pair<T1 , T2> & t)
		{
			return *this >> t.first >> t.second;
		}

		CStream & operator >> (Marshal::Transaction & t)
		{
			switch(t)
			{
			case Marshal::Begin:
				{
					m_nTransactionPos = m_nCurPos;
				}break;
			case Marshal::Rollback:
				{
					m_nCurPos = m_nTransactionPos;
				}break;
			case Marshal::End:
				{

				}break;
			default:
				{
					MsgAssert_Re(0 , *this , "Marshal::Transaction type error.");
				}
			}
			return *this << t.first << t.second;
		}
	protected:
		INT32   m_nCurPos;			 //5 记录当前流的位置.
		INT32   m_nTransactionPos;   //5 将流作为事务处理.
		Chunk   m_objChunk;
	};
}


#endif