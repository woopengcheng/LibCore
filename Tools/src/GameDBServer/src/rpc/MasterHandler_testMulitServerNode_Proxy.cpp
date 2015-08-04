#include "GlobalRpc.h"
#include "MasterHandler.h"



Msg::ObjectMsgCall * Server::MasterHandler::testMulitServerNode_RpcServerProxy(Net::ISession * pSession , Msg::Object objSrc , std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , int value2/* = 0*/ , unsigned int value22/* = 0*/ , char valChar/* = char(0)*/)
{
	LibCore_Chunk res = LibCore::Chunk();


	if(ERR_FAILURE == ProxySendMsg("tcp://127.0.0.1:8002" , 0 , dbname , value , value2 , value22 , valChar))
	{
		Return(res);
	}


	std::cout << "testMulitServerNode_RpcServerProxy" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::testMulitServerNode_RpcClientProxy(Net::ISession * pSession , Msg::Object objSrc  ,LibCore_Chunk & res/* = LibCore::Chunk()*/)
{




	std::cout << "testMulitServerNode_RpcClientProxy" << std::endl;
	Return(res);
}

Msg::ObjectMsgCall * Server::MasterHandler::testMulitServerNode_RpcTimeoutProxy(Net::ISession * pSession , Msg::Object objSrc,std_string & dbname/* = std::string()*/ , LibCore_Chunk & value/* = LibCore::Chunk()*/ , int value2/* = 0*/ , unsigned int value22/* = 0*/ , char valChar/* = char(0)*/ )
{


 	std::cout << "testMulitServerNode_RpcTimeoutProxy" << std::endl;
	ReturnNULL;
}

