#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHDrop_RpcClient(INT64 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHDrop_RpcTimeout(std_string table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHDrop_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

