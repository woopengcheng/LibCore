#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcServerProxy(std::vector<Msg::Object> vecTargets  , Msg::Object objSrc , std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/)
{
	std_string value = std::string();


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8001" , name , pwd))
	{
		RPCReturn1(value);
	}


	std::cout << "SlaveStartAuth_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcClientProxy(std::vector<Msg::Object> vecTargets  , Msg::Object objSrc  , std_string &value/* = std::string()*/)
{

	if (value != "")
	{
		GameDB::User objUser;
		objUser.FromBson(value.c_str() , value.length()); 

		m_pAuthInfo = new GameDB::UserAuth(objUser); 
	} 

	std::cout << "SlaveStartAuth_RpcClientProxy" << std::endl;
	RPCReturn1(value);
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcTimeoutProxy(std::vector<Msg::Object> vecTargets  , Msg::Object objSrc , std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/)
{

 	std::cout << "SlaveStartAuth_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

