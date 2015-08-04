#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHGetVals_RpcServer(Net::ISession * pSession, Msg::Object objSrc , std_string &table/* = std::string()*/  )
{
	LibCore_Chunk res = LibCore::Chunk();

	if (table.size() == 0 || !this->GetDataBase())
	{
		Return(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HGetVals(*pDB , oper , table);
	if (oper.IsSuccess())
	{
		gDebugStream("HGetKeys table:" << table << "success."); 
		Return(oper.GetOperateReturns().GetStream().GetData());
	} 

	std::cout << "HandleHGetVals_RpcServer "<< std::endl;
	Return(res);
}

