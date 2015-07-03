#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZDrop_RpcServer(std_string &table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
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

