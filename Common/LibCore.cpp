#include "LibCore.h"
#include "Log.h"
#include "NetCommon.h" 
#include "TimerHelp.h"
 
#ifdef WIN32
#include <ObjBase.h>
#else
#include <uuid/uuid.h>
#endif

namespace LibCore
{
	void GenerateUUIDBySys( char* buf )
	{

#ifdef WIN32
		GUID FilterCLSID;
		CoCreateGuid(&FilterCLSID);

		sprintf(buf, "%08X_%04X_%04X_%02X%02X_%02X%02X%02X%02X%02X%02X",
			FilterCLSID.Data1, FilterCLSID.Data2, FilterCLSID.Data3,
			FilterCLSID.Data4[0], FilterCLSID.Data4[1], FilterCLSID.Data4[2], FilterCLSID.Data4[3], 
			FilterCLSID.Data4[4], FilterCLSID.Data4[5], FilterCLSID.Data4[6], FilterCLSID.Data4[7]
		);
#else
		uuid_t uid;
		uuid_generate(uid);
		uuid_unparse(uid,buf);
#endif 
	}

	INT64 GenerateUUIDByTime( void )
	{ 
		return (Timer::TimerHelper::GetTickCount());
	}

	INT32 DLL_EXPORT Init(std::string strLogFile)
	{ 
		Log::Init(strLogFile.c_str() , NULL , 0);
		Net::InitNet();  

		return 0;
	}

	INT32 DLL_EXPORT Cleanup( void)
	{ 
		Net::CleanNet(); 
		Log::Cleanup();
		return 0;
	} 
}