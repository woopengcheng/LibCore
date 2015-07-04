#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleCreateUser_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/) 
{

	if (res == 0)
	{
		gOtherStream("CreateUser success.");
	}
	else
	{
		gOtherStream("CreateUser failure.");
	}

	std::cout << "HandleCreateUser_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleCreateUser_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/,SINT8 issys/* = 0*/) 
{


	std::cout << "HandleCreateUser_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

