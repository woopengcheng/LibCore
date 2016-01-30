/************************************
FileName	:	GlableRpc.h
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.1.116
Version		:	0.0.1
Description	:	静态函数,无对象时通过这个类处理.
************************************/
#ifndef __Server_global_rpc_h__
#define __Server_global_rpc_h__
#include "MsgLib/inc/IRpcMsgCallableObject.h" 
#include "RpcDefines.h" 

namespace Server
{
	class GlobalRpc : public Msg::IRpcMsgCallableObject
	{
		RPC_DEFINE_GlobalRpc;
	public:
		GlobalRpc(Msg::Object nID , Msg::RpcManager * pRpcManager)
			: Msg::IRpcMsgCallableObject(nID , pRpcManager)
		{
			GlobalRpc::InitObjectFuncs();
		}
	public:
	};

}

#endif

