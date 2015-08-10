#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHSetIncrFloat_RpcClient(Net::ISession * pSession, Msg::Object objSrc , double res/* = 0*/) 
{
	if (res >= 0.0f)
	{
		gOtherStream("HSetIncrFloat data count:" << res);
	}
	else
	{
		gWarniStream("HSetIncrFloat wrong, res:" << res);
	} 


	std::cout << "HandleHSetIncrFloat_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHSetIncrFloat_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , double value/* = 0.0f*/) 
{


	std::cout << "HandleHSetIncrFloat_RpcTimeout" << std::endl;
	ReturnNULL;
}

