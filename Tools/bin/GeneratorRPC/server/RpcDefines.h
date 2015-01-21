#ifndef __Server_rpc_defines_h__
#define __Server_rpc_defines_h__
#include "MsgCommon.h" 

//5 TestObject declare here
#define  RPC_DEFINE_TestObjectpublic:\
	Msg::ObjectMsgCall<Object> * TestObject_RpcServer(INT32 localid = 0 , INT32 userid = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

//5 TestObject1 declare here
#define  RPC_DEFINE_TestObject1public:\
	Msg::ObjectMsgCall<Object> * TestObject1_RpcServer(INT32 localid = 0 , INT32 userid = 0, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));


#endif

