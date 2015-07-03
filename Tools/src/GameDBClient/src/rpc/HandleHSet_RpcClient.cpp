#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSet_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{ 
	if (res == 0)
	{
		gOtherStream("HSet data count:" << res);
	}
	else
	{
		gWarniStream("HSet wrong, res:" << res);
	} 

	std::cout << "HandleHSet_RpcClient resCode:" << res << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSet_RpcTimeout(std_string & table/* = std::string()*/ , std_string & value/* = std::string()*/ , std_string & key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHSet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

