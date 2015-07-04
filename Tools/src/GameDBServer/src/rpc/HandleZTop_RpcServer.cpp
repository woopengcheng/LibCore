#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/SortedSet.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZTop_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/  )
{
	LibCore_Chunk res;

	GameDB::Database * pDB = this->GetDataBase();
	if ( table.size() == 0 || !pDB)
	{
		RPCReturn1(res);
	}   

	GameDB::Operate oper;
	GameDB::SortedSet::ZTop(*pDB , oper , table , start , end , limit);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "start:" << start << "end" << end  << "limit" << limit << "success.");
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	}  

	std::cout << "HandleZTop_RpcServer "<< std::endl;
	RPCReturn1(res);
}

