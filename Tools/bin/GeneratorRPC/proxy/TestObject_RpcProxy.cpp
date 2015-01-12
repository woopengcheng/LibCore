#include "GlobalRpc.h"

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject_RpcServerProxy(INT32 localid/* = 0*/ , INT32 userid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	ProxySendMsg("" , localid , userid);
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject_RpcClientProxy(INT32 localid/* = 0*/ , INT32 userid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	RPCReturn(localid , userid);
}

Msg::ObjectMsgCall * Proxy::GlobalRpc::TestObject_RpcTimeoutProxy(INT32 localid/* = 0*/ , INT32 userid/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	RPCReturnNULL;
}
