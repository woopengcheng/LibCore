#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleModifyUser_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{ 
	if (res == 0)
	{
		gOtherStream("HandleModifyUser data count:" << res);
	}
	else
	{
		gWarniStream("HandleModifyUser wrong, res:" << res);
	} 

	std::cout << "HandleModifyUser_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleModifyUser_RpcTimeout(std_string name/* = std::string()*/ , std_string pwd/* = std::string()*/ , SINT8 issys/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleModifyUser_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

