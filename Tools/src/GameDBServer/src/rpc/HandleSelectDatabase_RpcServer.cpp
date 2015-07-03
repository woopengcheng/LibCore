#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleSelectDatabase_RpcServer(std_string &dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = -1; 

	if(!m_objAuthInfo.CheckSysPermission() && dbname == GameDB::g_szSystemDatabase && m_pDBServer && m_pDBServer->GetEnvironment() && m_pDBServer->GetEnvironment()->GetDatabase(dbname))
	{
		res = -1;
	}
	else
	{
		res = 0;
		m_strDatabaseName = dbname;
	}

	gDebugStream("HandleSelectDatabase_RpcServer "<< res);
	RPCReturn1(res);
}

