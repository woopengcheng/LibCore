#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHGet_RpcServer(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	std_string value = std::string();

	if (key.size() == 0 || table.size() == 0 && !GetDBServer() && !GetDBServer()->GetEnvironment())
	{
		RPCReturn1(value);
	}

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(".sys");
	if (!pDB)
	{
		RPCReturn1(value);
	}

	GameDB::Operate oper;
	GameDB::HashTable::HGet(*pDB , oper , table , key);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "key:" << key << "success.");
		RPCReturn1(oper.GetParamters().GetValue<std::string>(0));
	} 

	std::cout << "HandleHGet_RpcServer "<< std::endl;
	RPCReturn1(value);
}
