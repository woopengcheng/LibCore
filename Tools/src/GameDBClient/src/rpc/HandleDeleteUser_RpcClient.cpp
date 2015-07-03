#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDeleteUser_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gOtherStream("DeleteUser success.");
	}
	else
	{
		gOtherStream("DeleteUser failure. res:" << res);
	}  

	std::cout << "HandleDeleteUser_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDeleteUser_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string & name/* = std::string()*/) 
{


	std::cout << "HandleDeleteUser_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

