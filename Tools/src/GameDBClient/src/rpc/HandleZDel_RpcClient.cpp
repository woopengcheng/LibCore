#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZDel_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , INT64 score/* = 0*/) 
{ 
	if (score > -1)
	{
		gOtherStream("ZDel data score:" << score);
	}
	else
	{
		gWarniStream("ZDel wrong, score:" << score);
	} 

	std::cout << "HandleZDel_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleZDel_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/) 
{


	std::cout << "HandleZDel_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

