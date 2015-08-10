#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHCount_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT64 res/* = 0*/) 
{
	if (res >= 0)
	{
		gOtherStream("HCount:" << res);
	}
	else
	{
		gOtherStream("HCount failure. res:" << res);
	}  


	std::cout << "HandleHCount_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHCount_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHCount_RpcTimeout" << std::endl;
	ReturnNULL;
}

