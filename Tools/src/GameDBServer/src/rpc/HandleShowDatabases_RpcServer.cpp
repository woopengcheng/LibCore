#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleShowDatabases_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc   )
{
	LibCore_Chunk res = LibCore::Chunk();

	GameDB::Environment * pEnv = GetDBServer()->GetEnvironment();
	if (!pEnv)
	{ 
		RPCReturn1(res);
	} 

	std::vector<std::string> strAllDBS;
	pEnv->GetAllDatabase(strAllDBS); 
	
	LibCore::CStream cs;
	cs << (UINT32)strAllDBS.size();
	std::vector<std::string>::iterator iter = strAllDBS.begin();
	for (;iter != strAllDBS.end();++iter)
	{
		cs << *iter;
	}

	std::cout << "HandleShowDatabases_RpcServer "<< std::endl;
	RPCReturn1(cs.GetData());
}

