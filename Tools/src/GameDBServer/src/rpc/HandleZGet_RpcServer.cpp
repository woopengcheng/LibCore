#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/SortedSet.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZGet_RpcServer(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT64 llScore = -1;

	if (key.size() == 0 || table.size() == 0 && !GetDBServer() && !GetDBServer()->GetEnvironment())
	{
		RPCReturn1(llScore);
	}

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{
		RPCReturn1(llScore);
	}
	 
	GameDB::Operate oper;
	GameDB::SortedSet::ZGet(*pDB , oper , table , key , llScore);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "key:" << key << "success.");
		RPCReturn1(llScore);
	} 

	std::cout << "HandleZGet_RpcServer "<< std::endl;
	RPCReturn1(llScore);
}

