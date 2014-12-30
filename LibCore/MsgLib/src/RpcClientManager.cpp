#include "RpcClientManager.h"

namespace Msg
{

	Net::NetHandlerTransitPtr RpcClientManager::OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::SOCKET socket /*= 0*/ )
	{
		Assert_Re0(pName && pAddress); 

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(pName);
		if (!pNetHandler)
		{
			Net::ClientSession * pClientSession =  new Net::ClientSession(pAddress , usPort , pName);
			RemoteRpcClient::RemoteRpcClientPtr pNetHandlerClient = RemoteRpcClient::RemoteRpcClientPtr(new RemoteRpcClient(this , m_pNetReactor , pClientSession)); 

			int nResult = pNetHandlerClient->Init(pAddress, usPort); 
			AddRemoteRpc(pClientSession->GetSessionID() , pNetHandlerClient); 

			if(0 == nResult) 
			{  
				m_pNetReactor->AddNetHandler(pNetHandlerClient);  
				pClientSession->SetNetState(Net::NET_STATE_CONNECTING);
				return pNetHandlerClient; 
			}
			else
			{ 
				pClientSession->SetClosed(TRUE);
				pClientSession->SetNetState(Net::NET_STATE_LOSTED); 
			}
		}

		return pNetHandler;
	} 


	INT32 RpcClientManager::Ping( void )
	{
		SPing objPing;

		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.begin();
		for (;iter != m_mapRemoteRpcs.end();)
		{
			Net::NetHandlerTransitPtr pNet = iter->second;

			++iter;  //5 the base maybe delete NetHandler
			if (!pNet.get() || pNet->GetSession()->GetSessionID() == -1)
			{
				continue;
			} 
			objPing.usRemoteRPCPort = m_pRpcInterface->GetServerPort();  
			memcpy(objPing.szRemoteName , pNet->GetSession()->GetRemoteName() , strlen(pNet->GetSession()->GetRemoteName() + 1));

			SendMsg(pNet , DEFAULT_RPC_PING_ID , (const char *)(&objPing) , sizeof(objPing) , TRUE); 

			//			gDebugStream("SendPing " <<  pNet->GetSession()->GetRemoteName());
		}

		return TRUE;
	}


	INT32 RpcClientManager::UpdatePing( void )
	{ 
		INT64 ullCurTime = Timer::TimerHelper::GetTickSecond(); 
		if (ullCurTime - m_ullLastSendPing >= DEFAULT_RPC_PING_TIMEOUT)
		{
			m_ullLastSendPing = Timer::TimerHelper::GetTickSecond();
			return Ping();
		} 

		return FALSE;
	}  


	INT32 RpcClientManager::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg , BOOL bForce/* = FALSE*/ ,BOOL bAddRpc/* = TRUE*/)
	{ 
		if (!pMsg)
		{
			return -1;
		}

		Net::NetHandlerTransitPtr pRemoteRpc = NULL;
		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.find(nSessionID);
		if (iter != m_mapRemoteRpcs.end())
		{ 
			pRemoteRpc = iter->second; 
		}

		if (pRemoteRpc && pRemoteRpc->GetSession()->GetSessionID() != -1 && 
			!pRemoteRpc->GetSession()->IsClosed() && ( pRemoteRpc->GetSession()->GetNetState() != Net::NET_STATE_LOSTED && 
			bForce || pRemoteRpc->GetSession()->GetNetState() == Net::NET_STATE_CONNECTED))
		{     
			return RpcManager::SendMsg(pRemoteRpc , pMsg , bForce , bAddRpc);  
		}

		return -1;
	}


	INT32 RpcClientManager::Init( void )
	{    

		return RpcManager::Init() ;
	}


	INT32 RpcClientManager::Cleanup( void )
	{ 

		return RpcManager::Cleanup(); 
	}



	INT32 RpcClientManager::Update( void )
	{  
		UpdatePing(); 
		return  RpcManager::Update();  
	} 

	void RpcClientManager::CloseNet( const char * pName )
	{
		Net::NetHandlerTransitPtr pHandler = GetHandlerByName(pName);
		if (pHandler.get())
		{
			CleanupRemoteRpc(pHandler->GetSession()->GetSessionID()); 
		} 
	}

}