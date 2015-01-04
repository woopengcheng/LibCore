#ifndef __msg_rpc_call_funcs_h__
#define __msg_rpc_call_funcs_h__

#include "stdafx.h" 
#include "RpcMsgHelper.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"

namespace Client
{ 

	static BOOL  local_call_TestObject(const char * pSessionName , char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0)
	{ 
		const char * pServerName = RpcInstance::GetInstance().GetServerName();
		GEN_RPC_CALL(pSessionName , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority , pServerName);
	}
}


#endif