#ifndef __cutil_c_stream_h__
#define __cutil_c_stream_h__
#include "Common/inc/Common.h"
#include "Common/inc/Chunk.h"
#include "Marshal/inc/Marshal.h"
#include "Marshal/inc/CommonMarshal.h"
#include "Common/inc/BoostHelper.h"

namespace Msg
{
	class Object;
}

namespace CUtil
{
	class DLL_EXPORT CStream
	{
	public:
		CStream()
			: m_nCurPos(0)
			, m_nTransactionPos(0)
		{

		}

		CStream(const CStream & cs) 
		{
			m_nCurPos = cs.GetCurPos();
			m_nTransactionPos = cs.GetTransactionPos();
			m_objChunk = cs.GetData();
		}

		CStream(const char * pBuf , UINT32 unLength)
			: m_nCurPos(0)
			, m_nTransactionPos(0)
			, m_objChunk((void*)pBuf , unLength)
		{

		}
		~CStream(){}

		void Copy(const CStream & cs) 
		{
			m_nCurPos = cs.GetCurPos();
			m_nTransactionPos = cs.GetTransactionPos();
			m_objChunk = cs.GetData();
		}

	public:
		CStream & operator = (const CStream & cs)
		{
			m_nCurPos = cs.GetCurPos();
			m_nTransactionPos = cs.GetTransactionPos();
			m_objChunk = cs.GetData();

			return *this;
		}

	public:
		template<typename T>
		CStream & Pushback(T  t)
		{
			m_objChunk.Pushback(&t , sizeof(t));

			return * this;
		}
		 
