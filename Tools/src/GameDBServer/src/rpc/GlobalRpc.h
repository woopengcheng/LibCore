#ifndef __Server_global_rpc_h__
#define __Server_global_rpc_h__
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

