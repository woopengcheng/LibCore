#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDeleteDatabase_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/) 
{ 
	if (res == 0)
	{
		gOtherStream("DeleteDatabase success.");
	}
	else
	{
		gOtherStream("DeleteDatabase failure.");
	}

	std::cout << "HandleDeleteDatabase_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleDeleteDatabase_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/) 
{


	std::cout << "HandleDeleteDatabase_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

