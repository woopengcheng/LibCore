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
		Msg::ObjectMsgCall * HandleHSet_RpcTimeout(std_string table = std::string() , std_string key = std::string() , std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSet_RpcClient(INT32 resCode = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHGet generate RPC func here
		Msg::ObjectMsgCall * HandleHGet_RpcTimeout(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHGet_RpcClient(std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZSet generate RPC func here
		Msg::ObjectMsgCall * HandleZSet_RpcTimeout(std_string table = std::string() , std_string key = std::string() , INT64 score = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZSet_RpcClient(INT32 resCode = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZGet generate RPC func here
		Msg::ObjectMsgCall * HandleZGet_RpcTimeout(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZGet_RpcClient(INT64 score = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleCreateUser generate RPC func here
		Msg::ObjectMsgCall * HandleCreateUser_RpcTimeout(std_string name = std::string() , std_string pwd = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleCreateUser_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZTop generate RPC func here
		Msg::ObjectMsgCall * HandleZTop_RpcTimeout(std_string table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZTop_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZRTop generate RPC func here
		Msg::ObjectMsgCall * HandleZRTop_RpcTimeout(std_string table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZRTop_RpcClient(LibCore_Chunk res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleDump generate RPC func here
		Msg::ObjectMsgCall * HandleDump_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleDump_RpcClient(LibCore_Chunk res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
	};

	extern GlobalRpc * g_pGlobalRpc;
}

#endif

