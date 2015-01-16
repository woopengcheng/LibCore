#ifndef __client_global_rpc_h__
#define __client_global_rpc_h__
#include "MsgCommon.h" 
#include "IRpcMsgCallableObject.h"
#include "Object.h"
#include "RPCMsgCall.h"
#include "RpcServerManager.h"
#include "RpcInstance.h"
#include "Chunk.h"

namespace Server
{  
// 	static char		    g_rpcDefaultParam_char = '0';
// 	static INT16		g_rpcDefaultParam_INT16 = 0;
// 	static UINT16		g_rpcDefaultParam_UINT16 = 0;
// 	static INT32		g_rpcDefaultParam_INT32 =  0;
// 	static UINT32		g_rpcDefaultParam_UINT32 = 0;
// 	static ConstCharPtr g_rpcDefaultParam_ConstCharPtr = NULL;
// 	static LibCore::Chunk	g_rpcDefaultParam_Chunk = LibCore::Chunk();  

	class GlobalRpc : public Msg::IRpcMsgCallableObject
	{
	public:
		GlobalRpc(Msg::Object nID = Msg::DEFAULT_RPC_CALLABLE_ID , Msg::RpcManager * pRpcManager = RpcInstance::GetInstance().GetRpcServerManager())
			: Msg::IRpcMsgCallableObject(nID , pRpcManager)    
		{ 
// 			Msg::Parameters objDeliverParams , objReturnParams;
// 
// 			//5 TestObject deliver
// 			{ 
// 				Msg::GenMsgHelper::GenMsgParams(objDeliverParams , g_rpcDefaultParam_char , g_rpcDefaultParam_INT16 , g_rpcDefaultParam_UINT16 , g_rpcDefaultParam_INT32 , g_rpcDefaultParam_UINT32 , g_rpcDefaultParam_ConstCharPtr , g_rpcDefaultParam_Chunk);
// 				Msg::GenMsgHelper::GenMsgParams(objReturnParams , g_rpcDefaultParam_char );  
// 				InsertDeliverParams("TestObject" , objDeliverParams);
// 				InsertReturnParams("TestObject" , objReturnParams);
// 				objDeliverParams.Clear();
// 				objReturnParams.Clear();
// 			}
		} 
	public:  
	}; 
} 


#endif