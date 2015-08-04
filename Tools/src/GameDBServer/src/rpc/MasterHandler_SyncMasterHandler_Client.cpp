#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::SyncMasterHandler_RpcClient(Net::ISession * pSession, Msg::Object objSrc , INT32 res/* = 0*/)
{


	std::cout << "SyncMasterHandler_RpcClient" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SyncMasterHandler_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , INT32 id/* = 0*/)
{


	std::cout << "SyncMasterHandler_RpcTimeout" << std::endl;
	ReturnNULL;
}

