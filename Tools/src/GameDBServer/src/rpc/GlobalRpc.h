/************************************
FileName	:	GlableRpc.h
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.1.116
Version		:	0.0.1
Date		:	2016-01-18 23:23:39
Description	:	静态函数,无对象时通过这个类处理.
************************************/
#ifndef __Server_global_rpc_h__
#define __Server_global_rpc_h__
#include "CUtil/inc/Chunk.h" 
#include "MsgLib/inc/Object.h" 
#include "MsgLib/inc/RPCMsgCall.h" 
#include "MsgLib/inc/RpcManager.h" 
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

