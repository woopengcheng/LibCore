#include "GlobalRpc.h"
#include "SlaveHandler.h"



Msg::ObjectMsgCall * Server::SlaveHandler::SlaveRequestSync_RpcClient(Net::ISession * pSession, Msg::Object objSrc , std_string & newbackdir/* = std::string()*/ , INT32 res/* = 0*/)
{


	std::cout << "SlaveRequestSync_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::SlaveHandler::SlaveRequestSync_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & dbname/* = std::string()*/)
{


	std::cout << "SlaveRequestSync_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

