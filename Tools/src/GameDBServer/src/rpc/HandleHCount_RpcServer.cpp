#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHCount_RpcServer(std_string table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT64 res = -1;

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HCount(*pDB , oper , table);
	if (oper.IsSuccess())
	{ 
		res = 0;
		gDebugStream("table:" << table << "key:" << "success."); 
	}

	gDebugStream("HandleHSize_RpcServer "<< res );
	RPCReturn1(res);
}

