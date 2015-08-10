#include "ServerHandler.h"



Msg::ObjectMsgCall * Server::ServerHandler::testMulitServerNode_RpcServer(Net::ISession * pSession, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , int value2/* = 0*/ , unsigned int value22/* = 0*/ , char valChar/* = char(0)*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testMulitServerNode_RpcServer "<< std::endl;
	Return(res);
}

