#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveRequestSync_RpcClient(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &newbackdir/* = std::string()*/ , INT32 res/* = 0*/ ) 
{


	std::cout << "SlaveRequestSync_RpcClient" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveRequestSync_RpcTimeout(Msg::VecObjects & vecTargets , Msg::Object objSrc , std_string &dbbackdir/* = std::string()*/ , std_string & dbname/* = std::string()*/ ) 
{


	std::cout << "SlaveRequestSync_RpcTimeout" << std::endl;
	RPCReturnNULL;
}

