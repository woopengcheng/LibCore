#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
#define  RPC_DEFINE_TestObject public:\
	Msg::ObjectMsgCall * TestObject_RpcServer(UINT32 userid7 = 0 , UINT64 userid9 = 0 , UINT16 localid4 = 0 , SINT8 userid1 = 0 , INT16 userid3 = 0 , INT64 localid8 = 0 , INT32 localid6 = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * TestObject1_RpcServer(std_string localid12 = std::string() , UINT8 localid2 = 0 , UINT16 localid4 = 0 , double localid10 = 1.0f , LibCore_Chunk localid13 = LibCore::Chunk() , SINT8 userid1 = 0 , INT16 userid3 = 0 , float localid11 = 1.0f, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\



}

#endif

