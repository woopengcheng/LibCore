#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "Common/Chunk.h"
#include "GlobalRpc.h"
#include "MsgNameDefine.h"
#include "RpcInstance.h"

namespace Client
{
	//5 defaultParams define here.
	static UINT64 g_rpcDefaultParam_UINT64 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static double g_rpcDefaultParam_double = 0.0f;
	static float g_rpcDefaultParam_float = 0.0f;
	static UINT8 g_rpcDefaultParam_UINT8 = 0;
	static UINT16 g_rpcDefaultParam_UINT16 = 0;
	static INT64 g_rpcDefaultParam_INT64 = 0;
	static SINT8 g_rpcDefaultParam_SINT8 = 0;
	static UINT32 g_rpcDefaultParam_UINT32 = 0;
	static std_string g_rpcDefaultParam_std_string = std::string();
	static LibCore_Chunk g_rpcDefaultParam_LibCore_Chunk = LibCore::Chunk();

	void RpcInstance::OnRegisterRpcs( void )
	{
		Assert(m_pRpcServerManager && Msg::g_pRpcCheckParams);	
		Msg::GlobalRpc * g_pGlobalRpc  = new Msg::GlobalRpc( Msg::DEFAULT_RPC_CALLABLE_ID , m_pRpcServerManager); 

		Msg::Parameters objDeliverParams , objReturnParams;
		//5 TestObject1 generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_SINT8 , g_rpcDefaultParam_UINT8 , g_rpcDefaultParam_INT16 , g_rpcDefaultParam_UINT16 , g_rpcDefaultParam_double , g_rpcDefaultParam_float , g_rpcDefaultParam_std_string , g_rpcDefaultParam_LibCore_Chunk);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("TestObject1", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("TestObject1", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szTestObject1_RpcTimeout , &Msg::GlobalRpc::TestObject1_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szTestObject1_RpcClient , &Msg::GlobalRpc::TestObject1_RpcClient); 
		}

		//5 TestObject generate default deliver and return check param here
		{
			Msg::GenMsgHelper::GenMsgParams(objDeliverParams  , g_rpcDefaultParam_UINT64 , g_rpcDefaultParam_SINT8 , g_rpcDefaultParam_INT16 , g_rpcDefaultParam_UINT32 , g_rpcDefaultParam_INT64 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_UINT16);
			Msg::GenMsgHelper::GenMsgParams(objReturnParams );
			Msg::g_pRpcCheckParams->InsertDeliverParams("TestObject", objDeliverParams);
			Msg::g_pRpcCheckParams->InsertReturnParams("TestObject", objReturnParams);
			objDeliverParams.Clear();
			objReturnParams.Clear();
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szTestObject_RpcTimeout , &Msg::GlobalRpc::TestObject_RpcTimeout); 
			m_pRpcServerManager->RegisterFunc<Msg::GlobalRpc>(Msg::g_szTestObject_RpcClient , &Msg::GlobalRpc::TestObject_RpcClient); 
		}

	}

}

