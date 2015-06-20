#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveSelectDB_RpcServer(std_string dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = 0;


	std::cout << "SlaveSelectDB_RpcServer "<< std::endl;
	RPCReturn1(res);
}

