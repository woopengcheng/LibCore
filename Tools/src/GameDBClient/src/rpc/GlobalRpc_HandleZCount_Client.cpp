#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZCount_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT64 res/* = 0*/) 
{

	if (res >= 0)
	{
		gOtherStream("ZCount:" << res);
	}
	else
	{
		gOtherStream("ZCount failure. res:" << res);
	}  


	std::cout << "HandleZCount_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZCount_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleZCount_RpcTimeout" << std::endl;
	ReturnNULL;
}

