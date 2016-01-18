#ifndef __msg_rpc_msg_helper_h__
#define __msg_rpc_msg_helper_h__
#include "MsgLib/inc/MsgCommon.h" 
#include "MsgLib/inc/RPCMsgCall.h" 
#include "CUtil/inc/ParameterHelper.h" 
#include "CUtil/inc/GenMsgHelper.h" 
#include "CUtil/inc/CUtil.h"
#include "CUtil/inc/Chunk.h"
#include "MsgLib/inc/MsgHelper.h"

namespace Msg
{  
	
#define GEN_RPC_CALL_8(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8 ,vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_7(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_6(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 );\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_5(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_4(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_3(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_2(pSendInstance , pSessionName , rpcCallName , p1 , p2 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_1(pSendInstance , pSessionName , rpcCallName , p1 , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
#define GEN_RPC_CALL_0(pSendInstance , pSessionName , rpcCallName , vecTargets , objSrc , usPriority , pServerName , objSyncType , nTimeout) \
	if (vecTargets.size() == 0 && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::RPCMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , FALSE , nTimeout, 0 , pServerName , objSyncType);\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return -1;\
	 
	
#define GEN_MSG_CALL(rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority) \
	if (vecTargets.size() == 0)\
	{\
		Assert_ReF(FALSE);\
	}\
	else\
	{ \
		Msg::ObjectMsgCall * pMsg = new(sizeof(Msg::Object)*(UINT32)(vecTargets.size()))Msg::ObjectMsgCall;  \
		\
		Msg::MsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		CUtil::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		return MsgInstance::GetInstance().SendMsg(pMsg);\
	}\
	\
	return -1;\

	class DLL_EXPORT MsgHelper
	{
	public: 		
		static BOOL GenMsgCall(RPCMsgCall & objMsgCall , BOOL bRecvRequest = FALSE , UINT64 ullTimeout = MAX_MSG_TIME_OUT , UINT64 ullMsgID = 0 , const char * pRemoteName = "" , EMSG_SYNC_TYPE objSyncType = SYNC_TYPE_NONSYNC);
		static BOOL GenMsgCall(ObjectMsgCall & objMsgCall , const char * pMsgCallName , UINT16 usPriority = 0);
		static BOOL GenMsgCall(ObjectMsgCall & objMsgCall , const char * pMsgCallName , std::vector<Object> & vtTargets , Object objSrc , UINT16 usPriority = 0);

	};

}
#endif