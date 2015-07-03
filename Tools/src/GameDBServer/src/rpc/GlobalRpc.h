#ifndef __Server_global_rpc_h__
#define __Server_global_rpc_h__
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
		
//SyncDataToSlave generate RPC func here
		Msg::ObjectMsgCall * SyncDataToSlave_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());
		Msg::ObjectMsgCall * SyncDataToSlave_RpcClient(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);
		
//testRefers generate RPC func here
		Msg::ObjectMsgCall * testRefers_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());
		Msg::ObjectMsgCall * testRefers_RpcClient(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , LibCore_Chunk & res = LibCore::Chunk());
		
		
//MasterStartSync generate RPC func here
		Msg::ObjectMsgCall * MasterStartSync_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & filename = std::string() , INT32 filesize = 0 , INT32 sendtype = 0 , LibCore_Chunk & value = LibCore::Chunk());
		Msg::ObjectMsgCall * MasterStartSync_RpcClient(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);
		
		
//SlaveStartAuth generate RPC func here
		Msg::ObjectMsgCall * SlaveStartAuth_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());
		Msg::ObjectMsgCall * SlaveStartAuth_RpcClient(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & value = std::string());
		
//SlaveSelectDB generate RPC func here
		Msg::ObjectMsgCall * SlaveSelectDB_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());
		Msg::ObjectMsgCall * SlaveSelectDB_RpcClient(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);
		
//SlaveRequestSync generate RPC func here
		Msg::ObjectMsgCall * SlaveRequestSync_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbbackdir = std::string() , std_string & dbname = std::string());
		Msg::ObjectMsgCall * SlaveRequestSync_RpcClient(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & newbackdir = std::string() , INT32 res = 0);
		
	};

	extern GlobalRpc * g_pGlobalRpc;
}

#endif

