#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHDrop_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT64 res/* = 0*/) 
{
	if (res >= 0)
	{
		gOtherStream("HandleHDrop success: drop count:" << res);
	}
	else
	{
		gOtherStream("HandleHDrop failure. res:" << res);
	}   

	std::cout << "HandleHDrop_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHDrop_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHDrop_RpcTimeout" << std::endl;
	ReturnNULL;
}
