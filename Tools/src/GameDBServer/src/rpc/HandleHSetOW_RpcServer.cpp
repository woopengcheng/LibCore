#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSetOW_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/  )
{
	INT32 res = -1;

	if (key.size() == 0 || table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HSetOW(*pDB , oper , table , key , value);
	if (oper.IsSuccess())
	{ 
		res = 0;
		gDebugStream("table:" << table << "key:" << key << "value:" << value << "success."); 
	} 

	gDebugStream("HandleHSetOW_RpcServer "<< res);
	RPCReturn1(res);
}

