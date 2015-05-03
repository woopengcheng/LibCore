#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcServerProxy(INT32 userid/* = 0*/ , INT32 localid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	ProxySendMsg("tcp://127.0.0.1:8002" , userid , localid);
	std::cout << "TestObject_RpcServerProxy" << std::endl;
	//RPCReturn0();
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcClientProxy(std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
 

	std::cout << "TestObject_RpcClientProxy" << std::endl;
	RPCReturn0();
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcTimeout(INT32 userid/* = 0*/ , INT32 localid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	std::cout << "TestObject_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

