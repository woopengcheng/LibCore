#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHCount_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , INT64 res/* = 0*/) 
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

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHCount_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/) 
{


	std::cout << "HandleHCount_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

