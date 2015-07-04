#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::SlaveStartAuth_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/  )
{
	std_string value = std::string();

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{ 
		RPCReturn1(value);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HGet(*pDB , oper , GameDB::User::TableName() , name);
	if (!oper.IsSuccess())
	{
		gDebugStream("DB:" <<  GameDB::g_szSystemDatabase << " table:" <<  GameDB::g_szSystemUserTable << "name:" << name << "failure.");
		RPCReturn1(value);
	}  
	 
	oper.GetOperateReturns().GetStream() >> value;
	if (value.length() <= 0)
	{
		gDebugStream("DB:" << GameDB::g_szSystemUserTable << "table:" << GameDB::g_szSystemUserTable << "key:" << name << "failure.");
		RPCReturn1(std_string());
	} 

	GameDB::User objUser;
	objUser.FromBson(value.c_str() , value.length()); 

	if(objUser.get_pswd() != pwd)
	{ 
		gDebugStream("DB:" << GameDB::g_szSystemUserTable << "table:" << GameDB::g_szSystemUserTable << "key:" << name << "password wrong.");
		RPCReturn1(std_string()); 
	}
	 
	std::cout << "SlaveStartAuth_RpcServer "<< std::endl;
	RPCReturn1(value);
}

