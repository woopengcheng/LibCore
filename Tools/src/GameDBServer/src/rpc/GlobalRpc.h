/************************************
FileName	:	GlableRpc.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-11 00:40:44
Description	:	静态函数,无对象时通过这个类处理.
************************************/
#ifndef __Server_global_rpc_h__
#define __Server_global_rpc_h__
#include "Common/Chunk.h" 
#include "MsgLib/inc/Object.h" 
#include "MsgLib/inc/RPCMsgCall.h" 
#include "MsgLib/inc/RpcServerManager.h" 
#include "MsgLib/inc/IRpcMsgCallableObject.h" 
#include "RpcDatas.h" 
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

