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

	INT32 DBServerNetHandler::HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		switch(unMsgID)
		{
		case DEFAULT_RPC_PING_ID:
			{
				return Msg::RemoteRpcServer::HandleMsg(pSession , unMsgID , pBuffer , unLength );
			}break;
		case DEFAULT_RPC_MSG_ID:
			{
// 				Assert_ReF1(pBuffer && m_pRpcManager);  
// 
// 				LibCore::CStream cs(pBuffer , unLength);
// 				UINT32 unTargetsCount = 0;
// 				cs >> LibCore::Marshal::Begin >> unTargetsCount >> LibCore::Marshal::Rollback;
// 
// 				RPCMsgCall * pMsg = new(unTargetsCount * sizeof(Object))RPCMsgCall;  
// 				pMsg->unMarshal(cs);
// 
// 				pMsg->SetSessionName(pMsg->m_szRemoteName);
// 				memcpy(pMsg->m_szRemoteName , m_pRpcManager->GetRpcInterface()->GetServerName() , strlen( m_pRpcManager->GetRpcInterface()->GetServerName()) + 1);
// 
// 				return m_pRpcManager->HandleMsg(pSession , pMsg); 
			}
		default:
			break;
		}

		return ERR_SUCCESS;
	}

}
