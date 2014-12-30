#include "GlobalRpc.h"

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject_RpcServerProxy(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7  , std::vector<Msg::Object> vecTargets , Msg::Object objSrc)
{   
	std::cout << "TestObject_RpcServerProxy" << std::endl; 

	ProxySendMsg("TCP://127.0.0.1:8002" , p1 , p2 , p3 , p4 , p5 , p6 , p7);
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject_RpcClientProxy( char p1 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc )
{ 
	std::cout << "TestObject_RpcClientProxy" << std::endl; 
	RPCReturn(p1);
}

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject_RpcTimeoutProxy( char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7  , std::vector<Msg::Object> vecTargets , Msg::Object objSrc)
{ 
	std::cout << "TestObject_RpcTimeoutProxy" << std::endl; 

	RPCReturnNULL;
}
 