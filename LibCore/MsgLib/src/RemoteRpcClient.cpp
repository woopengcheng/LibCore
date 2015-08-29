#include "MsgLib/inc/RemoteRpcClient.h"
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "Marshal/inc/CStream.h"

namespace Msg
{  

	RemoteRpcClient::RemoteRpcClient( RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor , Net::ISession * pSession )
		: Net::NetHandlerClient(pNetReactor , pSession) 
		, m_pRpcManager(pRpcManager)
	{

	}

	RemoteRpcClient::~RemoteRpcClient()
	{
		Cleanup();
		SAFE_DELETE(m_pSession);
	}

	CErrno RemoteRpcClient::Cleanup( void )
	{
		return Net::NetHandlerClient::Cleanup();
	}  
	 
	CErrno RemoteRpcClient::Update( void )
	{
		return Net::NetHandlerClient::Update();
	}

	CErrno RemoteRpcClient::OnReconnect( void )
	{   
		INT32 nResult;
		if (m_pSession && m_pSession->IsClosed())
		{
			nResult = Connect(m_pSession->GetAddress() , m_pSession->GetPort());
			if (!nResult)
			{ 
				m_pSession->SetNetState(Net::NET_STATE_CONNECTING);
				m_pSession->SetClosed(FALSE);

				Net::NetHandlerTransitPtr pHandler = m_pRpcManager->GetNetHandlerBySessionID(m_pSession->GetSessionID());
				m_pNetReactor->AddNetHandler(pHandler);
				return  CErrno(CErrno::ERR_SUCCESS);  
			} 
		}
		 
		return  CErrno(CErrno::ERR_FAILURE);  
	} 

	CErrno RemoteRpcClient::OnClose( void )
	{  
		if(GetSession() && GetSession()->GetSessionID() != -1 && m_pRpcManager)
		{  
			m_pRpcManager->CloseNet(GetSession()->GetRemoteName()); 
		} 
		 
		return NetHandlerClient::OnClose(); 
	} 

	CErrno RemoteRpcClient::HandleMsg( Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{ 
		switch(unMsgID)
		{
		case DEFAULT_RPC_PING_ID:
			{
			}break;
		case DEFAULT_RPC_MSG_ID:
			{
				Assert_ReF(pBuffer && m_pRpcManager);  
				CUtil::CStream cs(pBuffer , unLength);
				UINT32 unTargetsCount = (UINT32)*pBuffer;
				cs >> unTargetsCount;

				RPCMsgCall * pMsg = new(unTargetsCount * sizeof(Object))RPCMsgCall;  
//				pMsg->UnSerialization(pBuffer);
				pMsg->unMarshal(cs);

				return m_pRpcManager->HandleMsg(pSession , pMsg);  
			}
		default:
			break;
		}

		return CErrno::Failure();
	} 

}