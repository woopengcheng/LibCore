#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcServerProxy(std_string &dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
	std_string newbackdir = std::string();
	INT32 res = 0;


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8001" , dbbackdir , dbname))
	{
		RPCReturn2(newbackdir , res);
	}


	std::cout << "SlaveRequestSync_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcClientProxy(std_string &newbackdir/* = std::string()*/ , INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
	if (res == 0)
	{
		StartSyncToSlave(newbackdir);
	}

	std::cout << "SlaveRequestSync_RpcClientProxy" << std::endl;
	RPCReturn2(newbackdir , res);
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcTimeoutProxy(std_string &dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	std::cout << "SlaveRequestSync_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

