#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcServerProxy(UINT64 userid9/* = 0*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , UINT32 userid7/* = 0*/ , INT64 localid8/* = 0*/ , INT32 localid6/* = 0*/ , UINT16 localid4/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	ProxySendMsg("tcp://127.0.0.1:8002" , 1 , userid9 , userid1 , userid3 , userid7 , localid8 , localid6 , localid4);
	std::cout << "TestObject_RpcServerProxy" << std::endl;
	//Return();
	ReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcClientProxy(std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
 

	std::cout << "TestObject_RpcClientProxy" << std::endl;
	Return();
}

Msg::ObjectMsgCall * Msg::GlobalRpc::TestObject_RpcTimeout(UINT64 userid9/* = 0*/ , SINT8 userid1/* = 0*/ , INT16 userid3/* = 0*/ , UINT32 userid7/* = 0*/ , INT64 localid8/* = 0*/ , INT32 localid6/* = 0*/ , UINT16 localid4/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	std::cout << "TestObject_RpcTimeout" << std::endl;
	ReturnNULL;
}

