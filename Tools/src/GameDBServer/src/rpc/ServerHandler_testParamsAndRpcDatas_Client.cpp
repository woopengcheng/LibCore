#include "GlobalRpc.h"
#include "ServerHandler.h"



Msg::ObjectMsgCall * Server::ServerHandler::testParamsAndRpcDatas_RpcClient(Net::ISession * pSession, Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/)
{


	std::cout << "testParamsAndRpcDatas_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::ServerHandler::testParamsAndRpcDatas_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , TestRpcData & rpcData/* = TestRpcData()*/ , TestRpcData2 & rpcData2/* = TestRpcData2()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "testParamsAndRpcDatas_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

