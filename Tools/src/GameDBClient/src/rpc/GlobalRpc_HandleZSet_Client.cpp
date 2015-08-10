#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleZSet_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gOtherStream("ZSet data res:" << res);
	}
	else
	{
		gWarniStream("ZSet wrong, res:" << res);
	} 


	std::cout << "HandleZSet_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleZSet_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/, INT64 score/* = 0*/ ) 
{


	std::cout << "HandleZSet_RpcTimeout" << std::endl;
	ReturnNULL;
}

