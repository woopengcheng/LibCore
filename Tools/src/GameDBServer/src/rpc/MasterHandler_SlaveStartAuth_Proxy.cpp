#include "MasterHandler.h"
#include "GameDB/inc/User.h"

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc , std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/)
{
	std_string value = std::string();

	CreateSlaveRecord(objSrc);

	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8001" , 1 , name , pwd))
	{
		Return(value);
	}


	std::cout << "SlaveStartAuth_RpcServerProxy" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc  , std_string &value/* = std::string()*/)
{
	if (value != "")
	{
		GameDB::User objUser;
		objUser.FromBson(value.c_str() , (INT32)value.length()); 
		
		SetSlaveRecordInfo(m_pRpcMsgCall->GetProxySrcID() , objUser);
	} 
	else
	{
		DelSlaveRecord(m_pRpcMsgCall->GetProxySrcID());
	}

	std::cout << "SlaveStartAuth_RpcClientProxy" << std::endl;
	Return(value);
}

Msg::ObjectMsgCall * Server::MasterHandler::SlaveStartAuth_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc , std_string &name/* = std::string()*/ , std_string & pwd/* = std::string()*/)
{

 	std::cout << "SlaveStartAuth_RpcTimeoutProxy" << std::endl;
	ReturnNULL;
}

