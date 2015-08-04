#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleModifyUser_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{ 
	if (res == 0)
	{
		gOtherStream("HandleModifyUser data count:" << res);
	}
	else
	{
		gWarniStream("HandleModifyUser wrong, res:" << res);
	} 

	std::cout << "HandleModifyUser_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleModifyUser_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/ , SINT8 issys/* = 0*/) 
{


	std::cout << "HandleModifyUser_RpcTimeout" << std::endl;
	ReturnNULL;
}

