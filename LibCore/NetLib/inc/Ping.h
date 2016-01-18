#ifndef __net_ping_h__
#define __net_ping_h__   
#include "NetLib/inc/NetCommon.h"

namespace Net
{ 
#define DEFAULT_MSG_PING_ID					1
#define DEFAULT_PING_TIME_OUT_MICROSECOND	5

	enum EPingState
	{
		PING_STATE_PINGING,
		PING_STATE_LOST,
		PING_STATE_PINGED,
	};

	struct SPeerInfo
	{
		UINT16		usPeerPort;
		char		szAddress[MAX_ADDRESS_LENGTH];
		char		szNodeName[MAX_NAME_LENGTH];
		INT32		nSessionID;
		INT32		nPeerSessionID;
		EPingState	nState;

		SPeerInfo()
		{
			memset(this, 0, sizeof(SPeerInfo));
		}
	};

	struct SPing
	{ 
		UINT16  usPeerPort;
		char    szAddress[MAX_ADDRESS_LENGTH];
		char	szNodeName[MAX_NAME_LENGTH];

		SPing()
		{
			memset(this , 0 , sizeof(SPing));
		}
	};
}


#endif