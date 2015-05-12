#ifndef __msg_Client_msg_name_define_h__
#define __msg_Client_msg_name_define_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
	//5 SlaveRequestSync declare here
	RPC_DEFINE(SlaveRequestSync);

	//5 MasterStartSync declare here
	RPC_DEFINE(MasterStartSync);

	//5 HandleHSet declare here
	RPC_DEFINE(HandleHSet);

	//5 HandleHGet declare here
	RPC_DEFINE(HandleHGet);

}

#endif

