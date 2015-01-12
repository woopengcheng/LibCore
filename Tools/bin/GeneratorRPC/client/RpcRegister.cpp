#include "MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "RpcServerManager.h"
#include "RpcBase.h"
#include "GlobalRpc.h"

namespace Client
{
	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(GetRpcServerManager());	
		static GlobalRpc objRpc; 

		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcTimeout , &GlobalRpc::TestObject_RpcTimeout); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcClient , &GlobalRpc::TestObject_RpcClient); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject1_RpcTimeout , &GlobalRpc::TestObject1_RpcTimeout); 
		GetRpcServerManager()->RegisterFunc<GlobalRpc>(Msg::g_szTestObject1_RpcClient , &GlobalRpc::TestObject1_RpcClient); 
	}

}

