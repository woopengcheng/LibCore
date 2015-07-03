#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHGetKeyVals_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/  )
{
	LibCore_Chunk res = LibCore::Chunk();

	if (table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HGetKeyVals(*pDB , oper , table);
	if (oper.IsSuccess())
	{
		gDebugStream("HGetKeys table:" << table << "success."); 
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	} 
	 
	std::cout << "HandleHGetKeyVals_RpcServer "<< std::endl;
	RPCReturn1(res);
}

