#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHScan_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , std_string & start/* = std::string()*/ ,std_string & regexp/* = std::string()*/ , INT64 limit/* = 10*/  )
{
	LibCore_Chunk res = LibCore::Chunk();

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HScan(*pDB , oper , table , start , regexp , limit , GameDB::HashTable::GET_ALL_TYPE_KEYS);
	if (oper.IsSuccess())
	{
		gDebugStream("HGetKeys table:" << table << "success."); 
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	} 
	 
	std::cout << "HandleHScan_RpcServer "<< std::endl;
	RPCReturn1(res);
}

