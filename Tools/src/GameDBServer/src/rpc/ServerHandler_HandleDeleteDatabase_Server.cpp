#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleDeleteDatabase_RpcServer(Net::ISession * pSession, Msg::Object objSrc , std_string &dbname/* = std::string()*/  )
{
	INT32 res = -1;

	GameDB::Environment * pEnv = GetDBServer()->GetEnvironment();
	if (!pEnv)
	{ 
		RPCReturn1(res);
	}  

	if (pEnv->GetDatabase(dbname) && m_objAuthInfo.CheckSysPermission())
	{
		res = pEnv->RemoveDatabase(dbname) - 1;
	} 

	gDebugStream( "HandleDeleteDatabase_RpcServer " << res);;
	RPCReturn1(res);
}

