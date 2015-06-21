#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSet_RpcServer( std_string table/* = std::string()*/ , std_string key/* = std::string()*/  , std_string value /* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 resCode = -1;
	if (value.size() == 0 || key.size() == 0 || table.size() == 0 && !GetDBServer() && !GetDBServer()->GetEnvironment())
	{
		RPCReturn1(resCode);
	}

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{
		RPCReturn1(resCode);
	}

	GameDB::Operate oper;
	GameDB::HashTable::HSet(*pDB , oper , table , key , value);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "key:" << key << "value:" << value << "success.");
		RPCReturn1(0);
	}

	std::cout << "HandleHSet_RpcServer "<< std::endl;
	RPCReturn1(resCode);
}

