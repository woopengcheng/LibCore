#include "GlobalRpc.h"

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHGet_RpcClient(Net::ISession * pSession, Msg::Object objSrc , std_string & value/* = std::string()*/) 
{
	gDebugStream("HGet value:" << value);

	std::cout << "HandleHGet_RpcClient value:" << value << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Client::GlobalRpc::HandleHGet_RpcTimeout(Net::ISession * pSession, Msg::Object objSrc , std_string & table/* = std::string()*/ , std_string & key/* = std::string()*/) 
{


	std::cout << "HandleHGet_RpcTimeout" << std::endl;
	ReturnNULL;
}
