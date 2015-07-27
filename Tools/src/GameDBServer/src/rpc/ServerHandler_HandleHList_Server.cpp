#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHList_RpcServer(Net::ISession * pSession, Msg::Object objSrc   )
{
	LibCore_Chunk res = LibCore::Chunk();

	if (!this->GetDataBase())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HList(*pDB , oper);
	if (oper.IsSuccess())
	{ 
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	} 

	std::cout << "HandleHList_RpcServer "<< std::endl;
	RPCReturn1(res);
}

