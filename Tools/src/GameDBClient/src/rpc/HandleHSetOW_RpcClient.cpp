#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetOW_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{ 
	if (res == 0)
	{
		gOtherStream("HSetOW data count:" << res);
	}
	else
	{
		gWarniStream("HSetOW wrong, res:" << res);
	} 


	std::cout << "HandleHSetOW_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetOW_RpcTimeout(std_string table/* = std::string()*/ , std_string key/* = std::string()*/ , std_string value/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHSetOW_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

