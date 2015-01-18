#ifndef __libcore_common_marshal_h__
#define __libcore_common_marshal_h__
#include "Marshal/Marshal.h"


namespace LibCore
{
	class CStream;

	class DLL_EXPORT CharPtr : public LibCore::Marshal
	{ 
	public:
		CharPtr( void ): m_pBuf(NULL) , m_unLen(0) {}
		CharPtr(char * pBuf , UINT32 unLen) : m_pBuf(pBuf) , m_unLen(unLen) {}

	public:
		virtual CStream & marshal(CStream & cs);
		virtual CStream & unMarshal(CStream & cs);

	protected:
		char * m_pBuf;
		UINT32 m_unLen;
	};
}

#endif