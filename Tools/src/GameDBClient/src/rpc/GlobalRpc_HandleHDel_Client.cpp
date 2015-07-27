#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHDel_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{ 
	if (res == 0)
	{
		gOtherStream("HandleHDel success");
	}
	else
	{
		gOtherStream("HandleHDel failure. res:" << res);
	}  


	std::cout << "HandleHDel_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHDel_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/) 
{


	std::cout << "HandleHDel_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

