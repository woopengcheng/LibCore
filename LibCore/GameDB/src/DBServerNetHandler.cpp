#include "GameDB/inc/DBServerNetHandler.h" 
#include "MsgLib/inc/RpcManager.h"
#include "NetLib/inc/NetHelper.h"
#include "MsgLib/inc/RpcInterface.h"

namespace GameDB
{


	DBServerNetHandler::DBServerNetHandler(Msg::RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession)
		: Msg::RemoteRpcServer(pRpcManager , pNetReactor , pSession)  
	{ 
	} 


	DBServerNetHandler::~DBServerNetHandler()
	{  
	}  

	INT32 DBServerNetHandler::UpdatePing(void)
	{
		if (m_ullLastRecvPing == 0)
		{
			SetLastRecvPingTime();
		}

		std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(m_pRpcManager->GetRpcInterface()->GetServerType()  , m_pSession->GetAddress() , m_pSession->GetPort()); 

		if (m_pSession->IsClosed() && strcmp(strRemoteRPCName.c_str() , m_pSession->GetRemoteName()) != 0)
		{
			gErrorStream ("重复新建的.应删除" << m_pSession->GetRemoteName()); 

			GetSession()->SetClosed(TRUE);
			GetSession()->SetNetState(Net::NET_STATE_LOSTED);
			return ERR_FAILURE;
		}
		return ERR_SUCCESS;
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
