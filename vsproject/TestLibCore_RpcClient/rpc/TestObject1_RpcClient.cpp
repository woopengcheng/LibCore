#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject1_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "TestObject1_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject1_RpcTimeout(SINT8 userid1/* = 0*/ , UINT8 localid2/* = 0*/ , INT16 userid3/* = 0*/ , UINT16 localid4/* = 0*/ , double localid10/* = 1.0f*/ , float localid11/* = 1.0f*/ , std_string localid12/* = std::string()*/ , LibCore_Chunk localid13/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "TestObject1_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

