#ifndef __msg_ping_h__
#define __msg_ping_h__   
#include "MsgLib/inc/MsgCommon.h"

namespace Msg
{ 
	struct DLL_EXPORT SPing
	{ 
		UINT16  usRemoteRPCPort;
		char    szRemoteName[MAX_NAME_LENGTH];
	};
}


#endif