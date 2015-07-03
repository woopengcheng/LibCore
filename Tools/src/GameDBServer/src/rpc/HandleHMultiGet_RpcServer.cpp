#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHMultiGet_RpcServer(std_string &table/* = std::string()*/ , LibCore_Chunk & keys/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res = 0;

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
	GameDB::HashTable::HMultiGet(*pDB , oper , table ,vecKeys);
	if (oper.IsSuccess())
	{
		gDebugStream("HMultiDel table:" << table << "success."); 
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());  
	} 
	 
	std::cout << "HandleHMultiGet_RpcServer "<< std::endl;
	RPCReturn1(res);
}

