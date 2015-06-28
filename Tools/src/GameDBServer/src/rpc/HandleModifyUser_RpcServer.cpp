#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleModifyUser_RpcServer(std_string name/* = std::string()*/ , std_string pwd/* = std::string()*/ , SINT8 issys/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = -1;

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{ 
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HGet(*pDB , oper , GameDB::User::TableName() , name);
	if (!oper.IsSuccess())
	{
		gDebugStream("DB:" <<  GameDB::g_szSystemDatabase << " table:" <<  GameDB::g_szSystemUserTable << "name:" << name << "failure.");
		RPCReturn1(res);
	}  

	std::string value;
	oper.GetOperateReturns().GetStream() >> value;
	if (value.length() <= 0)
	{
		gDebugStream("DB:" << GameDB::g_szSystemUserTable << "table:" << GameDB::g_szSystemUserTable << "key:" << name << "auth failure.");
		RPCReturn1(res);
	} 

	GameDB::User objUser;
	objUser.FromBson(value.c_str() , value.length()); 
	objUser.set_pswd(pwd.c_str());
	objUser.set_sysuser(issys);

	std::string strValue;
	objUser.ToBson(strValue);
	GameDB::HashTable::HSet(*pDB , oper , GameDB::User::TableName() , name , strValue);

	if (oper.IsSuccess())
	{
		res = 0;
	}

	gDebugStream("HandleModifyUser_RpcServer "<< res);
	RPCReturn1(res);
}

