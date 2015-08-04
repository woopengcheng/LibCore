/************************************
FileName	:	GlableRpc.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-03 00:23:57
Description	:	静态函数,无对象时通过这个类处理.
************************************/
#ifndef __Proxy_global_rpc_h__
#define __Proxy_global_rpc_h__
#include "Common/Chunk.h" 
#include "MsgLib/inc/Object.h" 
#include "MsgLib/inc/RPCMsgCall.h" 
#include "MsgLib/inc/RpcServerManager.h" 
#include "MsgLib/inc/IRpcMsgCallableObject.h" 
#include "RpcDatas.h" 
#include "RpcDefines.h" 

namespace Msg
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

