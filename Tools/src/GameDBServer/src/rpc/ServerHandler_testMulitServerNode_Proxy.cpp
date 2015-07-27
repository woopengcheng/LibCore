#include "GlobalRpc.h"
#include "ServerHandler.h"



Msg::ObjectMsgCall * Server::ServerHandler::testMulitServerNode_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8002" , 0 , dbname , value))
	{
		RPCReturn1(res);
	}


	std::cout << "testMulitServerNode_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::ServerHandler::testMulitServerNode_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc  ,LibCore_Chunk & res/* = LibCore::Chunk()*/)
{




	std::cout << "testMulitServerNode_RpcClientProxy" << std::endl;
	RPCReturn1(res);
}

Msg::ObjectMsgCall * Server::ServerHandler::testMulitServerNode_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ )
{


 	std::cout << "testMulitServerNode_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

