#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZList_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc   )
{
	LibCore_Chunk res = 0;

	GameDB::Database * pDB = this->GetDataBase();
	if (!pDB)
	{
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::SortedSet::ZList(*pDB , oper );
	if (oper.IsSuccess())
	{ 
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	} 

	std::cout << "HandleZList_RpcServer "<< std::endl;
	RPCReturn1(res);
}

