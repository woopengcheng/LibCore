#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZDrop_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/  )
{
	INT32 res = -1;

	GameDB::Database * pDB = this->GetDataBase();
	if (table.size() == 0 || !pDB)
	{
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::SortedSet::ZDrop(*pDB , oper , table );
	if (oper.IsSuccess())
	{ 
		oper.GetOperateReturns().GetStream() >> res;
		gDebugStream("HDel: table:" << table  << "success.");
	}

	gDebugStream("HandleZDrop_RpcServer "<< res);
	RPCReturn1(res);
}

