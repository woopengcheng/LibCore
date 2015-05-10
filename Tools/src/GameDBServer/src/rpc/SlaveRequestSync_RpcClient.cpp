#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveRequestSync_RpcClient(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SlaveRequestSync_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveRequestSync_RpcTimeout(std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SlaveRequestSync_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

