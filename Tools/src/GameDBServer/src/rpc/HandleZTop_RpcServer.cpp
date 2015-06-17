#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZTop_RpcServer(std_string table/* = std::string()*/ , std_string count/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res = 0;


	std::cout << "HandleZTop_RpcServer "<< std::endl;
	RPCReturn1(res);
}

