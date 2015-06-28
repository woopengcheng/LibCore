#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSetIncr_RpcServer(std_string table/* = std::string()*/ , std_string key/* = std::string()*/ , INT64 value/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT64 res = -1;

	if (key.size() == 0 || table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HSetIncr(*pDB , oper , table , key , value);
	if (oper.IsSuccess())
	{
		oper.GetOperateReturns().GetStream() >> res;
		gDebugStream("table:" << table << "key:" << key << "value:" << value << "success."); 
	}
	gDebugStream("HandleHSetIncr_RpcServer "<< res);
	RPCReturn1(res);
}

