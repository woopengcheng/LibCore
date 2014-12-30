#ifndef __libcore_h__
#define __libcore_h__
#include "Common.h"
 
namespace LibCore
{ 
	extern INT32 DLL_EXPORT Init(std::string strLogFile = "LibCore");
	extern INT32 DLL_EXPORT Cleanup( void );

	extern void  DLL_EXPORT GenerateUUIDBySys( char* buf );
 	extern INT64 DLL_EXPORT GenerateUUIDByTime( void );
}
#endif