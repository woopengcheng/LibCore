#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/RpcInterface.h"

namespace Msg
{

	Net::NetHandlerTransitPtr RpcClientManager::OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/  , void * context/* = NULL*/)
	{
		Assert_Re0(pName && pAddress); 

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(pName);
		if (!pNetHandler)
		{
			Net::ClientSession * pClientSession =  new Net::ClientSession(pAddress , usPort , pName);
			RemoteRpcClientPtr pNetHandlerClient = RemoteRpcClientPtr(new RemoteRpcClient(this , m_pNetReactor , pClientSession)); 

			CErrno nResult = pNetHandlerClient->Init(pAddress, usPort); 
			AddRemoteRpc(pClientSession->GetSessionID() , pNetHandlerClient); 

			if(nResult.IsSuccess()) 
			{  
				m_pNetReactor->AddNetHandler(pNetHandlerClient);  
				pClientSession->SetClosed(FALSE);
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


	CErrno RpcClientManager::Ping( void )
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
			memcpy(objPing.szRemoteName , m_pRpcInterface->GetServerName() , strlen(m_pRpcInterface->GetServerName()) + 1);
			memcpy(objPing.szNetNodeName , m_pRpcInterface->GetNetNodeName() , strlen(m_pRpcInterface->GetNetNodeName()) + 1);

			SendMsg(pNet , DEFAULT_RPC_PING_ID , (const char *)(&objPing) , sizeof(objPing) , TRUE); 

			//			gDebugStream("SendPing " <<  pNet->GetSession()->GetRemoteName());
		}

		return CErrno::Success();
	}


	CErrno RpcClientManager::UpdatePing( void )
	{ 
		INT64 ullCurTime = Timer::TimerHelper::GetTickSecond(); 
		if (ullCurTime - m_llLastSendPing >= DEFAULT_RPC_PING_TIMEOUT)
		{
			m_llLastSendPing = Timer::TimerHelper::GetTickSecond();
			return Ping();
		} 

		return CErrno::Failure();
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


	CErrno RpcClientManager::Init( void )
	{    

		return RpcManager::Init() ;
	}


	CErrno RpcClientManager::Cleanup( void )
	{ 

		return RpcManager::Cleanup(); 
	} 

	CErrno RpcClientManager::Update( void )
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