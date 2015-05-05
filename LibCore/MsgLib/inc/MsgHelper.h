#ifndef __msg_rpc_msg_helper_h__
#define __msg_rpc_msg_helper_h__
#include "MsgLib/inc/MsgCommon.h" 
#include "MsgLib/inc/RPCMsgCall.h"  
#include "Common/Chunk.h"
#include "MsgLib/inc/RpcServerManager.h"  
#include "MsgLib/inc/GenMsgHelper.h"

namespace Msg
{  
	
#define GEN_RPC_CALL_8(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8 ,vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_7(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_6(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 );\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_5(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , p5 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_4(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , p4 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_3(pSendInstance , pSessionName , rpcCallName , p1 , p2 , p3 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_2(pSendInstance , pSessionName , rpcCallName , p1 , p2 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_1(pSendInstance , pSessionName , rpcCallName , p1 , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
#define GEN_RPC_CALL_0(pSendInstance , pSessionName , rpcCallName , vecTargets , objSrc , usPriority , pServerName , objSyncType) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName , objSyncType);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams);\
		\
		return pSendInstance->SendMsg(pSessionName , pMsg );\
	}\
	\
	return ERR_SUCCESS;\
	 
	
#define GEN_MSG_CALL(rpcCallName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority) \
	if (vecTargets.size() == 0)\
	{\
		Assert_ReF1(FALSE);\
	}\
	else\
	{ \
		Msg::ObjectMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::ObjectMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , rpcCallName , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		MsgInstance::GetInstance().SendMsg(pMsg);\
	}\
	\
	return ERR_SUCCESS;\

}
#endif