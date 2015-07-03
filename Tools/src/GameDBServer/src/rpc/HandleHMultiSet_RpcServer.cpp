#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/DBCommon.h"
#include "leveldb/slice.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHMultiSet_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , LibCore_Chunk & keyvalues/* = LibCore::Chunk()*/  )
{
	INT32 res = -1;

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::CollectionKeyValsT mapKeys;
	std::map<std::string , std::string> mapStrKeyValues;
	LibCore::CStream cs;
	cs << keyvalues;
	cs >> mapStrKeyValues;
	std::map<std::string , std::string>::iterator iter = mapStrKeyValues.begin();
	for (;iter != mapStrKeyValues.end();++iter)
	{
		std::string first = iter->first;
		GameDB::Slice second = iter->second;
		mapKeys.insert(std::pair<std::string , GameDB::Slice>(first , second));
	}

	GameDB::Operate oper;
	GameDB::HashTable::HMultiSet(*pDB , oper , table ,mapKeys);
	if (oper.IsSuccess())
	{
		res = 0;
		gDebugStream("HMultiDel table:" << table << "success."); 
	} 

	gDebugStream("HandleHMultiSet_RpcServer "<< res);
	RPCReturn1(res);
}

