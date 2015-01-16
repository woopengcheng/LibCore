#ifndef __libcore_marshal_h__
#define __libcore_marshal_h__
#include "Common.h"
#include "Log.h" 


namespace LibCore
{
	class CStream;

	class DLL_EXPORT Marshal
	{
	public:
		virtual CStream & marshal(CStream & cs) = 0;
		virtual CStream & unMarshal(CStream & cs) = 0;
	};
}

#endif