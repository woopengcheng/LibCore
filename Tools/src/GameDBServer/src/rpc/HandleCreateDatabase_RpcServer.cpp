#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleCreateDatabase_RpcServer(std_string &dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = -1;

	GameDB::Environment * pEnv = GetDBServer()->GetEnvironment();
	if (!pEnv)
	{ 
		RPCReturn1(res);
	}  
	
	if (!pEnv->GetDatabase(dbname))
	{
		GameDB::Database * pDB = pEnv->CreateDatabase(dbname);
		if (pDB)
		{
			res = 0;
		}
	}

	gDebugStream("HandleCreateDatabase_RpcServer "<< res);
	RPCReturn1(res);
}

