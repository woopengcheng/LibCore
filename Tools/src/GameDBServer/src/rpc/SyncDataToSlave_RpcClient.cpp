#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SyncDataToSlave_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SyncDataToSlave_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SyncDataToSlave_RpcTimeout(std_string &dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SyncDataToSlave_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

