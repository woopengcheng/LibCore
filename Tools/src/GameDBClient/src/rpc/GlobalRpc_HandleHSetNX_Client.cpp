#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHSetNX_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gOtherStream("HSetNX data count:" << res);
	}
	else
	{
		gWarniStream("HSetNX wrong, res:" << res);
	} 


	std::cout << "HandleHSetNX_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHSetNX_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/) 
{


	std::cout << "HandleHSetNX_RpcTimeout" << std::endl;
	ReturnNULL;
}

