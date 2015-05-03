#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
#define  RPC_DEFINE_TestObject public:\
	Msg::ObjectMsgCall * TestObject_RpcServer(INT32 userid = 0 , INT32 localid = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

}

#endif

