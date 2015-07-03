#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZDrop_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZDrop_RpcTimeout(std_string & table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleZDrop_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

