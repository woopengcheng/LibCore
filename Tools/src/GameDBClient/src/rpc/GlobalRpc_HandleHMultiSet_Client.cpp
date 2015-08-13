#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHMultiSet_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
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
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHMultiSet_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , CUtilChunk & keyvalues/* = CUtil::Chunk()*/) 
{


	std::cout << "HandleHMultiSet_RpcTimeout" << std::endl;
	ReturnNULL;
}

