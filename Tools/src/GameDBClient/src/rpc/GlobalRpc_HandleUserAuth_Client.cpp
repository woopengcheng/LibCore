#include "GlobalRpc.h"
#include "RPCCallFuncs.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleUserAuth_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/) 
{
	if (res == 0)
	{
		gDebugStream("HandleUserAuth_RpcClient success" );
	}
	else
	{ 
		gDebugStream("HandleUserAuth_RpcClient failure" );
	}

	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleUserAuth_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & name/* = std::string()*/ , std_string & pwd/* = std::string()*/) 
{


	std::cout << "HandleUserAuth_RpcTimeout" << std::endl;
	ReturnNULL;
}

