#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{


	std::cout << "SlaveRequestSync_RpcServer "<< std::endl;
	RPCReturn0();
}

