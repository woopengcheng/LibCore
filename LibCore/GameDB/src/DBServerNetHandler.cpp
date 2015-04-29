#include "GameDB/inc/DBServerNetHandler.h" 

namespace GameDB
{


	DBServerNetHandler::DBServerNetHandler(Msg::RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession)
		: Msg::RemoteRpcServer(pRpcManager , pNetReactor , pSession)  
	{ 
	} 


	DBServerNetHandler::~DBServerNetHandler()
	{  
	}  

// 	INT32 DBServerNetHandler::HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
// 	{
// 		switch(unMsgID)
// 		{
// 		case DEFAULT_RPC_PING_ID:
// 			{
// 				return Msg::RemoteRpcServer::HandleMsg(pSession , unMsgID , pBuffer , unLength );
// 			}break;
// 		case DEFAULT_RPC_MSG_ID:
// 			{
// 
// 			}
// 		default:
// 			break;
// 		}
// 
// 		return ERR_SUCCESS;
// 	}

}
