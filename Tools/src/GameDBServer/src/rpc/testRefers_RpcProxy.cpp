#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::testRefers_RpcServerProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  ,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8002" , 0 , dbname , value))
	{
		RPCReturn1(res);
	}


	std::cout << "testRefers_RpcServerProxy" << std::endl;
	RPCReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::testRefers_RpcClientProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc  ,LibCore_Chunk & res/* = LibCore::Chunk()*/)
{




	std::cout << "testRefers_RpcClientProxy" << std::endl;
	RPCReturn1(res);
}

Msg::ObjectMsgCall * Server::MasterHandler::testRefers_RpcTimeoutProxy(Msg::VecObjects & vecTargets  , Msg::Object objSrc,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ )
{


 	std::cout << "testRefers_RpcTimeoutProxy" << std::endl;
	RPCReturnNULL;
}

