#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetIncrFloat_RpcClient(double res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	if (res >= 0.0f)
	{
		gOtherStream("HSetIncrFloat data count:" << res);
	}
	else
	{
		gWarniStream("HSetIncrFloat wrong, res:" << res);
	} 


	std::cout << "HandleHSetIncrFloat_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSetIncrFloat_RpcTimeout(std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/ , double value/* = 0.0f*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHSetIncrFloat_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

