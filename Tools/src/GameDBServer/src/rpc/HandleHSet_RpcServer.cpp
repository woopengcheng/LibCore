#include "GlobalRpc.h"
#include "ServerHandler.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"
#include "RPCCallFuncs.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSet_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc ,  std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/  , std_string & value /* = std::string()*/  )
{
	INT32 res = -1;
	if (value.size() == 0 || key.size() == 0 || table.size() == 0 || !this->GetDataBase())
	{
		RPCReturn1(res);
	}
	 
	GameDB::Database * pDB = this->GetDataBase(); 
	  
	GameDB::Operate oper;
	GameDB::HashTable::HSet(*pDB , oper , table , key , value);
	if (oper.IsSuccess())
	{
// 		std::vector<Msg::Object> vecTargets2;
// 		vecTargets2.push_back(Msg::Object(1));
// 		rpc_SyncDataToSlave("tcp://127.0.0.1:9001" , GameDB::g_szSystemDatabase , oper.GetOperateRecord().GetData() , vecTargets2 , Msg::Object(1));

		res = 0;
		gDebugStream("table:" << table << "key:" << key << "value:" << value << "success."); 
	}

	gDebugStream("HandleHSet_RpcServer "<< res);
	RPCReturn1(res);
}
