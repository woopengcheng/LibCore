#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "stdafx.h" 
#include "MsgLib/inc/MsgHelper.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "MsgLib/inc/RPCMsgCall.h"

namespace Client
{ 

	static INT32  local_call_TestObject(const char * pSessionName , char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_NONSYNC)
	{ 
		const char * pServerName = RpcInstance::GetInstance().GetServerName();
		GEN_RPC_CALL(pSessionName , Msg::g_szTestObject_RpcCall , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority , pServerName);
	}
}


#endif