#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::TestObject1_RpcClient(INT32 localid/* = 0*/ , INT32 userid/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc 
{


	RPCReturn(localid , userid);
}

Msg::ObjectMsgCall * Client::GlobalRpc::TestObject1_RpcTimeout(INT32 localid/* = 0*/ , INT32 userid/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	RPCReturnNULL;
}

