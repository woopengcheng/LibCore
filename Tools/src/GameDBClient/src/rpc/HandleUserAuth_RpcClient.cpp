#include "GlobalRpc.h"
#include "RPCCallFuncs.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleUserAuth_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	if (res == 0)
	{
		gDebugStream("HandleUserAuth_RpcClient success" );
	}
	else
	{ 
		gDebugStream("HandleUserAuth_RpcClient failure" );
	}

	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleUserAuth_RpcTimeout(std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleUserAuth_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

