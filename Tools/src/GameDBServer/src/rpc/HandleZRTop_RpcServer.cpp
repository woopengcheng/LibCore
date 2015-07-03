#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/SortedSet.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleZRTop_RpcServer(std_string &table/* = std::string()*/ , INT64 start/* = 0*/ , INT64 end/* = 0*/ , INT64 limit/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res;
	 
	GameDB::Database * pDB = this->GetDataBase();
	if (table.size() == 0 || !pDB)
	{
		RPCReturn1(res);
	}  

	GameDB::Operate oper;
	GameDB::SortedSet::ZRTop(*pDB , oper , table , start , end , limit);
	if (oper.IsSuccess())
	{
		gDebugStream("table:" << table << "start:" << start << "end" << end  << "limit" << limit << "success.");
		RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
	}  
	 
	std::cout << "HandleZRTop_RpcServer "<< std::endl;
	RPCReturn1(res);
}

