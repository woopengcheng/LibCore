#include "MsgLib/inc/MsgCommon.h"
#include "RpcInstance.h"
#include "MsgNameDefine.h"
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcBase.h"
#include "GlobalRpc.h"
#include "MsgLib/inc/RpcCheckParams.h"

namespace Proxy
{    
	static char		    g_rpcDefaultParam_char = '0';
	static INT16		g_rpcDefaultParam_INT16 = 0;
	static UINT16		g_rpcDefaultParam_UINT16 = 0;
	static INT32		g_rpcDefaultParam_INT32 =  0;
	static UINT32		g_rpcDefaultParam_UINT32 = 0;
	static ConstCharPtr g_rpcDefaultParam_ConstCharPtr = NULL;
	static LibCore::Chunk	g_rpcDefaultParam_Chunk = LibCore::Chunk();

	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager);	
		static GlobalRpc objRpc; 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 TestObject deliver
		{ 
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams , g_rpcDefaultParam_char , g_rpcDefaultParam_INT16 , g_rpcDefaultParam_UINT16 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_UINT32 , g_rpcDefaultParam_ConstCharPtr , g_rpcDefaultParam_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams , g_rpcDefaultParam_char );  
			Msg::g_pRpcCheckParams->InsertDeliverParams("TestObject" , objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("TestObject" , objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear(); 

			m_pRpcServerManager->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcServerProxy , &GlobalRpc::TestObject_RpcServerProxy);  
			m_pRpcServerManager->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcClientProxy , &GlobalRpc::TestObject_RpcClientProxy); 
			m_pRpcServerManager->RegisterFunc<GlobalRpc>(Msg::g_szTestObject_RpcTimeout , &GlobalRpc::TestObject_RpcTimeoutProxy);   
		}
	}
	  
}  