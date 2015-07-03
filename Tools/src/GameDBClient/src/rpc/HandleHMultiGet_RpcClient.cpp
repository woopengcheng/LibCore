#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiGet_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = 0*/) 
{


	std::cout << "HandleHMultiGet_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiGet_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string & table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/) 
{


	std::cout << "HandleHMultiGet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

