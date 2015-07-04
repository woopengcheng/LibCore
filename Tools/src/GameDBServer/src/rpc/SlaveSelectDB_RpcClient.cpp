#include "GlobalRpc.h"
#include "GameDB/inc/SlaveSession.h"
#include "DBSlave.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveSelectDB_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/ ) 
{
	if (res == 0)
	{
		if (GetSession() && GetSession()->GetOtherSession())
		{
			GameDB::SlaveSession * pSession = (GameDB::SlaveSession *)GetSession()->GetOtherSession();
			Server::DBSlave::GetInstance().RequestSyncData(pSession->GetSlaveInfo().strDBName , pSession->GetSlaveInfo().strDir ); 
		}

		std::cout << "SlaveStartAuth_RpcClient" << std::endl;
	}


	std::cout << "SlaveSelectDB_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveSelectDB_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &dbname/* = std::string()*/ ) 
{


	std::cout << "SlaveSelectDB_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

