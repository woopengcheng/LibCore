#ifndef __Client_global_rpc_h__
#define __Client_global_rpc_h__
#include "Common/Chunk.h" 
#include "MsgLib/inc/Object.h" 
#include "MsgLib/inc/MsgCommon.h" 
#include "MsgLib/inc/RPCMsgCall.h" 
#include "MsgLib/inc/RpcServerManager.h" 
#include "MsgLib/inc/IRpcMsgCallableObject.h" 
#include "RpcDatas.h" 

namespace Msg
{
	class GlobalRpc : public Msg::IRpcMsgCallableObject
	{
	public:
		GlobalRpc(Msg::Object nID , Msg::RpcManager * pRpcManager)
			: Msg::IRpcMsgCallableObject(nID , pRpcManager)
		{
		}
	public:
		//HandleHSet generate RPC func here
		Msg::ObjectMsgCall* HandleHSet_RpcTimeout(INT32 userid = 0 , INT32 localid = 1, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSet_RpcClient(INT32 resCode = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
	};

	extern GlobalRpc * g_pGlobalRpc;
}

#endif

