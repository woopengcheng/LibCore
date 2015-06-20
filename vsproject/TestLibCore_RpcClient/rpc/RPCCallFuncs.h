#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgNameDefine.h"
#include "RpcInstance.h"

namespace Client
{
	static INT32  local_call_TestObject(const char * pSessionName , UINT32 userid7/* = 0*/ , UINT64 userid9/* = 0*/ , UINT16 localid4/* = 0*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , INT64 localid8/* = 0*/ , INT32 localid6/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_7((&(Client::RpcInstance::GetInstance())) , pSessionName , Msg::g_szTestObject_RpcCall , userid7 , userid9 , localid4 , userid1 , userid3 , localid8 , localid6, vecTargets , objSrc , usPriority , Client::RpcInstance::GetInstance().GetServerName() , objSyncType , 10);
	}

	static INT32  local_call_TestObject1(const char * pSessionName , std_string localid12/* = std::string()*/ , UINT8 localid2/* = 0*/ , UINT16 localid4/* = 0*/ , double localid10/* = 1.0f*/ , LibCore_Chunk localid13/* = LibCore::Chunk()*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , float localid11/* = 1.0f*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0 , Msg::EMSG_SYNC_TYPE objSyncType = Msg::SYNC_TYPE_SYNC)
	{
		GEN_RPC_CALL_8((&(Client::RpcInstance::GetInstance())) , pSessionName , Msg::g_szTestObject1_RpcCall , localid12 , localid2 , localid4 , localid10 , localid13 , userid1 , userid3 , localid11, vecTargets , objSrc , usPriority , Client::RpcInstance::GetInstance().GetServerName() , objSyncType , 10);
	}

}

#endif
