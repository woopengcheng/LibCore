#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHDel_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , std_string & key/* = std::string()*/  )
{
	INT32 res = -1;

	GameDB::Database * pDB = this->GetDataBase();
	if (key.size() == 0 || table.size() == 0 || !pDB)
	{
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HDel(*pDB , oper , table , key);
	if (oper.IsSuccess())
	{
		res = 0;
		gDebugStream("HDel: table:" << table  << "success.");
	}

	gDebugStream("HandleHDel_RpcServer "<< res);
	RPCReturn1(res);
}

