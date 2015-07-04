#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleUserAuth_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/  )
{
	INT32 res = -1;

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(g_szSystemDatabase);
	if (!pDB)
	{ 
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HGet(*pDB , oper , GameDB::User::TableName() , name);
	if (!oper.IsSuccess())
	{
		gDebugStream("DB:" <<  g_szSystemDatabase << " table:" <<  g_szSystemDatabase << "name:" << name << "failure.");
		RPCReturn1(res);
	}  

	std::string value;
	oper.GetOperateReturns().GetStream() >> value;
	if (value.length() <= 0)
	{
		gDebugStream("DB:" << g_szSystemDatabase << "table:" << g_szSystemDatabase << "key:" << name << "auth failure.");
		RPCReturn1(res);
	} 

	GameDB::User objUser;
	objUser.FromBson(value.c_str() , (INT32)value.length()); 

	if(objUser.get_pswd() != pwd)
	{ 
		gDebugStream("DB:" << g_szSystemDatabase << "table:" << g_szSystemDatabase << "key:" << name << "password wrong.");
		RPCReturn1(res); 
	}
	 
	m_objAuthInfo.SetUserInfo(objUser);
	res = 0;
	gDebugStream("HandleUserAuth_RpcServer "<< res);
	RPCReturn1(res);
}

