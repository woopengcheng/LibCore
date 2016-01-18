#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::testMulitServerNode_RpcServer(INT32 nSessionID, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , CUtilChunk & value/* = CUtil::Chunk()*/ , int value2/* = 0*/ , unsigned int value22/* = 0*/ , char valChar/* = char(0)*/)
{
	CUtilChunk res = CUtil::Chunk();


	std::cout << "testMulitServerNode_RpcServer "<< std::endl;
	Return(res);
}

