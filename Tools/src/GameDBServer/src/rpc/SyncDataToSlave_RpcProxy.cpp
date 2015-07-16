#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcServerProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  ,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	INT32 res = 0;

	Server::MasterHandler * pMasterHandler = Server::DBMaster::GetInstance().GetMasterHandler(dbname);
	if (pMasterHandler && pMasterHandler->GetSession())
	{
		INT32 nSessionID = pMasterHandler->GetSession()->GetOtherSession()->GetSessionID();
		if(ERR_FAILURE == ProxySendMsg(nSessionID , 1 , dbname , value))
		{
			RPCReturn1(res);
		}

	}

	std::cout << "SyncDataToSlave_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcClientProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  ,INT32 res/* = 0*/)
{




	std::cout << "SyncDataToSlave_RpcClientProxy" << std::endl;
	RPCReturn1(res);
}

Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcTimeoutProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ )
{


 	std::cout << "SyncDataToSlave_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

