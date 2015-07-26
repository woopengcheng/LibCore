#include "GlobalRpc.h"
#include "ServerHandler.h"



Msg::ObjectMsgCall * Server::ServerHandler::SyncDataToSlave_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/)
{


	std::cout << "SyncDataToSlave_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::ServerHandler::SyncDataToSlave_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc ,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "SyncDataToSlave_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

