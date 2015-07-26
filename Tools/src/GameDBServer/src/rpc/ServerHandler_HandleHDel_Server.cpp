#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "RPCCallFuncs.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHDel_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &table/* = std::string()*/ , std_string & key/* = std::string()*/  )
{
	INT32 res = -1;

	GameDB::Database * pDB = this->GetDataBase();
	if (key.size() == 0 || table.size() == 0 || !pDB)
	{
		RPCReturn1(res);
	} 

	GameDB::Operate oper;
	GameDB::HashTable::HDel(*pDB , oper , table , key);
	if (oper.IsSuccess())
	{
		rpc_SyncDataToSlave("tcp://127.0.0.1:9001" , 0 , GetObjectID() , m_strDatabaseName , oper.GetOperateRecord().GetData());

		res = 0;
		gDebugStream("HDel: table:" << table  << "success.");
	}

	gDebugStream("HandleHDel_RpcServer "<< res);
	RPCReturn1(res);
}

