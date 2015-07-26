#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGet_RpcClient(VecObjects & vecTargets , Msg::Object objSrc , std_string & value/* = std::string()*/) 
{
	gDebugStream("HGet value:" << value);

	std::cout << "HandleHGet_RpcClient value:" << value << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGet_RpcTimeout(VecObjects & vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/) 
{


	std::cout << "HandleHGet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

