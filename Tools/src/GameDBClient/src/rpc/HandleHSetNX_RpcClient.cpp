#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetNX_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gOtherStream("HSetNX data count:" << res);
	}
	else
	{
		gWarniStream("HSetNX wrong, res:" << res);
	} 


	std::cout << "HandleHSetNX_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetNX_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/) 
{


	std::cout << "HandleHSetNX_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

