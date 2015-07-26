#include "GlobalRpc.h"
#include "SlaveHandler.h"



Msg::ObjectMsgCall * Server::SlaveHandler::SlaveStartAuth_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & value/* = std::string()*/)
{
	if (value != "")
	{
		this->SelectDB();
	}

	std::cout << "SlaveStartAuth_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::SlaveHandler::SlaveStartAuth_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc ,std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/)
{


	std::cout << "SlaveStartAuth_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

