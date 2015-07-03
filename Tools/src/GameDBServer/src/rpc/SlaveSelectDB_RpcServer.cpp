#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveSelectDB_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &dbname/* = std::string()*/  )
{
	INT32 res = 0;

	if(m_strDatabaseName.length() > 0)
	{ 
		res = -1;
	} 
	else
	{
		m_strDatabaseName = dbname;
	}

	std::cout << "SlaveSelectDB_RpcServer "<< std::endl;
	RPCReturn1(res);
}

