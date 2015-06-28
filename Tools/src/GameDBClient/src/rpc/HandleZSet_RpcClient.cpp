#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZSet_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	if (res == 0)
	{
		gOtherStream("ZSet data res:" << res);
	}
	else
	{
		gWarniStream("ZSet wrong, res:" << res);
	} 


	std::cout << "HandleZSet_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZSet_RpcTimeout(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, INT64 score/* = 0*/ , std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleZSet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

