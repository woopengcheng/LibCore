#include "GlobalRpc.h"
#include "SlaveHandler.h"



Msg::ObjectMsgCall * Server::SlaveHandler::SlaveSelectDB_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/)
{
	if (res == 0)
	{
		this->RequestSyncData();
	}

	std::cout << "SlaveSelectDB_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::SlaveHandler::SlaveSelectDB_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc ,std_string & dbname/* = std::string()*/)
{


	std::cout << "SlaveSelectDB_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

