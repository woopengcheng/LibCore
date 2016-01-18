#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleZDrop_RpcClient(INT32 nSessionID , Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res >= 0)
	{
		gOtherStream("HandleZDrop data res:" << res);
	}
	else
	{
		gWarniStream("HandleZDrop wrong, res:" << res);
	} 


	std::cout << "HandleZDrop_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleZDrop_RpcTimeout(INT32 nSessionID , Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleZDrop_RpcTimeout" << std::endl;
	ReturnNULL;
}

