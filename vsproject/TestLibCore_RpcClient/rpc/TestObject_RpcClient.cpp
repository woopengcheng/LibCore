#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcClient( char p1 , std::vector<Msg::Object> vecTargets ,Msg:: Object objSrc )
{   
// 	std::cout << "TestObject_RpcClient" << std::endl; 
	return NULL;
}


Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcTimeout( char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7  , std::vector<Msg::Object> vecTargets , Msg::Object objSrc)
{ 
	std::cout << "TestObject_RpcTimeout" << std::endl; 
	return NULL;
}