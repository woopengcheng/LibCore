#include "GlobalRpc.h" 
#include "TestObject.h"

Msg::ObjectMsgCall * Server::TestObject::TestObject_RpcServer( char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc)
{ 
	std::cout << "TestObject_RpcServer" << std::endl; 
	RPCReturn(p1);
}
