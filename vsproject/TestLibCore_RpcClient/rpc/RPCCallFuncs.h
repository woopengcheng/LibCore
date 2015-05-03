#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "RpcInstance.h"

namespace Client
{
	static INT32  local_call_TestObject1(const char * pSessionName , SINT8 userid1/* = 0*/ , UINT8 localid2/* = 0*/ , INT16 userid3/* = 0*/ , UINT16 localid4/* = 0*/ , double localid10/* = 1.0f*/ , float localid11/* = 1.0f*/ , std_string localid12/* = std::string()*/ , LibCore_Chunk localid13/* = LibCore::Chunk()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_8((&MSG_INSTANCE) , pSessionName , Msg::g_szTestObject1_RpcCall , userid1 , localid2 , userid3 , localid4 , localid10 , localid11 , localid12 , localid13 , vecTargets , objSrc , usPriority , MSG_INSTANCE.GetServerName() , objSyncType);
	}

	static INT32  local_call_TestObject(const char * pSessionName , UINT64 userid9/* = 0*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , UINT32 userid7/* = 0*/ , INT64 localid8/* = 0*/ , INT32 localid6/* = 0*/ , UINT16 localid4/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_7((&MSG_INSTANCE) , pSessionName , Msg::g_szTestObject_RpcCall , userid9 , userid1 , userid3 , userid7 , localid8 , localid6 , localid4 , vecTargets , objSrc , usPriority , MSG_INSTANCE.GetServerName() , objSyncType);
	}

}

#endif
