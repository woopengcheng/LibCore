#include "MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "IRpcMsgCallableObject.h"
#include "RpcServerManager.h"
#include "RpcBase.h"
#include "GlobalRpc.h"
#include "TestObject.h"

namespace Server
{    
	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(GetRpcServerManager());	

		GetRpcServerManager()->RegisterFunc<TestObject>(Msg::g_szTestObject_RpcServer , &TestObject::TestObject_RpcServer);  
 	}
	  
}  