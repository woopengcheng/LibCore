#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::testRefers_RpcClient(LibCore_Chunk & res/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "testRefers_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::testRefers_RpcTimeout(std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "testRefers_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

