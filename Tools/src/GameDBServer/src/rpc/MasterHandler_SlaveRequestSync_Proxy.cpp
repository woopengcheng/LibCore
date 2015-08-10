#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc , std_string & dbname/* = std::string()*/)
{
	std_string newbackdir = std::string();
	INT32 res = 0;
	 
	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8001" , 1 , dbname))
	{
		Return(newbackdir , res);
	}


	std::cout << "SlaveRequestSync_RpcServerProxy" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc , std_string &newbackdir/* = std::string()*/ , INT32 res/* = 0*/)
{
	if (res == 0)
	{
		StartSyncToSlave(newbackdir);
	}

	std::cout << "SlaveRequestSync_RpcClientProxy" << std::endl;
	Return(newbackdir , res);
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveRequestSync_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc , std_string & dbname/* = std::string()*/)
{


	std::cout << "SlaveRequestSync_RpcTimeoutProxy" << std::endl;
	ReturnNULL;
}

