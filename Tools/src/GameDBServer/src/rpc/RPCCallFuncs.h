#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "DBSlave.h"
#include "DBServer.h"
#include "DBMaster.h"

namespace Server
{
	static INT32  local_call_SlaveRequestSync(const char * pSessionName , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_0((&(Server::DBSlave::GetInstance())) , pSessionName , Msg::g_szSlaveRequestSync_RpcCall , vecTargets , objSrc , usPriority , Server::DBSlave::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_MasterStartSync(const char * pSessionName , LibCore_Chunk value/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{
		GEN_RPC_CALL_1((&(Server::DBMaster::GetInstance())) , pSessionName , Msg::g_szMasterStartSync_RpcCall , value, vecTargets , objSrc , usPriority , Server::DBMaster::GetInstance().GetServerName() , objSyncType , 10);
	}

}

#endif
