#ifndef __Proxy_global_rpc_h__
#define __Proxy_global_rpc_h__
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
		//TestObject generate RPC func here
		Msg::ObjectMsgCall * TestObject_RpcServerProxy(UINT32 userid7 = 0 , UINT64 userid9 = 0 , UINT16 localid4 = 0 , SINT8 userid1 = 0 , INT16 userid3 = 0 , INT64 localid8 = 0 , INT32 localid6 = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * TestObject_RpcTimeoutProxy(UINT32 userid7 = 0 , UINT64 userid9 = 0 , UINT16 localid4 = 0 , SINT8 userid1 = 0 , INT16 userid3 = 0 , INT64 localid8 = 0 , INT32 localid6 = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * TestObject_RpcClientProxy(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

		//TestObject1 generate RPC func here
		Msg::ObjectMsgCall * TestObject1_RpcServerProxy(std_string localid12 = std::string() , UINT8 localid2 = 0 , UINT16 localid4 = 0 , double localid10 = 1.0f , LibCore_Chunk localid13 = LibCore::Chunk() , SINT8 userid1 = 0 , INT16 userid3 = 0 , float localid11 = 1.0f, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * TestObject1_RpcTimeoutProxy(std_string localid12 = std::string() , UINT8 localid2 = 0 , UINT16 localid4 = 0 , double localid10 = 1.0f , LibCore_Chunk localid13 = LibCore::Chunk() , SINT8 userid1 = 0 , INT16 userid3 = 0 , float localid11 = 1.0f, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * TestObject1_RpcClientProxy(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

		
	};

	extern GlobalRpc * g_pGlobalRpc;
}

#endif

