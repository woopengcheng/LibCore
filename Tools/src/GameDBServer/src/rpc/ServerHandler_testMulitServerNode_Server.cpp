#include "GlobalRpc.h"
#include "ServerHandler.h"



Msg::ObjectMsgCall * Server::ServerHandler::testMulitServerNode_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testMulitServerNode_RpcServer "<< std::endl;
	RPCReturn1(res);
}

