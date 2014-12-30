#include "RemoteRpcServer.h"
#include "NetHelper.h"
#include "RpcManager.h"
#include "RpcInterface.h"
#include "RPCMsgCall.h"

namespace Msg
{

	RemoteRpcServer::RemoteRpcServer( RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor, Net::ISession * pSession )
		: Net::NetHandlerServer(pNetReactor , pSession)
		, m_pRpcManager(pRpcManager) 
	{
		SetLastRecvPingTime();
	} 


	RemoteRpcServer::~RemoteRpcServer()
	{ 
		Cleanup();
		SAFE_DELETE(m_pSession);
	} 


	void RemoteRpcServer::SetLastRecvPingTime( INT64 ullLstRecfPing /*= 0*/ )
	{
		if (ullLstRecfPing == 0)
		{
			m_ullLastRecvPing = Timer::TimerHelper::GetTickCount(); 
		}
		else
		{
			m_ullLastRecvPing = ullLstRecfPing; 
		}  
	}


	INT32 RemoteRpcServer::Update( void )
	{ 
		UpdatePing();

		return NetHandlerTransit::Update();
	}


	INT32 RemoteRpcServer::UpdatePing( void )
	{
		if (m_ullLastRecvPing == 0)
		{
			SetLastRecvPingTime();
		}

		std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(m_pRpcManager->GetRpcInterface()->GetServerType()  , m_pSession->GetAddress() , m_pSession->GetPort()); 

		if (m_pSession->IsClosed() && strcmp(strRemoteRPCName.c_str() , m_pSession->GetRemoteName()) != 0)
		{
			gErrorStream ("重复新建的.应删除" << m_pSession->GetRemoteName());
// 			m_pRpcManager->GetRpcInterface()->CloseNet(strRemoteRPCName.c_str());
			
			GetSession()->SetClosed(TRUE);
			GetSession()->SetNetState(Net::NET_STATE_LOSTED);
			return 0;
		}

		INT64 ullCurTime = Timer::TimerHelper::GetTickCount();
		INT64 nDiffTime = Timer::TimerHelper::GetTickSecond(ullCurTime - m_ullLastRecvPing);
		if (nDiffTime >= DEFAULT_RPC_PING_TIMEOUT * 3 && m_pSession && m_pRpcManager)
		{
			gErrorStream ("timeout close " << m_pSession->GetRemoteName());
			m_pSession->SetClosed(TRUE); 

			m_pRpcManager->CloseNet(m_pSession->GetSessionID()); 
		} 

		return 0;
	}


	INT32 RemoteRpcServer::OnClose( void )
	{   
		if(GetSession() && GetSession()->GetSessionID() != -1 && m_pRpcManager)
		{ 
// 			m_pRpcManager->GetRpcInterface()->CloseNet(GetSession()->GetRemoteName()); 
			GetSession()->SetClosed(TRUE);
			GetSession()->SetNetState(Net::NET_STATE_LOSTED);
 			m_pRpcManager->CloseNet(GetSession()->GetRemoteName()); 
		} 

		return NetHandlerServer::OnClose();
	}


	INT32 RemoteRpcServer::HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		switch(unMsgID)
		{
		case DEFAULT_RPC_PING_ID:
			{
				Assert_Re(pBuffer && m_pRpcManager , -1);   

				SPing objPing;
				memcpy(&objPing , pBuffer , unLength);

				SetLastRecvPingTime();
				return m_pRpcManager->HandlePing(pSession , &objPing); 
			}break;
		case DEFAULT_RPC_MSG_ID:
			{
				Assert_Re(pBuffer && m_pRpcManager, -1);  
				UINT32 unTargetsCount = (UINT32)*pBuffer;
				RPCMsgCall * pMsg = new(unTargetsCount * sizeof(Object))RPCMsgCall;  
				pMsg->UnSerialization(pBuffer); 
				pMsg->SetSessionName(pSession->GetRemoteName()); 

				return m_pRpcManager->HandleMsg(pSession , pMsg); 
			}
		default:
			break;
		}

		return -1;
	}
}