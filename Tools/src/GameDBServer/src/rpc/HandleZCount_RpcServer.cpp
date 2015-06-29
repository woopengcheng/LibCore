#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZCount_RpcServer(std_string table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{ 
	INT64 res = -1;

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::SortedSet::ZCount(*pDB , oper , table);
	if (oper.IsSuccess())
	{ 
		oper.GetOperateReturns().GetStream() >> res;
		gDebugStream("table:" << table << "key:" << "success."); 
	}

	std::cout << "HandleZCount_RpcServer "<< std::endl;
	RPCReturn1(res);
}

