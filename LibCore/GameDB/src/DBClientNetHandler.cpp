#include "GameDB/inc/DBClientNetHandler.h" 

namespace GameDB
{

	DBClientNetHandler::DBClientNetHandler( Msg::RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor , Net::ISession * pSession)
		: Msg::RemoteRpcClient(pRpcManager , pNetReactor , pSession)   
	{

	}

	DBClientNetHandler::~DBClientNetHandler()
	{ 
	} 

// 	INT32 DBClientNetHandler::HandleMsg( Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
// 	{ 
// 		switch(unMsgID)
// 		{
// 		case 0:
// 			{
// 				std::cout << pBuffer << std::endl;
// 			}break; 
// 		default:
// 			break;
// 		}
// 
// 		return ERR_FAILURE;
// 	} 

}
