#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "TimerLib/inc/TimerHelp.h"

Msg::ObjectMsgCall * Server::ServerHandler::SlaveRequestSync_RpcServer(std_string dbbackdir/* = std::string()*/ , std_string dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	std_string newbackdir = std::string();
	INT32 res = 1;

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(dbname);
	if (!pDB)
	{
		RPCReturn2(newbackdir , res);
	}

	std::string strTimeStamp = Timer::TimerHelper::GetDate("%Y%m%d%H%M%S");
	pDB->Backup(strTimeStamp , GetDBServer()->GetBackupDir());
	newbackdir = GetDBServer()->GetBackupDir() + strTimeStamp;
	  
	res = 0;
	std::cout << "SlaveRequestSync_RpcServer "<< std::endl;
	RPCReturn2(newbackdir , res);
}

