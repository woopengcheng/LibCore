#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetIncr_RpcClient(INT64 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{ 
	if (res >= 0)
	{
		gOtherStream("HSetIncr data count:" << res);
	}
	else
	{
		gWarniStream("HSetIncr wrong, res:" << res);
	} 

	std::cout << "HandleHSetIncr_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetIncr_RpcTimeout(std_string table/* = std::string()*/ , std_string key/* = std::string()*/ , INT64 value/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHSetIncr_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

