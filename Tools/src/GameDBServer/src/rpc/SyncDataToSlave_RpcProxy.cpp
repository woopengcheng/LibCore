#include "GlobalRpc.h"
#include "MasterHandler.h"


Msg::ObjectMsgCall * Msg::GlobalRpc::SyncDataToSlave_RpcServerProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  ,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	INT32 res = 0;

	Server::SlaveRecord * pSlaveRecord = Server::DBMaster::GetInstance().GetSlaveRecord(dbname);
	if (pSlaveRecord)
	{
		if(ERR_FAILURE == ProxySendMsg(pSlaveRecord->GetSlaveSessionID() , pSlaveRecord->GetObjRemoteSlaveID() , dbname , value))
		{
			RPCReturn1(res);
		}

	}

	std::cout << "SyncDataToSlave_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SyncDataToSlave_RpcClientProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  ,INT32 res/* = 0*/)
{




	std::cout << "SyncDataToSlave_RpcClientProxy" << std::endl;
	RPCReturn1(res);
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SyncDataToSlave_RpcTimeoutProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ )
{


 	std::cout << "SyncDataToSlave_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

