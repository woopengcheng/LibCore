#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::testParamsAndRpcDatas_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/)
{


	std::cout << "testParamsAndRpcDatas_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::testParamsAndRpcDatas_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , TestRpcData & rpcData/* = TestRpcData()*/ , TestRpcData2 & rpcData2/* = TestRpcData2()*/ , std::vector<INT32> & Vec/* = std::vector<INT32>(1)*/)
{


	std::cout << "testParamsAndRpcDatas_RpcTimeout" << std::endl;
	ReturnNULL;
}

