#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGet_RpcClient(std_string value/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{
	gDebugStream("HGet value:" << value);

	std::cout << "HandleHGet_RpcClient value:" << value << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHGet_RpcTimeout(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHGet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

