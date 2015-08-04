#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::MasterStartSync_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/)
{


	std::cout << "MasterStartSync_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::MasterStartSync_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc ,std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "MasterStartSync_RpcTimeout" << std::endl;
	ReturnNULL;
}

