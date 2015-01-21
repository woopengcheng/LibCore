#include "Marshal\CStream.h"
#include "Marshal\MashalTest.h"
#include "MsgLib\inc\Object.h"

namespace LibCore
{  

	CStream & MarshalTest::marshal(CStream & cs)
	{  
		cs << m_nTest;
		cs.Pushback(m_nTest);
		gDebugStream(m_nTest << " MarshalTest::marshal m_nTest ");
		return cs; 
	}

	CStream & MarshalTest::unMarshal(CStream & cs)
	{  
		cs >> m_nTest;
		cs.Pop(m_nTest);
		gDebugStream(m_nTest << " MarshalTest::unMarshal m_nTest ");
		return cs;
	} 

	CStream & CStream::operator<<(Chunk & t)			
	{
		Pushback(t.GetDataLen()); 
		m_objChunk.Pushback(t.Begin() , t.GetDataLen());
		return *this;
	} 

	CStream & CStream::operator>>(Chunk & t)
	{
		UINT32 unLen = 0;
		Pop(unLen);
		if (unLen > m_objChunk.GetDataLen() - m_nCurPos)
		{
			gErrorStream("CStream pop error");
			return *this;
		}
		char * pBuf = (char *)m_objChunk.Begin() + m_nCurPos;
		t.Pushback(pBuf , unLen);
		return *this;
	} 

	CStream & CStream::operator<<(Msg::Object & t)			
	{
		*this << t.m_llObjID;
		 
		return *this;
	} 

	CStream & CStream::operator>>(Msg::Object & t)			
	{
		*this >> t.m_llObjID;

		return *this;
	} 
}