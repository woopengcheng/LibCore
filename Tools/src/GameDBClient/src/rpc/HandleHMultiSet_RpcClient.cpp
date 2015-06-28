#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiSet_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiSet_RpcTimeout(std_string table/* = std::string()*/ , LibCore_Chunk keyvalues/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHMultiSet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

