#include "GlobalRpc.h"
#include "DBSlave.h"
#include "GameDB/inc/SlaveSession.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcClient(std_string value/* std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
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

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcTimeout(std_string pwd/* = std::string()*/ , std_string name/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SlaveStartAuth_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

