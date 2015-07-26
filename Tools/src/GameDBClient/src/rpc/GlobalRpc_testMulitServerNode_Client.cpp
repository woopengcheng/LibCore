#include "GlobalRpc.h"


Msg::ObjectMsgCall * Msg::GlobalRpc::testMulitServerNode_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/)
{


	std::cout << "testMulitServerNode_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::testMulitServerNode_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "testMulitServerNode_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

