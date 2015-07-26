#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiSet_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/) 
{ 
	if (res >= 0)
	{
		gOtherStream("MultiSet data count:" << res);
	}
	else
	{
		gWarniStream("MultiSet wrong, res:" << res);
	} 

	std::cout << "HandleHMultiSet_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiSet_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/ , LibCore_Chunk & keyvalues/* = LibCore::Chunk()*/) 
{


	std::cout << "HandleHMultiSet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

