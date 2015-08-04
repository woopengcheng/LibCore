#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiDel_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
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
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiDel_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/) 
{


	std::cout << "HandleHMultiDel_RpcTimeout" << std::endl;
	ReturnNULL;
}

