#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiDel_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	if (res >= 0)
	{
		gOtherStream("HandleHMultiDel data count:" << res);
	}
	else
	{
		gWarniStream("HandleHMultiDel wrong, res:" << res);
	} 

	std::cout << "HandleHMultiDel_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiDel_RpcTimeout(std_string table/* = std::string()*/ , LibCore_Chunk keys/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHMultiDel_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

