#ifndef __test_client_object_h__
#define __test_client_object_h__

#include "stdafx.h" 
#include "RPCMsgCall.h" 
#include "MsgNameDefine.h" 
#include "Chunk.h"
#include "RpcServerManager.h"
#include "GenMsgHelper.h"
#include "RpcInstance.h"

namespace Client
{ 
	
	static BOOL  local_call_TestObject(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0)
	{
		if (vecTargets.size() == 0)
		{
			return FALSE;
		}
		else
		{ 
			Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  

			Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , RpcInstance::GetInstance().GetServerName());
			Msg::GenMsgHelper::GenMsgCall(*pMsg , Msg::g_szTestObject_RpcCall , vecTargets , objSrc , usPriority);
			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);

			return RpcInstance::GetInstance().SendMsg("tcp://127.0.0.1:8002" , pMsg );
		}

		return FALSE;
	}
}


#endif