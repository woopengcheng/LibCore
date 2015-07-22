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
	Msg::ObjectMsgCall * SlaveRequestSync_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SyncDataToSlave_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * SyncDataToSlave_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testTheSameNode_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , LibCore_Chunk & res = LibCore::Chunk());\
	Msg::ObjectMsgCall * testTheSameNode_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
public:\
	static CollectionObjectFuncsT s_setFuncs;\
	static void InitObjectFuncs()\
	{\
		ServerHandler::s_setFuncs.insert("HandleUserAuth");\
		ServerHandler::s_setFuncs.insert("HandleSelectDatabase");\
		ServerHandler::s_setFuncs.insert("HandleCreateDatabase");\
		ServerHandler::s_setFuncs.insert("HandleDeleteDatabase");\
		ServerHandler::s_setFuncs.insert("HandleShowDatabases");\
		ServerHandler::s_setFuncs.insert("HandleCreateUser");\
		ServerHandler::s_setFuncs.insert("HandleDeleteUser");\
		ServerHandler::s_setFuncs.insert("HandleModifyUser");\
		ServerHandler::s_setFuncs.insert("HandleHSet");\
		ServerHandler::s_setFuncs.insert("HandleHSetNX");\
		ServerHandler::s_setFuncs.insert("HandleHSetOW");\
		ServerHandler::s_setFuncs.insert("HandleHGet");\
		ServerHandler::s_setFuncs.insert("HandleHDel");\
		ServerHandler::s_setFuncs.insert("HandleHSetIncr");\
		ServerHandler::s_setFuncs.insert("HandleHSetIncrFloat");\
		ServerHandler::s_setFuncs.insert("HandleHGetKeys");\
		ServerHandler::s_setFuncs.insert("HandleHGetVals");\
		ServerHandler::s_setFuncs.insert("HandleHGetKeyVals");\
		ServerHandler::s_setFuncs.insert("HandleHScan");\
		ServerHandler::s_setFuncs.insert("HandleHCount");\
		ServerHandler::s_setFuncs.insert("HandleHDrop");\
		ServerHandler::s_setFuncs.insert("HandleHList");\
		ServerHandler::s_setFuncs.insert("HandleHMultiSet");\
		ServerHandler::s_setFuncs.insert("HandleHMultiGet");\
		ServerHandler::s_setFuncs.insert("HandleHMultiDel");\
		ServerHandler::s_setFuncs.insert("HandleZSet");\
		ServerHandler::s_setFuncs.insert("HandleZGet");\
		ServerHandler::s_setFuncs.insert("HandleZDel");\
		ServerHandler::s_setFuncs.insert("HandleZTop");\
		ServerHandler::s_setFuncs.insert("HandleZRTop");\
		ServerHandler::s_setFuncs.insert("HandleZDrop");\
		ServerHandler::s_setFuncs.insert("HandleZCount");\
		ServerHandler::s_setFuncs.insert("HandleZList");\
		ServerHandler::s_setFuncs.insert("HandleDump");\
		ServerHandler::s_setFuncs.insert("SlaveStartAuth");\
		ServerHandler::s_setFuncs.insert("SlaveRequestSync");\
		ServerHandler::s_setFuncs.insert("SyncDataToSlave");\
		ServerHandler::s_setFuncs.insert("testTheSameNode");\
	}\
	virtual BOOL IsHasFunc(const std::string & strFunc)\
	{\
		CollectionObjectFuncsT::iterator iter = ServerHandler::s_setFuncs.find(strFunc);\
		if (iter != ServerHandler::s_setFuncs.end())\
		{\
			return TRUE;\
		}\
	return FALSE;\
	}\

#define  RPC_DEFINE_SlaveHandler public:\
	Msg::ObjectMsgCall * SyncMasterHandler_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 id = 0);\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & value = std::string());\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * SlaveSelectDB_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , INT32 res = 0);\
	Msg::ObjectMsgCall * SlaveSelectDB_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & newbackdir = std::string() , INT32 res = 0);\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * MasterStartSync_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & filename = std::string() , INT32 filesize = 0 , INT32 sendtype = 0 , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * SyncDataToSlave_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcClient(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , LibCore_Chunk & res = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcTimeout(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
public:\
	static CollectionObjectFuncsT s_setFuncs;\
	static void InitObjectFuncs()\
	{\
		SlaveHandler::s_setFuncs.insert("SyncMasterHandler");\
		SlaveHandler::s_setFuncs.insert("SlaveStartAuth");\
		SlaveHandler::s_setFuncs.insert("SlaveSelectDB");\
		SlaveHandler::s_setFuncs.insert("SlaveRequestSync");\
		SlaveHandler::s_setFuncs.insert("MasterStartSync");\
		SlaveHandler::s_setFuncs.insert("SyncDataToSlave");\
		SlaveHandler::s_setFuncs.insert("testRefers");\
	}\
	virtual BOOL IsHasFunc(const std::string & strFunc)\
	{\
		CollectionObjectFuncsT::iterator iter = SlaveHandler::s_setFuncs.find(strFunc);\
		if (iter != SlaveHandler::s_setFuncs.end())\
		{\
			return TRUE;\
		}\
	return FALSE;\
	}\

#define  RPC_DEFINE_MasterHandler public:\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & name = std::string() , std_string & pwd = std::string());\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & value = std::string());\
	Msg::ObjectMsgCall * SlaveSelectDB_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string());\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & newbackdir = std::string() , INT32 res = 0);\
	Msg::ObjectMsgCall * testRefers_RpcServerProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcTimeoutProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
	Msg::ObjectMsgCall * testRefers_RpcClientProxy(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , LibCore_Chunk & res = LibCore::Chunk());\
	Msg::ObjectMsgCall * testTheSameNode_RpcServer(Msg::VecObjects & vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID) , std_string & dbname = std::string() , LibCore_Chunk & value = LibCore::Chunk());\
public:\
	static CollectionObjectFuncsT s_setFuncs;\
	static void InitObjectFuncs()\
	{\
		MasterHandler::s_setFuncs.insert("SlaveStartAuth");\
		MasterHandler::s_setFuncs.insert("SlaveSelectDB");\
		MasterHandler::s_setFuncs.insert("SlaveRequestSync");\
		MasterHandler::s_setFuncs.insert("testRefers");\
		MasterHandler::s_setFuncs.insert("testTheSameNode");\
	}\
	virtual BOOL IsHasFunc(const std::string & strFunc)\
	{\
		CollectionObjectFuncsT::iterator iter = MasterHandler::s_setFuncs.find(strFunc);\
		if (iter != MasterHandler::s_setFuncs.end())\
		{\
			return TRUE;\
		}\
	return FALSE;\
	}\







}

#endif

