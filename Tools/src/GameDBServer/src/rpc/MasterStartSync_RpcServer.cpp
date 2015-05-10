#include "GlobalRpc.h"
#include "SlaveHandler.h"

Msg::ObjectMsgCall * Server::SlaveHandler::MasterStartSync_RpcServer(LibCore_Chunk value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{


	std::cout << "MasterStartSync_RpcServer "<< std::endl;
	RPCReturn0();
}

