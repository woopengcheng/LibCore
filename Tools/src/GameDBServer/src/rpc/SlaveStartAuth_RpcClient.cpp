#include "GlobalRpc.h"
#include "DBSlave.h"
#include "GameDB/inc/SlaveSession.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &value/* std::string()*/ ) 
{ 
	if (value != "")
	{
		if (GetSession() && GetSession()->GetOtherSession())
		{
			GameDB::SlaveSession * pSession = (GameDB::SlaveSession *)GetSession()->GetOtherSession();
			Server::DBSlave::GetInstance().SelectDB(pSession->GetSlaveInfo().strDBName); 
		}

		std::cout << "SlaveStartAuth_RpcClient" << std::endl;
	}

	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &pwd/* = std::string()*/ , std_string & name/* = std::string()*/ ) 
{


	std::cout << "SlaveStartAuth_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

