#include "MasterHandler.h"
#include "GameDB/inc/RemoteNodeDefine.h"

Msg::ObjectMsgCall * Server::MasterHandler::testMulitServerNode_RpcServerProxy(INT32 nSessionID, Msg::Object objSrc , std_string & dbname/* = std::string()*/ , CUtilChunk & value/* = CUtil::Chunk()*/ , int value2/* = 0*/ , unsigned int value22/* = 0*/ , char valChar/* = char(0)*/)
{
	CUtilChunk res = CUtil::Chunk();


	if(-1 == ProxySendMsg(g_strGameDBNodes[NETNODE_DBSERVER_TO_DBCLIENT] , 0 , dbname , value , value2 , value22 , valChar))
	{
		Return(res);
	}


	std::cout << "testMulitServerNode_RpcServerProxy" << std::endl;
	ReturnNULL;
}

Msg::ObjectMsgCall * Server::MasterHandler::testMulitServerNode_RpcClientProxy(INT32 nSessionID, Msg::Object objSrc  ,CUtilChunk & res/* = CUtil::Chunk()*/)
{




	std::cout << "testMulitServerNode_RpcClientProxy" << std::endl;
	Return(res);
}

Msg::ObjectMsgCall * Server::MasterHandler::testMulitServerNode_RpcTimeoutProxy(INT32 nSessionID, Msg::Object objSrc,std_string & dbname/* = std::string()*/ , CUtilChunk & value/* = CUtil::Chunk()*/ , int value2/* = 0*/ , unsigned int value22/* = 0*/ , char valChar/* = char(0)*/ )
{


 	std::cout << "testMulitServerNode_RpcTimeoutProxy" << std::endl;
	ReturnNULL;
}

