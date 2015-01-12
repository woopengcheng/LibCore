#include "RPCMsgCall.h" 
#include "RpcServerManager.h" 
#include "RpcInstance.h" 
#include "Chunk.h" 

namespace Proxy
{
	// static defaultParams define here. 
	static INT16 g_rpcDefaultParam_INT16 = 0;
	static INT32 g_rpcDefaultParam_INT32 = 0;
	static UNT16 g_rpcDefaultParam_UNT16 = 0;
	static UNT32 g_rpcDefaultParam_UNT32 = 0;

	class GlobalRpc : public Msg::IRpcMsgCallableObject
	{
	public:
		GlobalRpc(Msg::Object nID = Msg::DEFAULT_RPC_CALLABLE_ID , Msg::RpcManager * pRpcManager = RpcInstance::GetInstance().GetRpcServerManager())
			: Msg::IRpcMsgCallableObject(nID , pRpcManager)
		{
			Msg::Parameters objDeliverParams , objReturnParams;

			//TestObject generate default deliver and return check param here
			{
				Msg::GenMsgHelper::GenMsgParams(objDeliverParams ,g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32);
				Msg::GenMsgHelper::GenMsgParams(objReturnParams ,g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32);
				InsertDeliverParams("TestObject");
				InsertReturnParams("TestObject");
				objDeliverParams.Clear();
				objReturnParams.Clear();
			}

			//TestObject1 generate default deliver and return check param here
			{
				Msg::GenMsgHelper::GenMsgParams(objDeliverParams ,g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32);
				Msg::GenMsgHelper::GenMsgParams(objReturnParams ,g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32);
				InsertDeliverParams("TestObject1");
				InsertReturnParams("TestObject1");
				objDeliverParams.Clear();
				objReturnParams.Clear();
			}

		}
	public:
		//TestObject generate RPC func here
		Msg::ObjectMsgCall<Object> * TestObject_RpcServerProxy(g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall<Object> * TestObject_RpcClientTimeout(g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall<Object> * TestObject_RpcClientProxy(g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

		//TestObject1 generate RPC func here
		Msg::ObjectMsgCall<Object> * TestObject1_RpcServerProxy(g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall<Object> * TestObject1_RpcClientTimeout(g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));
		Msg::ObjectMsgCall<Object> * TestObject1_RpcClientProxy(g_rpcDefaultParam_INT32 , g_rpcDefaultParam_INT32, std::vector<Msg::Object> vecTargets = VECTOR_TARGETS_NULL , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID));

	};
}

#endif

