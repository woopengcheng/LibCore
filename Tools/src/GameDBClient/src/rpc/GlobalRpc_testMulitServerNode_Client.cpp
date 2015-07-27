#include "GlobalRpc.h"


Msg::ObjectMsgCall * Msg::GlobalRpc::testMulitServerNode_RpcClient(Net::ISession * pSession , Msg::Object objSrc , LibCore_Chunk & res/* = LibCore::Chunk()*/)
{


	std::cout << "testMulitServerNode_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::testMulitServerNode_RpcTimeout(Net::ISession * pSession , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "testMulitServerNode_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

