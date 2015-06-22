#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/SortedSet.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZSet_RpcServer(std_string table  , std_string key , INT64 score, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc)
{
	INT32 resCode = 0;
	 
	if (key.size() == 0 || table.size() == 0 && !GetDBServer() && !GetDBServer()->GetEnvironment())
	{
		RPCReturn1(resCode);
	}

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{
		RPCReturn1(resCode);
	}

	GameDB::Operate oper;
	GameDB::SortedSet::ZSet(*pDB , oper , table , key , score);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "key:" << key << "score:" << score << "success.");
		RPCReturn1(0);
	} 

	std::cout << "HandleZSet_RpcServer "<< std::endl;
	RPCReturn1(resCode);
}

