#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHDel_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{ 
	if (res == 0)
	{
		gOtherStream("HandleHDel success");
	}
	else
	{
		gOtherStream("HandleHDel failure. res:" << res);
	}  


	std::cout << "HandleHDel_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHDel_RpcTimeout(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHDel_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

