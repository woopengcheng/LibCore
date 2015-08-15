#include "GlobalRpc.h"
#include "MasterHandler.h"


Msg::ObjectMsgCall * Server::GlobalRpc::SyncDataToSlave_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc  ,std_string & dbname/* = std::string()*/ , CUtilChunk & value/* = CUtil::Chunk()*/)
{
	INT32 res = 0;

	Server::SlaveRecord * pSlaveRecord = Server::DBMaster::GetInstance().GetSlaveRecord(dbname);
	if (pSlaveRecord)
	{
		if(ERR_FAILURE == ProxySendMsg(pSlaveRecord->GetSlaveSessionID() , pSlaveRecord->GetObjRemoteSlaveID() , dbname , value))
		{
			Return(res);
		}

	}

	std::cout << "SyncDataToSlave_RpcServerProxy" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::GlobalRpc::SyncDataToSlave_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc  ,INT32 res/* = 0*/)
{




	std::cout << "SyncDataToSlave_RpcClientProxy" << std::endl;
	Return(res);
}

Msg::ObjectMsgCall * Server::GlobalRpc::SyncDataToSlave_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc,std_string & dbname/* = std::string()*/ , CUtilChunk & value/* = CUtil::Chunk()*/ )
{


 	std::cout << "SyncDataToSlave_RpcTimeoutProxy" << std::endl;
	ReturnNULL;
}
