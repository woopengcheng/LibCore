#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{

#define  RPC_DEFINE_ServerHandler public:\
	Msg::ObjectMsgCall * HandleUserAuth_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * HandleSelectDatabase_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleCreateDatabase_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleDeleteDatabase_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * HandleShowDatabases_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleCreateUser_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0);\
	Msg::ObjectMsgCall * HandleDeleteUser_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string());\
	Msg::ObjectMsgCall * HandleModifyUser_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string() , SINT8 issys = 0);\
	Msg::ObjectMsgCall * HandleHSet_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHSetNX_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHSetOW_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , std_string & value = std::string());\
	Msg::ObjectMsgCall * HandleHGet_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleHDel_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleHSetIncr_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , INT64 value = 0);\
	Msg::ObjectMsgCall * HandleHSetIncrFloat_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , double value = 0.0f);\
	Msg::ObjectMsgCall * HandleHGetKeys_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHGetVals_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHGetKeyVals_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHScan_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & start = std::string() , std_string & regexp = std::string() , INT64 limit = 10);\
	Msg::ObjectMsgCall * HandleHCount_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHDrop_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleHList_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleHMultiSet_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , LibCore_Chunk & keyvalues = LibCore::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiGet_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , LibCore_Chunk & keys = LibCore::Chunk());\
	Msg::ObjectMsgCall * HandleHMultiDel_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , LibCore_Chunk & keys = LibCore::Chunk());\
	Msg::ObjectMsgCall * HandleZSet_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string() , INT64 score = 0);\
	Msg::ObjectMsgCall * HandleZGet_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleZDel_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , std_string & key = std::string());\
	Msg::ObjectMsgCall * HandleZTop_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0);\
	Msg::ObjectMsgCall * HandleZRTop_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0);\
	Msg::ObjectMsgCall * HandleZDrop_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleZCount_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & table = std::string());\
	Msg::ObjectMsgCall * HandleZList_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleDump_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\

#define  RPC_DEFINE_SlaveHandler public:\
	Msg::ObjectMsgCall * SyncMasterHandler_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 id = 0);\
	Msg::ObjectMsgCall * MasterStartSync_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & filename = std::string() , INT32 filesize = 0 , INT32 sendtype = 0 , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * SyncDataToSlave_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , LibCore_Chunk & res = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\



#define  RPC_DEFINE_MasterHandler public:\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & value = std::string());\
	Msg::ObjectMsgCall * SlaveSelectDB_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbbackdir = std::string() , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbbackdir = std::string() , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & newbackdir = std::string() , INT32 res = 0);\
	Msg::ObjectMsgCall * testRefers_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , LibCore_Chunk & res = LibCore::Chunk());\





}

#endif

