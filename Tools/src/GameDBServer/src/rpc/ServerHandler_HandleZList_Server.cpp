#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZList_RpcServer(Net::ISession * pSession, Msg::Object objSrc   )
{
	LibCore_Chunk res = 0;

	GameDB::Database * pDB = this->GetDataBase();
	if (!pDB)
	{
		Return(res);
	} 

	GameDB::Operate oper;
	GameDB::SortedSet::ZList(*pDB , oper );
	if (oper.IsSuccess())
	{ 
		Return(oper.GetOperateReturns().GetStream().GetData());
	} 

	std::cout << "HandleZList_RpcServer "<< std::endl;
	Return(res);
}

