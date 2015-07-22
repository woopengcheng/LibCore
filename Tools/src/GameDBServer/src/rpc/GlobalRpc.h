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
		
		
//SyncMasterHandler generate RPC func here
		Msg::ObjectMsgCall * SyncMasterHandler_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 id = 0);
		Msg::ObjectMsgCall * SyncMasterHandler_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);
		
//MasterStartSync generate RPC func here
		Msg::ObjectMsgCall * MasterStartSync_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & filename = std::string() , INT32 filesize = 0 , INT32 sendtype = 0 , LibCore_Chunk & value = LibCore::Chunk());
		Msg::ObjectMsgCall * MasterStartSync_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);
		
//SyncDataToSlave generate RPC func here
		Msg::ObjectMsgCall * SyncDataToSlave_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());
		Msg::ObjectMsgCall * SyncDataToSlave_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());
		Msg::ObjectMsgCall * SyncDataToSlave_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);
		
		
public:
	static CollectionObjectFuncsT s_setFuncs;
	static void InitObjectFuncs()
	{
		GlobalRpc::s_setFuncs.insert("SyncMasterHandler");
		GlobalRpc::s_setFuncs.insert("MasterStartSync");
		GlobalRpc::s_setFuncs.insert("SyncDataToSlave");
	}
	virtual BOOL IsHasFunc(const std::string & strFunc)
	{
		CollectionObjectFuncsT::iterator iter = GlobalRpc::s_setFuncs.find(strFunc);
		if (iter != GlobalRpc::s_setFuncs.end())
		{
			return TRUE;
		}
	return FALSE;
	}
	};

}

#endif

