#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSetIncrFloat_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , std_string & key/* = std::string()*/ , double value/* = 0.0f*/  )
{
	double res = 0.0f;

	if (key.size() == 0 || table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HSetIncrFloat(*pDB , oper , table , key , value);
	if (oper.IsSuccess())
	{
		oper.GetOperateReturns().GetStream() >> res;
		gDebugStream("table:" << table << "key:" << key << "value:" << value << "success."); 
	}

	gDebugStream("HandleHSetIncrFloat_RpcServer "<< res);
	RPCReturn1(res);
}