		CStream & Pushback(void * pBuf , UINT32 unSize)
		{
			m_objChunk.Pushback(pBuf , unSize); 

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

		CStream & Pop(void *& pBuf , UINT32 unSize)
		{
			MsgAssert_Re (m_nCurPos + unSize <= m_objChunk.GetDataLen() , *this , "CStream pop error.");
			pBuf = ( (char *)m_objChunk.Begin() + m_nCurPos);
			m_nCurPos += unSize;

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
		CStream & operator << (Msg::Object & t);	 
		CStream & operator << (CStream & t);	 

		template<typename T> CStream & operator << (std::basic_string<T> & t)
		{
			STATIC_ASSERT(sizeof(T) == 1);  //5 测试是否是单字节.utf16和utf32.单独处理
			UINT32 unBytes = (UINT32)(t.size() )* sizeof(T);
			Pushback(unBytes);
//			m_objChunk.Insert(m_objChunk.End() , (void*)t.c_str() , (UINT32)unBytes);
			m_objChunk.Pushback((void*)t.c_str() , (UINT32)unBytes);

			return *this;
		}
		template<typename T> CStream & operator << (const std::basic_string<T> & t)
		{
			return operator << (*const_cast<std::basic_string<T>*>(&t)); 
		}

		template<typename T1 , typename T2> CStream & operator << (std::pair<T1 , T2> & t)
		{
			return *this << t.first << t.second;
		} 

		template<typename T1> CStream & operator << (std::vector<T1> & t)
		{
			return *this << STLContainer<std::vector<T1>>(t);
		} 

		template<typename T1> CStream & operator << (std::list<T1> & t)
		{
			return *this << STLContainer<std::list<T1>>(t);
		} 
		
		template<typename T1> CStream & operator << (std::deque<T1> & t)
		{
			return *this << STLContainer<std::deque<T1>>(t);
		} 

		template<typename T1> CStream & operator << (std::set<T1> & t)
		{
			return *this << STLContainer<std::set<T1>>(t);
		} 

		template<typename T1 , typename T2> CStream & operator << (std::map<T1 , T2> & t)
		{
			return *this << STLContainer<std::map<T1 , T2> >(t);
		} 

	public:
		CStream & operator >> (char & t)			{ return Pop(t);}  
		CStream & operator >> (UINT8 & t)			{ return Pop(t);} 
		CStream & operator >> (bool & t)			{ return Pop(t);} 
		CStream & operator >> (INT16 & t)			{ return Pop(t);} 
		CStream & operator >> (UINT16 & t)			{ return Pop(t);} 
		CStream & operator >> (long & t)			{ return Pop(t);} 
		CStream & operator >> (INT32 & t)			{ return Pop(t);} 
		CStream & operator >> (UINT32 & t)			{ return Pop(t);} 
		CStream & operator >> (INT64 & t)			{ return Pop(t);} 
		CStream & operator >> (UINT64 & t)			{ return Pop(t);} 
		CStream & operator >> (float & t)			{ return Pop(t);} 
		CStream & operator >> (double & t)			{ return Pop(t);} 
		CStream & operator >> (Marshal & t)			{ return t.unMarshal(*this); } 
		CStream & operator >> (Chunk & t);
		CStream & operator >> (Msg::Object & t);
		CStream & operator >> (CStream & t);	 

		template<typename T> CStream & operator >> (std::basic_string<T> & t)
		{
			STATIC_ASSERT(sizeof(t) == 1);  //5 测试是否是单字节.utf16和utf32.单独处理
			
			UINT32 unBytes = 0;
			Pop(unBytes);

			MsgAssert_Re(!(unBytes % sizeof(T)) , *this , "unMarshal invalid length.");
			MsgAssert_Re(!(unBytes > m_objChunk.GetDataLen() - m_nCurPos) , *this , "unMarshal invalid length.");
			
			t.assign((T*)((char *)m_objChunk.Begin() + m_nCurPos) , unBytes / sizeof(T));
			m_nCurPos += unBytes;
			return *this;
		}
		template<typename T> CStream & operator >> (const std::basic_string<T> & t)
		{ 
			return operator >> (*const_cast<std::basic_string<T>*>(&t)); 
		}

		template<typename T1 , typename T2> CStream & operator >> (std::pair<T1 , T2> & t)
		{
			return *this >> t.first >> t.second;
		}
		
		template<typename T1> CStream & operator >> (std::vector<T1> & t)
		{
			return *this >> STLContainer<std::vector<T1>>(t);
		} 

		template<typename T1> CStream & operator >> (std::list<T1> & t)
		{
			return *this >> STLContainer<std::list<T1>>(t);
		} 
		
		template<typename T1> CStream & operator >> (std::deque<T1> & t)
		{
			return *this >> STLContainer<std::deque<T1>>(t);
		} 

		template<typename T1> CStream & operator >> (std::set<T1> & t)
		{
			return *this >> STLContainer<std::set<T1>>(t);
		} 

		template<typename T1 , typename T2> CStream & operator >> (std::map<T1 , T2> & t)
		{
			return *this >> STLContainer<std::map<T1 , T2> >(t);
		} 
		CStream & operator >> (Marshal::Transaction  t) 
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
			return *this;
		}

		public: 
			UINT32  GetDataLen( void ) const { return m_objChunk.GetDataLen(); }
			INT32   GetCurPos( void )const { return m_nCurPos; }
			INT32   GetTransactionPos( void ) const { return m_nTransactionPos;	}
			Chunk   GetData( void ) const { return m_objChunk;	}
			Chunk & GetData( void ) { return m_objChunk;	}
			void  * Begin(){ return m_objChunk.Begin(); }
			void  * End(){ return m_objChunk.End(); }
			void    Insert(void * pPos , void * pBegin , UINT32 unLen){ m_objChunk.Insert(pPos , pBegin , unLen); } 
			void    Clear(){ m_objChunk.Clear(); m_nCurPos = 0; m_nTransactionPos = 0; } 

	protected:
		INT32   m_nCurPos;			 //5 记录当前流的位置.
		INT32   m_nTransactionPos;   //5 将流作为事务处理.
		Chunk   m_objChunk;
	};
}


#endif