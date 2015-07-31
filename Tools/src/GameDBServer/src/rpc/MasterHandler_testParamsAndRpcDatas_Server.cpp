#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::testParamsAndRpcDatas_RpcServer(Net::ISession * pSession, Msg::Object objSrc , TestRpcData & rpcData/* = TestRpcData()*/ , TestRpcData2 & rpcData2/* = TestRpcData2()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testParamsAndRpcDatas_RpcServer "<< std::endl;
	RPCReturn1(res);
}

