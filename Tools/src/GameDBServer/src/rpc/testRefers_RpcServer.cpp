#include "GlobalRpc.h"
#include "SlaveHandler.h"

Msg::ObjectMsgCall * Server::SlaveHandler::testRefers_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/  )
{
	LibCore_Chunk res = LibCore::Chunk();


	std::cout << "testRefers_RpcServer "<< std::endl;
	RPCReturn1(res);
}

