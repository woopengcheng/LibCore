#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "TestObject_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcTimeout(UINT64 userid9/* = 0*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , UINT32 userid7/* = 0*/ , INT64 localid8/* = 0*/ , INT32 localid6/* = 0*/ , UINT16 localid4/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "TestObject_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

