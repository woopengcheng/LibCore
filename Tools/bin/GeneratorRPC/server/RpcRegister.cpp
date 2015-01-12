#include "MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "RpcServerManager.h"
#include "RpcBase.h"
#include "GlobalRpc.h"
#include "TestObject.h"
#include "TestObject1.h"

namespace Server
{
	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(GetRpcServerManager());	
		static GlobalRpc objRpc; 

		GetRpcServerManager()->RegisterFunc<TestObject >(Msg::g_szTestObject_RpcServer , &TestObject::TestObject_RpcServer); 
		GetRpcServerManager()->RegisterFunc<TestObject1 >(Msg::g_szTestObject1_RpcServer , &TestObject1::TestObject1_RpcServer); 
	}

}

