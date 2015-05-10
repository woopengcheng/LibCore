#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::MasterStartSync_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "MasterStartSync_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::MasterStartSync_RpcTimeout(LibCore_Chunk value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "MasterStartSync_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

