#ifndef __test_proxy_object_h__
#define __test_proxy_object_h__

#include "stdafx.h"  
#include "MsgNameDefine.h"  
#include "IRpcMsgCallableObject.h"
#include "RpcServerManager.h"
#include "RpcInstance.h"
#include "Object.h"
 

namespace Proxy
{  
	class TestObject : public Msg::IRpcMsgCallableObject
	{ 
	public:
		TestObject()
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , RpcInstance::GetInstance().GetRpcServerManager()){}
	public:
		virtual INT32 Update(){ return 0; } 
	protected:
	private:
	};

	static BOOL  local_call_TestObject(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0)
	{
		if (vecTargets.size() == 0)
		{
			return FALSE;
		}
		else
		{ 
			Msg::RPCMsgCall * pMsg = new(sizeof(Msg::Object)*vecTargets.size())Msg::RPCMsgCall;  
			
			Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , "tcp://127.0.0.1:8001");
			Msg::GenMsgHelper::GenMsgCall(*pMsg , Msg::g_szTestObject_RpcCall , vecTargets , objSrc , usPriority);
			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);

			RpcInstance::GetInstance().SendMsg("srv" , pMsg);
		}

		return TRUE;
	}
}


#endif