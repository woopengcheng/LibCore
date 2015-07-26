#include "GlobalRpc.h"
#include "ServerHandler.h"



Msg::ObjectMsgCall * Server::ServerHandler::testRefers_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/)
{


	std::cout << "testRefers_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::ServerHandler::testRefers_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc ,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "testRefers_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

