#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHCount_RpcClient(INT64 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHCount_RpcTimeout(std_string table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHCount_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

