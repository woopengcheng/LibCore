#include "GlobalRpc.h"


Msg::ObjectMsgCall * Msg::GlobalRpc::SyncMasterHandler_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 res/* = 0*/)
{


	std::cout << "SyncMasterHandler_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SyncMasterHandler_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc , INT32 id/* = 0*/)
{


	std::cout << "SyncMasterHandler_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

