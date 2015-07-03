#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleSelectDatabase_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	if (res == 0)
	{
		gOtherStream("selectdb success.");
	}
	else
	{
		gOtherStream("selectdb failure.");
	}

	std::cout << "HandleSelectDatabase_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleSelectDatabase_RpcTimeout(std_string & dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleSelectDatabase_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

