#include "GlobalRpc.h"

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcServerProxy(std_string pwd/* = std::string()*/ , std_string name/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	ProxySendMsg("tcp://127.0.0.1:8001" , pwd , name);
	std::cout << "SlaveStartAuth_RpcServerProxy" << std::endl;
	//RPCReturn1(res);
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcClientProxy(INT32 res/* = 0*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{

	std::cout << "SlaveStartAuth_RpcClientProxy" << std::endl;
	RPCReturn1(res);
}

Msg::ObjectMsgCall * Msg::GlobalRpc::SlaveStartAuth_RpcTimeoutProxy(std_string pwd/* = std::string()*/ , std_string name/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{


 	std::cout << "SlaveStartAuth_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

