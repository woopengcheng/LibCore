#include "GlobalRpc.h"

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject1_RpcServerProxy(INT32 userid/* = 0*/ , INT32 localid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	ProxySendMsg("" , userid , localid);
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject1_RpcClientProxy(INT32 userid/* = 0*/ , INT32 localid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	RPCReturn(userid , localid);
}

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject1_RpcTimeoutProxy(INT32 userid/* = 0*/ , INT32 localid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	RPCReturnNULL;
}

