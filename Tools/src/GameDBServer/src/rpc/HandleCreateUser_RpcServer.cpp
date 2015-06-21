#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"
#include "GameDB/inc/User.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleCreateUser_RpcServer(std_string name/* = std::string()*/ , std_string pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{ 
	INT32 res = -1;

	if (name.size() == 0 || pwd.size() == 0  && !GetDBServer() && !GetDBServer()->GetEnvironment())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{
		RPCReturn1(res);
	}

	std::string strValue;
	GameDB::User objUser;
	objUser.set_name(name.c_str());
	objUser.set_pswd(pwd.c_str());
	objUser.set_sysuser(true);
	objUser.ToBson(strValue);

	GameDB::Operate oper;
	GameDB::HashTable::HSet(*pDB , oper , GameDB::User::TableName() , name , strValue);
	if (oper.IsSuccess())
	{
		gDebugStream("create user: name:" << name  << "success.");
		RPCReturn1(0);
	}
	 
	std::cout << "HandleCreateUser_RpcServer "<< std::endl;
	RPCReturn1(res);
}

