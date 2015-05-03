#include "GlobalRpc.h"
#include "TestObject.h"

Msg::ObjectMsgCall * Server::TestObject::TestObject_RpcServer(UINT64 userid9/* = 0*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , UINT32 userid7/* = 0*/ , INT64 localid8/* = 0*/ , INT32 localid6/* = 0*/ , UINT16 localid4/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{


	std::cout << "TestObject_RpcServer "<< std::endl;
	RPCReturn0();
}

