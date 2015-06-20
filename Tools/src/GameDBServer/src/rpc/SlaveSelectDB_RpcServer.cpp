#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::SlaveSelectDB_RpcServer(std_string dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{


	std::cout << "SlaveSelectDB_RpcServer "<< std::endl;
	RPCReturn0();
}

