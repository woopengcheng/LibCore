#include "GlobalRpc.h"
#include "DBSlave.h"
#include "GameDB/inc/SlaveSession.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{ 
	if (res == 0)
	{
		GameDB::SlaveSession * pSession = (GameDB::SlaveSession *)GetSession();
		if (pSession)
		{
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

