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




	INT32 RpcClientManager::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg , BOOL bForce/* = FALSE*/ ,BOOL bAddRpc/* = TRUE*/)
	{ 
		if (!pMsg)
		{
			return -1;
		}
				
		return RpcManager::SendMsg(nSessionID, pMsg , bForce , bAddRpc);
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