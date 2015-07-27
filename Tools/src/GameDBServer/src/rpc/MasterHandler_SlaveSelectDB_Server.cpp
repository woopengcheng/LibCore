#include "GlobalRpc.h"
#include "MasterHandler.h"
#include "GameDB/inc/MasterSession.h"
#include "SlaveRecord.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveSelectDB_RpcServer(Net::ISession * pSession, Msg::Object objSrc , std_string &dbname/* = std::string()*/  )
{
	INT32 res = 0; 

	SlaveRecord * pRecord = GetSlaveRecord(objSrc);
	if (pRecord && pRecord->GetDBName() == "")
	{
		pRecord->SetDBName(dbname);
	}
	else
	{
		res = -1;
	} 

	std::cout << "SlaveSelectDB_RpcServer " << res << std::endl;
	RPCReturn1(res);
}

