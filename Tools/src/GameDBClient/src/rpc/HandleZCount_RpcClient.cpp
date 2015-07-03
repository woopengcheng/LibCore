#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZCount_RpcClient(INT64 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZCount_RpcTimeout(std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleZCount_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

