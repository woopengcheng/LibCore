#ifndef __msg_rpc_msg_helper_h__
#define __msg_rpc_msg_helper_h__
#include "MsgCommon.h" 
#include "RPCMsgCall.h"  
#include "Chunk.h"
#include "RpcServerManager.h"  
#include "GenMsgHelper.h"

namespace Msg
{  

#define GEN_RPC_CALL(pSessionName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority , pServerName) \
	if (vecTargets.size() == 0 && !pSessionName && !pServerName)\
	{\
		Assert_Re0(FALSE);\
	}\
	else\
	{ \
		Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  \
		\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , pServerName);\
		Msg::GenMsgHelper::GenMsgCall(*pMsg , Msg::g_szTestObject_RpcCall , vecTargets , objSrc , usPriority);\
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);\
		\
		return RpcInstance::GetInstance().SendMsg(pSessionName , pMsg );\
	}\
	\
	return FALSE;\
	 


}
#endif