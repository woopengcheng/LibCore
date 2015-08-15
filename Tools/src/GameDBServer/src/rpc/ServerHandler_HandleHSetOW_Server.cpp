#include "ServerHandler.h"
#include "RPCCallFuncs.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleHSetOW_RpcServer(Net::ISession * pSession, Msg::Object objSrc , std_string &table/* = std::string()*/ , std_string & key/* = std::string()*/ , std_string & value/* = std::string()*/  )
{
	INT32 res = -1;

	if (key.size() == 0 || table.size() == 0 || !this->GetDataBase())
	{
		Return(res);
	}

	GameDB::Database * pDB = this->GetDataBase(); 

	GameDB::Operate oper;
	GameDB::HashTable::HSetOW(*pDB , oper , table , key , value);
	if (oper.IsSuccess())
	{ 
		rpc_SyncDataToSlave("tcp://127.0.0.1:9001" , 0 , GetObjectID() , m_strDatabaseName , oper.GetOperateRecord().GetData());

		res = 0;
		gDebugStream("table:" << table << "key:" << key << "value:" << value << "success."); 
	} 

	gDebugStream("HandleHSetOW_RpcServer "<< res);
	Return(res);
}
