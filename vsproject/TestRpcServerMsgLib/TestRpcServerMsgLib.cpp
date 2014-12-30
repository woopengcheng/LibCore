// InnerMsgLib.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "InnerMsg.h"
#include "ObjectMsgCall.h"
#include "TimerHelp.h"
#include "ICallableObject.h"
#include "MsgProxy.h"
#include "MsgNameDefine.h" 
#include "Chunk.h"
#include "RpcServerManager.h"
#include "TestObject.h"
#include "Rpc.h"
#include "RpcInterface.h"


static BOOL  local_call_TestObject(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<Object> vecTargets , Object objSrc , UINT16 usPriority = 0)
{
	if (vecTargets.size() == 0)
	{
		return FALSE;
	}
	else
	{ 
		Msg::RPCMsgCall * pMsg = new(sizeof(Object)*vecTargets.size())Msg::RPCMsgCall;  

		Msg::GenMsgHelper::GenMsgCall(*pMsg , FALSE , 10 , 0 , "TCP://127.0.0.1:8001");
		Msg::GenMsgHelper::GenMsgCall(*pMsg , 0 , Msg::g_szTestObject_RpcCall , vecTargets , objSrc , usPriority);
		Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);

		Msg::RpcInterface::GetInstance().SendMsg("accsrv" , pMsg);
	}

	return TRUE;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Log::Init("RpcServer");
	Net::InitNet(); 
	Msg::RpcInterface<MSG_ID>::GetInstance().Init("RPCServerConfigs.xml"); 

// 	Msg::Rpc<MSG_ID> objRpc(Msg::RpcInterface<MSG_ID>::GetInstance().GetRpcServerManager()); 
// 	Msg::RpcInterface<MSG_ID>::GetInstance().GetRpcServerManager()->AddCallableObject(&objRpc); 
// 	Msg::RpcInterface<MSG_ID>::GetInstance().GetRpcServerManager()->RegisterFunc<MSG_ID , Msg::Rpc<MSG_ID>>(Msg::g_szTestObject_RpcCall , &Msg::Rpc<MSG_ID>::TestObject_RpcClient); 
// 	Msg::RpcInterface<MSG_ID>::GetInstance().GetRpcServerManager()->RegisterFunc<MSG_ID , Msg::Rpc<MSG_ID>>(Msg::g_szTestObject_RpcTimeout , &Msg::Rpc<MSG_ID>::TestObject_RpcTimeout); 

	TestObject  ObjTestObject;

	Msg::RpcInterface<MSG_ID>::GetInstance().GetRpcServerManager()->AddCallableObject(&ObjTestObject);
	Msg::RpcInterface<MSG_ID>::GetInstance().GetRpcServerManager()->RegisterFunc<MSG_ID , Msg::Rpc<MSG_ID>>(Msg::g_szTestObject_RpcCall , &Msg::Rpc<MSG_ID>::TestObject_RpcServer); 


// 	std::vector<MSG_ID> targets;
// 	targets.push_back(1);   
// 	local_call_TestObject<MSG_ID>('a' , 1 , 2 , 3 , 4 , "HelloWorld." , Msg::Chunk("Foobar" , sizeof("Foobar")) , targets , 1 , 1); 

	while (1)
	{
		Msg::RpcInterface<MSG_ID>::GetInstance().Update();
		Timer::TimerHelper::sleep(1); 
	}

	Msg::RpcInterface<MSG_ID>::GetInstance().Cleanup(); 
	Net::CleanNet();
	Log::Cleanup();
	return 0;
}

