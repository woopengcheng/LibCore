#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/SortedSet.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZGet_RpcServer(std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT64 llScore = -1; 

	GameDB::Database * pDB = this->GetDataBase();
	if (key.size() == 0 || table.size() == 0 || !pDB)
	{
		RPCReturn1(llScore);
	} 
	 
	GameDB::Operate oper;
	GameDB::SortedSet::ZGet(*pDB , oper , table , key);
	if (oper.IsSuccess())
	{
		oper.GetOperateReturns().GetStream() >> llScore;
		gDebugStream("table:" << table << "key:" << key << "success."); 
	} 

	gDebugStream("HandleZGet_RpcServer score:"<< llScore);
	RPCReturn1(llScore);
}

