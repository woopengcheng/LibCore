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
		
//HandleUserAuth generate RPC func here
		Msg::ObjectMsgCall * HandleUserAuth_RpcTimeout(std_string name = std::string() , std_string pwd = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleUserAuth_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleSelectDatabase generate RPC func here
		Msg::ObjectMsgCall * HandleSelectDatabase_RpcTimeout(std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleSelectDatabase_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleCreateDatabase generate RPC func here
		Msg::ObjectMsgCall * HandleCreateDatabase_RpcTimeout(std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleCreateDatabase_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleDeleteDatabase generate RPC func here
		Msg::ObjectMsgCall * HandleDeleteDatabase_RpcTimeout(std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleDeleteDatabase_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleShowDatabases generate RPC func here
		Msg::ObjectMsgCall * HandleShowDatabases_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleShowDatabases_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleCreateUser generate RPC func here
		Msg::ObjectMsgCall * HandleCreateUser_RpcTimeout(std_string name = std::string() , std_string pwd = std::string() , SINT8 issys = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleCreateUser_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleDeleteUser generate RPC func here
		Msg::ObjectMsgCall * HandleDeleteUser_RpcTimeout(std_string name = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleDeleteUser_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleModifyUser generate RPC func here
		Msg::ObjectMsgCall * HandleModifyUser_RpcTimeout(std_string name = std::string() , std_string pwd = std::string() , SINT8 issys = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleModifyUser_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHSet generate RPC func here
		Msg::ObjectMsgCall * HandleHSet_RpcTimeout(std_string table = std::string() , std_string key = std::string() , std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSet_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHSetNX generate RPC func here
		Msg::ObjectMsgCall * HandleHSetNX_RpcTimeout(std_string table = std::string() , std_string key = std::string() , std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSetNX_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHSetOW generate RPC func here
		Msg::ObjectMsgCall * HandleHSetOW_RpcTimeout(std_string table = std::string() , std_string key = std::string() , std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSetOW_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHGet generate RPC func here
		Msg::ObjectMsgCall * HandleHGet_RpcTimeout(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHGet_RpcClient(std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHDel generate RPC func here
		Msg::ObjectMsgCall * HandleHDel_RpcTimeout(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHDel_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHSetIncr generate RPC func here
		Msg::ObjectMsgCall * HandleHSetIncr_RpcTimeout(std_string table = std::string() , std_string key = std::string() , INT64 value = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSetIncr_RpcClient(INT64 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHSetIncrFloat generate RPC func here
		Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcTimeout(std_string table = std::string() , std_string key = std::string() , double value = 0.0f, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcClient(double res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHGetKeys generate RPC func here
		Msg::ObjectMsgCall * HandleHGetKeys_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHGetKeys_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHGetVals generate RPC func here
		Msg::ObjectMsgCall * HandleHGetVals_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHGetVals_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHGetKeyVals generate RPC func here
		Msg::ObjectMsgCall * HandleHGetKeyVals_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHGetKeyVals_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHScan generate RPC func here
		Msg::ObjectMsgCall * HandleHScan_RpcTimeout(std_string table = std::string() , std_string start = std::string() , std_string regexp = std::string() , INT64 limit = 10, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHScan_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHCount generate RPC func here
		Msg::ObjectMsgCall * HandleHCount_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHCount_RpcClient(INT64 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHDrop generate RPC func here
		Msg::ObjectMsgCall * HandleHDrop_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHDrop_RpcClient(INT64 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHList generate RPC func here
		Msg::ObjectMsgCall * HandleHList_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHList_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHMultiSet generate RPC func here
		Msg::ObjectMsgCall * HandleHMultiSet_RpcTimeout(std_string table = std::string() , LibCore_Chunk keyvalues = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHMultiSet_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHMultiGet generate RPC func here
		Msg::ObjectMsgCall * HandleHMultiGet_RpcTimeout(std_string table = std::string() , LibCore_Chunk keys = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHMultiGet_RpcClient(LibCore_Chunk res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleHMultiDel generate RPC func here
		Msg::ObjectMsgCall * HandleHMultiDel_RpcTimeout(std_string table = std::string() , LibCore_Chunk keys = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleHMultiDel_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZSet generate RPC func here
		Msg::ObjectMsgCall * HandleZSet_RpcTimeout(std_string table = std::string() , std_string key = std::string() , INT64 score = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZSet_RpcClient(INT32 resCode = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZGet generate RPC func here
		Msg::ObjectMsgCall * HandleZGet_RpcTimeout(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZGet_RpcClient(INT64 score = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZDel generate RPC func here
		Msg::ObjectMsgCall * HandleZDel_RpcTimeout(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZDel_RpcClient(INT64 score = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZTop generate RPC func here
		Msg::ObjectMsgCall * HandleZTop_RpcTimeout(std_string table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZTop_RpcClient(LibCore_Chunk res = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZRTop generate RPC func here
		Msg::ObjectMsgCall * HandleZRTop_RpcTimeout(std_string table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZRTop_RpcClient(LibCore_Chunk res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZDrop generate RPC func here
		Msg::ObjectMsgCall * HandleZDrop_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZDrop_RpcClient(INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZCount generate RPC func here
		Msg::ObjectMsgCall * HandleZCount_RpcTimeout(std_string table = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZCount_RpcClient(INT64 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleZList generate RPC func here
		Msg::ObjectMsgCall * HandleZList_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleZList_RpcClient(LibCore_Chunk res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
//HandleDump generate RPC func here
		Msg::ObjectMsgCall * HandleDump_RpcTimeout(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall * HandleDump_RpcClient(LibCore_Chunk res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		
	};

	extern GlobalRpc * g_pGlobalRpc;
}

#endif

