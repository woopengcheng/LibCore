#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZDel_RpcServer(std_string &table/* = std::string()*/ , std_string & key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT64 score = -1;

	GameDB::Database * pDB = this->GetDataBase();
	if (key.size() == 0|| table.size() == 0 || !pDB)
	{
		RPCReturn1(score);
	} 

	GameDB::Operate oper;
	GameDB::SortedSet::ZDel(*pDB , oper , table , key);
	if (oper.IsSuccess())
	{
		oper.GetOperateReturns().GetStream() >> score ;
		gDebugStream("HDel: table:" << table  << "success.");
	}
	 
	gDebugStream("HandleZDel_RpcServer score"<< score);
	RPCReturn1(score);
}

