#include "MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "RpcServerManager.h"
#include "RpcBase.h"
#include "GlobalRpc.h"

namespace Proxy
{
	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(GetRpcServerManager());	
		static GlobalRpc objRpc; 

				GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcServerProxy , &GlobalRpc::TestObject_RpcServerProxy); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcClientProxy , &GlobalRpc::TestObject_RpcClientProxy); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcTimeoutProxy , &GlobalRpc::TestObject_RpcTimeoutProxy); 
				GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject1_RpcServerProxy , &GlobalRpc::TestObject1_RpcServerProxy); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject1_RpcClientProxy , &GlobalRpc::TestObject1_RpcClientProxy); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject1_RpcTimeoutProxy , &GlobalRpc::TestObject1_RpcTimeoutProxy); 
	}

}

