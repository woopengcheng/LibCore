#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject1_RpcServerProxy(SINT8 userid1/* = 0*/ , UINT8 localid2/* = 0*/ , INT16 userid3/* = 0*/ , UINT16 localid4/* = 0*/ , double localid10/* = 1.0f*/ , float localid11/* = 1.0f*/ , std_string localid12/* = std::string()*/ , CUtilChunk localid13/* = CUtil::Chunk()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	ProxySendMsg("tcp://127.0.0.1:8002" , 0 , userid1 , localid2 , userid3 , localid4 , localid10 , localid11 , localid12 , localid13);
	std::cout << "TestObject1_RpcServerProxy" << std::endl;
	//Return();
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject1_RpcClientProxy(std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
 

	std::cout << "TestObject1_RpcClientProxy" << std::endl;
	Return();
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject1_RpcTimeout(SINT8 userid1/* = 0*/ , UINT8 localid2/* = 0*/ , INT16 userid3/* = 0*/ , UINT16 localid4/* = 0*/ , double localid10/* = 1.0f*/ , float localid11/* = 1.0f*/ , std_string localid12/* = std::string()*/ , CUtilChunk localid13/* = CUtil::Chunk()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	std::cout << "TestObject1_RpcTimeout" << std::endl;
	ReturnNULL;
}

