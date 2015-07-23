#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::MasterStartSync_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/)
{


	std::cout << "MasterStartSync_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::MasterStartSync_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc ,std_string & filename/* = std::string()*/ , INT32 filesize/* = 0*/ , INT32 sendtype/* = 0*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{


	std::cout << "MasterStartSync_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

