#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "DBClient.h"

namespace Client
{
#ifndef MSG_INSTANCE
#error "need define marcor MSG_INSTANCE for rpc use."
#endif
	static INT32  local_call_HandleHSet(const char * pSessionName , std_string table/* = std::string()*/ , std_string value/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_3((&MSG_INSTANCE) , pSessionName , Msg::g_szHandleHSet_RpcCall , table , value , key , vecTargets , objSrc , usPriority , MSG_INSTANCE.GetServerName() , objSyncType);
	}

	static INT32  local_call_HandleHGet(const char * pSessionName , std_string table/* = std::string()*/ , std_string key/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_2((&MSG_INSTANCE) , pSessionName , Msg::g_szHandleHGet_RpcCall , table , key , vecTargets , objSrc , usPriority , MSG_INSTANCE.GetServerName() , objSyncType);
	}

}

#endif
