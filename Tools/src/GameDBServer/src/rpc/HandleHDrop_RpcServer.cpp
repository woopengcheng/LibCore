#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHDrop_RpcServer(std_string table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT64 res = -1;
	 
	GameDB::Database * pDB = this->GetDataBase();
	if (table.size() == 0 || !pDB)
	{
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HDrop(*pDB , oper , table);
	if (oper.IsSuccess())
	{
		res = 0;
		gOtherStream("delete table:" << table  << "success.");
	}
	 
	gDebugStream("HandleHDrop_RpcServer "<< res);
	RPCReturn1(res);
}

