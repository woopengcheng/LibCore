#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleSelectDatabase_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/) 
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

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleSelectDatabase_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/) 
{


	std::cout << "HandleSelectDatabase_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

