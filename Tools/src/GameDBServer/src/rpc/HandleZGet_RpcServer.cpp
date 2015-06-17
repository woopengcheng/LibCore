#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZGet_RpcServer(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	std_string value = std::string();


	std::cout << "HandleZGet_RpcServer "<< std::endl;
	RPCReturn1(value);
}

