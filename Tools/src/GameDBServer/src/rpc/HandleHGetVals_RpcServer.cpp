#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHGetVals_RpcServer(std_string &table/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res = LibCore::Chunk();

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HGetVals(*pDB , oper , table);
	if (oper.IsSuccess())
	{
		gDebugStream("HGetKeys table:" << table << "success."); 
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	} 

	std::cout << "HandleHGetVals_RpcServer "<< std::endl;
	RPCReturn1(res);
}

