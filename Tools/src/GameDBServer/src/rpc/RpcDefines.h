#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
#define  RPC_DEFINE_ServerHandler public:\
	Msg::ObjectMsgCall * HandleHSet_RpcServer(std_string table = std::string() , std_string key = std::string() , std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleHGet_RpcServer(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleZSet_RpcServer(std_string table = std::string() , std_string key = std::string() , INT64 score = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleZGet_RpcServer(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleCreateUser_RpcServer(std_string name = std::string() , std_string pwd = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleZTop_RpcServer(std_string table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleZRTop_RpcServer(std_string table = std::string() , INT64 start = 0 , INT64 end = 0 , INT64 limit = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleDump_RpcServer(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcServer(std_string name = std::string() , std_string pwd = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcServer(std_string dbbackdir = std::string() , std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\


#define  RPC_DEFINE_MasterHandler public:\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcServerProxy(std_string name = std::string() , std_string pwd = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcTimeoutProxy(std_string name = std::string() , std_string pwd = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveStartAuth_RpcClientProxy(std_string value = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveSelectDB_RpcServer(std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcServerProxy(std_string dbbackdir = std::string() , std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcTimeoutProxy(std_string dbbackdir = std::string() , std_string dbname = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * SlaveRequestSync_RpcClientProxy(std_string newbackdir = std::string() , INT32 res = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\


#define  RPC_DEFINE_SlaveHandler public:\
	Msg::ObjectMsgCall * MasterStartSync_RpcServer(std_string filename = std::string() , INT32 filesize = 0 , INT32 sendtype = 0 , LibCore_Chunk value = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\



}

#endif

