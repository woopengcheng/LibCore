#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHCount_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/  )
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
		oper.GetOperateReturns().GetStream() >> res;
		gDebugStream("table:" << table << "key:" << "success."); 
	}

	gDebugStream("HandleHCount_RpcServer "<< res );
	RPCReturn1(res);
}

