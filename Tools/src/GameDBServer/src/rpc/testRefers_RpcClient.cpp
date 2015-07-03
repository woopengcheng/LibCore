#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::testRefers_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/ ) 
{


	std::cout << "testRefers_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::testRefers_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ ) 
{


	std::cout << "testRefers_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

