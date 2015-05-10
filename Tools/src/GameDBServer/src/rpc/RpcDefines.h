#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
#define  RPC_DEFINE_MasterHandler public:\

	Msg::ObjectMsgCall * SlaveRequestSync_RpcServer(std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
#define  RPC_DEFINE_ServerHandler public:\

	Msg::ObjectMsgCall * HandleHSet_RpcServer(std_string table = std::string() , std_string value = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * HandleHGet_RpcServer(std_string table = std::string() , std_string key = std::string(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
#define  RPC_DEFINE_SlaveHandler public:\

	Msg::ObjectMsgCall * MasterStartSync_RpcServer(LibCore_Chunk value = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\

}

#endif

