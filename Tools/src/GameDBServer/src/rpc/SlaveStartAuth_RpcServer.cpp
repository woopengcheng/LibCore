#include "GlobalRpc.h"
#include "MasterHandler.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcServer(std_string pwd/* = std::string()*/ , std_string name/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = 0;
// 	 
// 	if (pwd.size() == 0 || name.size() == 0 && !GetDBServer() && !GetDBServer()->GetEnvironment())
// 	{
// 		RPCReturn1(resCode);
// 	}
// 
// 	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(".sys");
// 	if (!pDB)
// 	{
// 		RPCReturn1(resCode);
// 	}


	std::cout << "SlaveStartAuth_RpcServer "<< std::endl;
	RPCReturn1(res);
}

