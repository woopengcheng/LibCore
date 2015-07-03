#include "GlobalRpc.h"
#include "GameDB/inc/SlaveSession.h"
#include "DBSlave.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveSelectDB_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveSelectDB_RpcTimeout(std_string &dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SlaveSelectDB_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

