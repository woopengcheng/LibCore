#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::testTheSameNode_RpcServer(Net::ISession * pSession, Msg::Object objSrc ,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testTheSameNode_RpcServer "<< std::endl;
	RPCReturn1(res);
}

