#ifndef __client_global_rpc_h__
#define __client_global_rpc_h__
#include "MsgLib/inc/MsgCommon.h" 
#include "MsgLib/inc/IRpcMsgCallableObject.h"
#include "MsgLib/inc/Object.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgLib/inc/RpcServerManager.h"
#include "RpcInstance.h"
#include "Common/Chunk.h"

namespace Msg
{  
// 	static char		    g_rpcDefaultParam_char = '0';
// 	static INT16		g_rpcDefaultParam_INT16 = 0;
// 	static UINT16		g_rpcDefaultParam_UINT16 = 0;
// 	static INT32		g_rpcDefaultParam_INT32 =  0;
// 	static UINT32		g_rpcDefaultParam_UINT32 = 0;
// 	static ConstCharPtr g_rpcDefaultParam_ConstCharPtr = NULL;
// 	static LibCore::Chunk	g_rpcDefaultParam_Chunk = LibCore::Chunk();  

	class  GlobalRpc : public Msg::IRpcMsgCallableObject
	{
	public:
		GlobalRpc(Msg::Object nID , Msg::RpcManager * pRpcManager )
			: Msg::IRpcMsgCallableObject(nID , pRpcManager)    
		{ 
			Msg::Parameters objDeliverParams , objReturnParams;

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
		//5 Testobject define here
		Msg::ObjectMsgCall * TestObject_RpcTimeout(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc);
		Msg::ObjectMsgCall * TestObject_RpcClient(char p1 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc);

	}; 

	extern GlobalRpc * g_pGlobalRpc;
} 


#endif