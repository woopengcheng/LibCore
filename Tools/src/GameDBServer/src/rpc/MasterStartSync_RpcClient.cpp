#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::MasterStartSync_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "MasterStartSync_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::MasterStartSync_RpcTimeout(std_string &filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "MasterStartSync_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

