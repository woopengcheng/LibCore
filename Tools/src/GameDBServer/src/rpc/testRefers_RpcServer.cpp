#include "GlobalRpc.h"
#include "SlaveHandler.h"

Msg::ObjectMsgCall * Server::SlaveHandler::testRefers_RpcServer(std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testRefers_RpcServer "<< std::endl;
	RPCReturn1(res);
}

