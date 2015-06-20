#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveSelectDB_RpcClient(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SlaveSelectDB_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveSelectDB_RpcTimeout(std_string dbname/* = std::string()*/, std::vector<Msg::Object> vecTargets , Msg::Object objSrc) 
{


	std::cout << "SlaveSelectDB_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

