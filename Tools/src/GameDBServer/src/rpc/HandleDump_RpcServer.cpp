#include "GlobalRpc.h"
#include "ServerHandler.h"

Msg::ObjectMsgCall * Server::ServerHandler::HandleDump_RpcServer(std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{
	LibCore_Chunk res;

	GameDB::Database * pDB = GetDataBase();
	if (!pDB)
	{
		RPCReturn1(res);
	}

	int nCount = 0;
	GameDB::Operate oper;
	leveldb::Iterator * iter = pDB->GetLevelDB()->NewIterator(leveldb::ReadOptions());
	iter->SeekToFirst();
	while(iter->Valid())
	{
		GameDB::Slice key = iter->key();
		GameDB::Slice val = iter->value();
		 
		oper.GetOperateReturns().GetStream() << key.ToString() << val.ToString();

		++nCount;
		iter->Next();
	} 
	delete iter;  
	  
	oper.GetOperateReturns().GetStream().Insert(oper.GetOperateReturns().GetStream().Begin() , &nCount , sizeof(nCount));

 	std::cout << "HandleDump_RpcServer "<< std::endl;
	RPCReturn1(oper.GetOperateReturns().GetStream().GetData());
}

