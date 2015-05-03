#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSet_RpcClient(INT32 resCode/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHSet_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::HandleHSet_RpcTimeout(INT32 userid/* = 0*/ , INT32 localid/* = 1*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "HandleHSet_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

