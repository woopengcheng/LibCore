#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiGet_RpcClient(LibCore_Chunk res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHMultiGet_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHMultiGet_RpcTimeout(std_string table/* = std::string()*/ , LibCore_Chunk keys/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHMultiGet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

