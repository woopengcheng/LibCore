#include "MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "IRpcMsgCallableObject.h"
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
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcTimeout , &GlobalRpc::TestObject_RpcTimeoutProxy);   
	}
	  
}  