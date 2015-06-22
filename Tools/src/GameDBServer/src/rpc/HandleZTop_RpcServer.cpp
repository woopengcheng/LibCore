#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/SortedSet.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZTop_RpcServer(std_string table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res;
	
	if (table.size() == 0 && !GetDBServer() && !GetDBServer()->GetEnvironment())
	{
		RPCReturn1(res);
	}

	GameDB::Database * pDB = GetDBServer()->GetEnvironment()->GetDatabase(GameDB::g_szSystemDatabase);
	if (!pDB)
	{
		RPCReturn1(res);
	}

	GameDB::Operate oper;
	GameDB::SortedSet::ZTop(*pDB , oper , table , start , end , limit);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "start:" << start << "end" << end  << "limit" << limit << "success.");
		RPCReturn1(oper.GetStream().GetData());
	}  

	std::cout << "HandleZTop_RpcServer "<< std::endl;
	RPCReturn1(res);
}

