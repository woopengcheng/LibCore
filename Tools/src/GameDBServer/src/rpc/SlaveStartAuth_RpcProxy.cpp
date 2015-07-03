#include "GlobalRpc.h"
#include "MasterHandler.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcServerProxy(std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{
	std_string value = std::string();


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8001" , name , pwd))
	{
		RPCReturn1(value);
	}


	std::cout << "SlaveStartAuth_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcClientProxy(std_string &value/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
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

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcTimeoutProxy(std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/, std::vector<Msg::Object> vecTargets  , Msg::Object objSrc )
{

 	std::cout << "SlaveStartAuth_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

