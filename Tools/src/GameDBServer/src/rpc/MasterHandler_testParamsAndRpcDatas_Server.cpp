#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::testParamsAndRpcDatas_RpcServer(Net::ISession * pSession, Msg::Object objSrc , TestRpcData & rpcData/* = TestRpcData()*/ , TestRpcData2 & rpcData2/* = TestRpcData2()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , std::vector<INT32> & Vec/* = std::vector<INT32>(1)*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testParamsAndRpcDatas_RpcServer "<< std::endl;
	Return(res);
}

