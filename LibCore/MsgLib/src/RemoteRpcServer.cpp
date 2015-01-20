#include "MsgLib/inc/RemoteRpcServer.h"
#include "NetLib/inc/NetHelper.h"
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RPCMsgCall.h"

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

#ifndef USE_ZMQ     //5 如果是ZMQ,底层有重连机制.
		UpdatePing();
#endif

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
			return ERR_NET_FAILURE;
		}

		INT64 ullCurTime = Timer::TimerHelper::GetTickCount();
		INT64 nDiffTime = Timer::TimerHelper::GetTickSecond(ullCurTime - m_ullLastRecvPing);
		if (nDiffTime >= DEFAULT_RPC_PING_TIMEOUT * 3 && m_pSession && m_pRpcManager)
		{
			gErrorStream ("timeout close " << m_pSession->GetRemoteName());
			m_pSession->SetClosed(TRUE); 

			m_pRpcManager->CloseNet(m_pSession->GetSessionID()); 
		} 

		return ERR_SUCCESS;
	}


	INT32 RemoteRpcServer::OnClose( void )
	{   
		if(GetSession() && GetSession()->GetSessionID() != -1 && m_pRpcManager)
		{   
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
				Assert_ReF1(pBuffer && m_pRpcManager);   

				SPing objPing;
				memcpy(&objPing , pBuffer , unLength);

				SetLastRecvPingTime();
				return m_pRpcManager->HandlePing(pSession , &objPing); 
			}break;
		case DEFAULT_RPC_MSG_ID:
			{
				Assert_ReF1(pBuffer && m_pRpcManager);  

				LibCore::CStream cs(pBuffer , unLength);
				UINT32 unTargetsCount = (UINT32)*pBuffer;
				cs >> unTargetsCount;

				RPCMsgCall * pMsg = new(unTargetsCount * sizeof(Object))RPCMsgCall;  
				pMsg->unMarshal(cs);

				pMsg->SetSessionName(pMsg->m_szRemoteName);
				memcpy(pMsg->m_szRemoteName , m_pRpcManager->GetRpcInterface()->GetServerName() , strlen( m_pRpcManager->GetRpcInterface()->GetServerName()) + 1);

				return m_pRpcManager->HandleMsg(pSession , pMsg); 
// 				Assert_ReF1(pBuffer && m_pRpcManager);  
// 				UINT32 unTargetsCount = (UINT32)*pBuffer;
// 				RPCMsgCall * pMsg = new(unTargetsCount * sizeof(Object))RPCMsgCall;  
// 				pMsg->UnSerialization(pBuffer); 
// 				pMsg->SetSessionName(pMsg->m_szRemoteName);
// 				memcpy(pMsg->m_szRemoteName , m_pRpcManager->GetRpcInterface()->GetServerName() , strlen( m_pRpcManager->GetRpcInterface()->GetServerName()) + 1);

			}
		default:
			break;
		}

		return ERR_FAILURE;
	}
}