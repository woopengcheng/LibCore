#include "MsgLib/inc/RemoteRpcClient.h"
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "Marshal/CStream.h"

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

	INT32 RemoteRpcClient::Cleanup( void )
	{
		return Net::NetHandlerClient::Cleanup();
	}  
	 
	INT32 RemoteRpcClient::Update( void )
	{
		return Net::NetHandlerClient::Update();
	}

	INT32 RemoteRpcClient::OnReconnect( void )
	{   
		int nResult = -1;
		if (m_pSession && m_pSession->IsClosed())
		{
			nResult = Connect(m_pSession->GetAddress() , m_pSession->GetPort());
			if (!nResult)
			{ 
				m_pSession->SetNetState(Net::NET_STATE_CONNECTING);
				m_pSession->SetClosed(FALSE);

				Net::NetHandlerTransitPtr pHandler = m_pRpcManager->GetNetHandlerBySessionID(m_pSession->GetSessionID());
				m_pNetReactor->AddNetHandler(pHandler);
			} 
		}

		return  nResult;  
	} 

	INT32 RemoteRpcClient::OnClose( void )
	{  
		if(GetSession() && GetSession()->GetSessionID() != -1 && m_pRpcManager)
		{  
			m_pRpcManager->CloseNet(GetSession()->GetRemoteName()); 
		} 
		 
		return NetHandlerClient::OnClose(); 
	} 

	INT32 RemoteRpcClient::HandleMsg( Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{ 
		switch(unMsgID)
		{
		case DEFAULT_RPC_PING_ID:
			{
			}break;
		case DEFAULT_RPC_MSG_ID:
			{
				Assert_ReF1(pBuffer && m_pRpcManager);  
				LibCore::CStream cs(pBuffer , unLength);
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

		return ERR_FAILURE;
	} 

}