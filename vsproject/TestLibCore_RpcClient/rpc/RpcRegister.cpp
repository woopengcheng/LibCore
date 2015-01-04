#include "MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "IRpcMsgCallableObject.h"
#include "RpcServerManager.h"
#include "RpcBase.h"
#include "GlobalRpc.h"
 
namespace Client
{    
	void RpcInstance::OnRegisterRpcs( void )
	{ 
		Assert(m_pRpcServerManager); 
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , Client::RpcInstance::GetInstance().GetRpcServerManager());
 
		m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szTestObject_RpcTimeout , &Msg::GlobalRpc::TestObject_RpcTimeout); 
		m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szTestObject_RpcClient , &Msg::GlobalRpc::TestObject_RpcClient); 

	}
	  
}  