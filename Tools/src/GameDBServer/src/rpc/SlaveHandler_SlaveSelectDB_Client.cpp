#include "SlaveHandler.h"



Msg::ObjectMsgCall * Server::SlaveHandler::SlaveSelectDB_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/)
{
	if (res == 0)
	{
		this->RequestSyncData();
	}

	std::cout << "SlaveSelectDB_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::SlaveHandler::SlaveSelectDB_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc ,std_string & dbname/* = std::string()*/)
{


	std::cout << "SlaveSelectDB_RpcTimeout" << std::endl;
	ReturnNULL;
}

