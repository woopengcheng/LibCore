/************************************
FileName	:	GlableRpc.h
Author		:	generate by tools
HostName	:	devuser-PC
IP			:	10.236.41.54
Version		:	0.0.1
Description	:	静态函数,无对象时通过这个类处理.
************************************/
#ifndef __Client_global_rpc_h__
#define __Client_global_rpc_h__
#include "MsgLib/inc/IRpcMsgCallableObject.h" 
#include "RpcDefines.h" 

namespace Client
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

