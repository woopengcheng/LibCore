#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "TestObject_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcTimeout(INT32 userid/* = 0*/ , INT32 localid/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "TestObject_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

