#include "GlobalRpc.h"
#include "SlaveHandler.h"
#include "GameDB/inc/OperateRecord.h"
#include "GameDB/inc/DBCommon.h"

Msg::ObjectMsgCall * Server::SlaveHandler::SyncDataToSlave_RpcServer(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/  )
{
	INT32 res = 0;
	LibCore::CStream cs;
	cs.Pushback(value.Begin() , value.GetDataLen());
	
	INT32 nCount = 0;
	cs >> nCount;
	
	MsgAssert_Re0(nCount < 1000000 && nCount >= 0 , "wrong count.");
	MsgAssert_Re0(dbname == m_pDatabase->GetName() , "gamedatabase is not same.");

	INT32 nType = -1;
	while (nCount --)
	{
		cs >> nType;
		switch(nType)
		{
		case GameDB::OperateRecord::OPERATE_RECODE_INSERT:
			{
				std::string dbKey , value;
				cs >> dbKey >> value;

				leveldb::Status status = m_pDatabase->QuickWrite(GameDB::Slice(dbKey),GameDB::Slice(value));
				MsgAssert_Re0(status.ok() , "slave write error.");
			}
			break;
		case GameDB::OperateRecord::OPERATE_RECODE_DELETE:
			{

				std::string dbKey;
				cs >> dbKey;

				leveldb::Status status = m_pDatabase->QuickDel(GameDB::Slice(dbKey));
				MsgAssert_Re0(status.ok() , "slave delete error.");
			}
			break;
		default:
			MsgAssert_Re0(0 , "unknown operator type.");
			break;
		}
	}

	std::cout << "SyncDataToSlave_RpcServer "<< std::endl;
	RPCReturn1(res);
}




// 
// #include "GlobalRpc.h"
// #include "MasterHandler.h"
// 
// Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcServerProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc , std_string &dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ )
// {
// 	INT32 res = 0;
// 
// 
// 	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:9002" , dbname , value))
// 	{
// 		RPCReturn1(res);
// 	}
// 
// 
// 	std::cout << "SyncDataToSlave_RpcServerProxy" << std::endl;
// 	RPCReturnNULL;
// }
// 
// Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcClientProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  , INT32 res/* = 0*/)
// {
// 
// 
// 	std::cout << "SyncDataToSlave_RpcClientProxy" << std::endl;
// 	RPCReturn1(res);
// }
// 
// Msg::ObjectMsgCall * Server::MasterHandler::SyncDataToSlave_RpcTimeoutProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc , std_string &dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
// {
// 
// 
// 	std::cout << "SyncDataToSlave_RpcTimeoutProxy" << std::endl;
// 	RPCReturnNULL;
// }
// 
