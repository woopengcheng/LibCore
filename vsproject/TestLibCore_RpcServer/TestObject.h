#ifndef __test_client_object_h__
#define __test_client_object_h__

#include "stdafx.h"  
#include "MsgNameDefine.h"  
#include "IRpcMsgCallableObject.h"
#include "RpcServerManager.h"
#include "RpcInstance.h"
#include "Object.h"
#include "RpcDefines.h" 

namespace Server
{  
	class TestObject : public Msg::IRpcMsgCallableObject
	{ 
		RPC_DEFINE_TestObject;
	public:
		TestObject()
			: Msg::IRpcMsgCallableObject(Msg::Object(1) , RpcInstance::GetInstance().GetRpcServerManager()){}
	public:
		virtual INT32 Update(){ return 0; } 

		
	protected:
	private:
	}; 
}

#endif