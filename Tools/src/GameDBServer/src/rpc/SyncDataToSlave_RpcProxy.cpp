#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcServerProxy(std_string dbname/* = std::string()*/ , LibCore_Chunk value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
	INT32 res = 0;


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:9002" , dbname , value))
	{
		RPCReturn1(res);
	}


	std::cout << "SyncDataToSlave_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcClientProxy(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
 

	std::cout << "SyncDataToSlave_RpcClientProxy" << std::endl;
	RPCReturn1(res);
}

Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcTimeoutProxy(std_string dbname/* = std::string()*/ , LibCore_Chunk value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	std::cout << "SyncDataToSlave_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

