#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::SlaveStartAuth_RpcServer(std_string pwd/* = std::string()*/ , std_string name/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = 0;


	std::cout << "SlaveStartAuth_RpcServer "<< std::endl;
	RPCReturn1(res);
}

