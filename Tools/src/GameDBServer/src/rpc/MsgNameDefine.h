#ifndef __msg_Server_msg_name_define_h__
#define __msg_Server_msg_name_define_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
	//5 HandleZRTop declare here
	RPC_DEFINE(HandleZRTop);

	//5 MasterStartSync declare here
	RPC_DEFINE(MasterStartSync);

	//5 HandleHSet declare here
	RPC_DEFINE(HandleHSet);

	//5 SlaveRequestSync declare here
	RPC_DEFINE(SlaveRequestSync);

	//5 HandleHGet declare here
	RPC_DEFINE(HandleHGet);

	//5 HandleZGet declare here
	RPC_DEFINE(HandleZGet);

	//5 HandleZTop declare here
	RPC_DEFINE(HandleZTop);

	//5 HandleDump declare here
	RPC_DEFINE(HandleDump);

	//5 HandleZSet declare here
	RPC_DEFINE(HandleZSet);

}

#endif

