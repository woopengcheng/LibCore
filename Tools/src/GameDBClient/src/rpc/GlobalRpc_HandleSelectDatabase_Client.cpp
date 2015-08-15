#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleSelectDatabase_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gOtherStream("selectdb success.");
	}
	else
	{
		gOtherStream("selectdb failure.");
	}

	std::cout << "HandleSelectDatabase_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleSelectDatabase_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & dbname/* = std::string()*/) 
{


	std::cout << "HandleSelectDatabase_RpcTimeout" << std::endl;
	ReturnNULL;
}
