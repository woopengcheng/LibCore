#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleDeleteUser_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &name/* = std::string()*/  )
{
	INT32 res = -1; 

	GameDB::Database * pDB = this->GetDataBase();
	if (name.size() == 0 || !pDB || !pDB->IsSystemDatabase())
	{
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HDel(*pDB , oper , GameDB::User::TableName() , name);
	if (oper.IsSuccess())
	{
		res = 0;
		gDebugStream("delete user: name:" << name  << "success.");
	}

	gDebugStream("HandleDeleteUser_RpcServer "<< res);
	RPCReturn1(res);
}

