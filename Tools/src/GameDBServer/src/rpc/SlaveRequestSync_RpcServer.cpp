#include "GlobalRpc.h"
#include "DBServer.h"
#include "GameDB/inc/Environment.h"
#include "TimerLib/inc/TimerHelp.h"


Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveRequestSync_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc ,std_string & dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/)
{
	std_string newbackdir = std::string();
	INT32 res = 1;

	GameDB::Database * pDB = Server::DBServer::GetInstance().GetEnvironment()->GetDatabase(dbname);
	if (!pDB)
	{
		RPCReturn2(newbackdir , res);
	}

	std::string strTimeStamp = Timer::TimerHelper::GetDate("%Y%m%d%H%M%S");
	pDB->Backup(strTimeStamp , Server::DBServer::GetInstance().GetBackupDir());
	newbackdir = Server::DBServer::GetInstance().GetBackupDir() + strTimeStamp;

	res = 0;
	std::cout << "SlaveRequestSync_RpcServer "<< std::endl;
	RPCReturn2(newbackdir , res);
}

