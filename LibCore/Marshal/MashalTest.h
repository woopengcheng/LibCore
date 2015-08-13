#ifndef __cutil_marshal_test_h__
#define __cutil_marshal_test_h__
#include "Marshal/Marshal.h"
#include "LogLib/inc/Log.h"

namespace CUtil
{
	class CStream;

	class DLL_EXPORT MarshalTest : public Marshal
	{
	public:
		MarshalTest(int nValue):m_nTest(nValue){}
		CStream & marshal(CStream & cs);
		CStream & unMarshal(CStream & cs);

	private:
		INT32 m_nTest;
	};
}

#endif