#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "DBClient.h"

namespace Client
{
	static INT32  local_call_HandleHSet(const char * pSessionName , INT32 userid/* = 0*/ , INT32 localid/* = 1*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&MSG_INSTANCE) , pSessionName , Msg::g_szHandleHSet_RpcCall , userid , localid , vecTargets , objSrc , usPriority , MSG_INSTANCE.GetServerName() , objSyncType);
	}

}

#endif
