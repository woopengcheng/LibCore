#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
#define  RPC_DEFINE_TestObject public:\
	Msg::ObjectMsgCall * TestObject1_RpcServer(SINT8 userid1 = 0 , UINT8 localid2 = 0 , INT16 userid3 = 0 , UINT16 localid4 = 0 , double localid10 = 1.0f , float localid11 = 1.0f , std_string localid12 = std::string() , LibCore_Chunk localid13 = LibCore::Chunk(), std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));\
	Msg::ObjectMsgCall * TestObject_RpcServer(UINT64 userid9 = 0 , SINT8 userid1 = 0 , INT16 userid3 = 0 , UINT32 userid7 = 0 , INT64 localid8 = 0 , INT32 localid6 = 0 , UINT16 localid4 = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

}

#endif

