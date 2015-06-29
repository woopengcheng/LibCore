#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/HashTable.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHMultiDel_RpcServer(std_string table/* = std::string()*/ , LibCore_Chunk keys/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	INT32 res = -1;

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::CollectionSlicesT vecKeys;
	std::vector<std::string> vecStrKeys;
	LibCore::CStream cs;
	cs << keys;
	cs >> vecStrKeys;
	std::vector<std::string>::iterator iter = vecStrKeys.begin();
	for (;iter != vecStrKeys.end();++iter)
	{
		vecKeys.push_back(*iter);
	}

	GameDB::Operate oper;
	GameDB::HashTable::HMultiDel(*pDB , oper , table ,vecKeys);
	if (oper.IsSuccess())
	{
		gDebugStream("HMultiDel table:" << table << "success.");  
		oper.GetOperateReturns().GetStream() >> res; 
	} 

	gDebugStream("HandleHMultiDel_RpcServer "<< res);
	RPCReturn1(res);
}
