#include "GlobalRpc.h"
#include "TestObject.h"

Msg::ObjectMsgCall * Server::TestObject::TestObject1_RpcServer(SINT8 userid1/* = 0*/ , UINT8 localid2/* = 0*/ , INT16 userid3/* = 0*/ , UINT16 localid4/* = 0*/ , double localid10/* = 1.0f*/ , float localid11/* = 1.0f*/ , std_string localid12/* = std::string()*/ , CUtilChunk localid13/* = CUtil::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{


	std::cout << "TestObject1_RpcServer "<< std::endl;
	Return();
}

