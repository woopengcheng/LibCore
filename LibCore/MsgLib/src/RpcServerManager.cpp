#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/IRpcListener.h"
#include "NetLib/inc/ServerSession.h"

namespace Msg
{

	INT32 RpcServerManager::UpdateCalls( void )
	{
		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		MapRpcsT::iterator iter = m_mapSendRpcs.begin();
		for (;iter != m_mapSendRpcs.end();)
		{
			Rpc * objRpc = iter->second;
			RPCMsgCall * pRpcMsgCall = objRpc->GetRpcMsgCall();
			MsgAssert_ReF1(pRpcMsgCall , "RpcMsg is NULL.");

			if ( objRpc->IsTimeout() )
			{  
				pRpcMsgCall->m_bClientRequest = TRUE;
				pRpcMsgCall->SetRpcMsgCallType(RPCTYPE_TIMEOUT);

				objRpc->OnTimeout(pRpcMsgCall , vecObjectMsgCall);	

				SAFE_DELETE(pRpcMsgCall);
				vecObjectMsgCall.clear();
				SAFE_DELETE(iter->second);
				m_mapSendRpcs.erase(iter++);
			}
			else
			{
				++iter;
			}
		} 

		return ERR_SUCCESS;
	} 


	INT32 RpcServerManager::HandleMsg(Net::ISession * pSession , RPCMsgCall * pMsg )
	{
		Assert_ReF1(pMsg && strcmp(pMsg->m_szMsgMethod , "") != 0);

		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		if (!pMsg->m_bClientRequest)
		{
			HandleServerMsg(pSession , pMsg);
		}
		else
		{
			HandleClientMsg(pSession , pMsg);
		}

		SAFE_DELETE(pMsg); 

		return ERR_SUCCESS;
	}  


	INT32 RpcServerManager::HandleClientMsg( Net::ISession * pSession , RPCMsgCall * pMsg )
	{
		Assert_ReF1(pMsg && strcmp(pMsg->m_szMsgMethod , "") != 0);

		MapRpcsT::iterator result = m_mapSendRpcs.find(pMsg->m_ullMsgID);
		if (result != m_mapSendRpcs.end())
		{  
			Rpc::VecObjectMsgCallT vecObjectMsgCall;

			Rpc * objRpc = result->second;
			RPCMsgCall * pTemp = objRpc->GetRpcMsgCall(); 
			pMsg->SetSessionName(pTemp->GetSessionName());

			objRpc->SetRpcMsgCall(pMsg); 
			objRpc->SetSession(pSession);
			if (pMsg->m_bClientRequest)
			{   
				if (pTemp->GetSyncType() == SYNC_TYPE_NONSYNC)
				{
					if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod , RPCClient))
					{  
						pMsg->SetRpcMsgCallType(RPCTYPE_CLIENT); 
						objRpc->OnClient(pMsg , vecObjectMsgCall);  
					}
					else if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod , RPCClientProxy))
					{   
						pMsg->SetRpcMsgCallType(RPCTYPE_CLIENT_PROXY); 
						pMsg->m_objSource = pTemp->GetProxySrcID();  

						objRpc->OnProxy(pMsg , vecObjectMsgCall);   

						Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
						for (;iter != vecObjectMsgCall.end();++iter)  
						{
							RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);
							if (pReturnMsg)
							{ 
								SendMsg(pMsg->GetSessionName(), pReturnMsg , FALSE , FALSE);
								SAFE_DELETE(pReturnMsg);
							}
						}  
					}
					else
					{
						MsgAssert_ReF1(0 , "客户端接受到错误的RPC包.");
					}
				}
				else if(pTemp->GetSyncType() == SYNC_TYPE_SYNC)
				{
					if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod , RPCClient))
					{  
						pMsg->SetRpcMsgCallType(RPCTYPE_CLIENT); 
						if(FALSE == objRpc->OnClient(pMsg , vecObjectMsgCall))
						{
							pTemp->SetSyncResult(SYNC_RESULT_FALSE);
						}
						else
						{
							pTemp->SetSyncResult(SYNC_RESULT_SUCCESS);
						}

						Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
						for (;iter != vecObjectMsgCall.end();++iter)  
						{
							RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);
							if (pReturnMsg)
							{ 
								SAFE_DELETE(pReturnMsg);
							}
						} 
					} 
					else
					{
						MsgAssert_ReF1(0 , "error sync rpc packet.");
						pTemp->SetSyncResult(SYNC_RESULT_FALSE);
					} 
				}
				else
				{
					MsgAssert_ReF1(0 , "unkown sync_type packet.");
				}
			}
			else
			{
				MsgAssert_ReF1(0 , "客户端接受到错误的RPC包.");
			}

			SAFE_DELETE(result->second);
			m_mapSendRpcs.erase(result);
			vecObjectMsgCall.clear();

			if (pTemp->GetSyncType() == SYNC_TYPE_NONSYNC)
			{
				SAFE_DELETE(pTemp);  
			}
		} 

		return ERR_SUCCESS;
	}


	INT32 RpcServerManager::HandleServerMsg( Net::ISession * pSession , RPCMsgCall * pMsg )
	{ 
		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		Rpc objRpc(this , pMsg->m_ullTimeout , DEFAULT_RPC_CALLABLE_ID , pMsg , pSession);  

		if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod , RPCServer))
		{
			pMsg->SetRpcMsgCallType(RPCTYPE_SERVER); 
			objRpc.OnServer(pMsg , vecObjectMsgCall); 

			Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
			for (;iter != vecObjectMsgCall.end();++iter)  
			{
				RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);

				SendMsg(pMsg->GetSessionName() , pReturnMsg , FALSE , FALSE);
				SAFE_DELETE(pReturnMsg);
			} 
		}
		else if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod , RPCServerProxy))
		{
			pMsg->SetRpcMsgCallType(RPCTYPE_SERVER_PROXY);
			objRpc.OnProxy(pMsg , vecObjectMsgCall);  

			Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
			for (;iter != vecObjectMsgCall.end();++iter)  
			{
				RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);

				SAFE_DELETE(pReturnMsg);
			} 
		}
		else
		{
			MsgAssert_ReF1(0 , "recv wrong rpc.may not register.name:" << pMsg->m_szMsgMethod << ",from:" << pMsg->GetSessionName());
		}  

		vecObjectMsgCall.clear(); 
		return ERR_SUCCESS;
	}


	INT32 RpcServerManager::Init( UINT32 unMsgThreadPriorityCount /*= 1*/ , UINT32 unMsgHandlerthreadPriorityCount /*= 1*/, UINT32 unMsgThreadPriority /*= DEFAULT_MSG_THREAD_ID*/ ,UINT32 unMsgHandlerthreadPriority /*= DEFAULT_MSG_HANDLE_THREAD_ID*/)
	{ 

		return RpcManager::Init();
	}


	INT32 RpcServerManager::Cleanup( void )
	{  

		return RpcManager::Cleanup(); 
	}  


	INT32 RpcServerManager::Update( void )
	{  
#ifndef CLOSE_RPC_TIMEOUT
		UpdateCalls();
#endif
		return RpcManager::Update();
	} 

#ifdef USE_ZMQ
	INT32 RpcServerManager::HandlePing( Net::ISession * pSession , SPing * pPing )
	{ 
		if(m_pRpcInterface && pSession && pPing )
		{  
			std::string strRemoteRPCName = pPing->szRemoteName;  

			RpcClientManager *  pRpcClientManager = m_pRpcInterface->GetRpcClientManager();
			if (pRpcClientManager)
			{  
				Net::NetHandlerTransitPtr pNetHandlerClient = pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
				if (!pNetHandlerClient)
				{  
					pNetHandlerClient = pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , pSession->GetAddress() , pPing->usRemoteRPCPort); 
				}  

				if(pNetHandlerClient && m_pRpcInterface->GetRpcListener())
				{   
					m_pRpcInterface->GetRpcListener()->OnListenOn(m_pRpcInterface);  
				} 
			}  

			gDebugStream("zmq recv client ping. " << strRemoteRPCName << std::endl);
		}  

		return TRUE;
	} 

#else
	INT32 RpcServerManager::HandlePing( Net::ISession * pSession , SPing * pPing )
	{ 
		if(m_pRpcInterface && pSession && pPing )
		{  
			std::string strRemoteRPCName = Net::NetHelper::GenerateRemoteName(m_pRpcInterface->GetServerType()  , pSession->GetAddress() , pPing->usRemoteRPCPort); 

			if (pPing->usRemoteRPCPort != pSession->GetPort() /*|| !IsRpcInfoVaild(strRemoteRPCName)*/)
			{
				DelRpcInfo(pSession->GetRemoteName());
				gDebugStream("setName: ID: " << pSession->GetSessionID() << "Name " << pSession->GetRemoteName() << "set " << strRemoteRPCName);
				pSession->SetRemoteName(strRemoteRPCName.c_str()); 
				pSession->SetSocktPort(pPing->usRemoteRPCPort);

				AddRpcInfo(SRpcInfo(pSession->GetRemoteName() , pSession->GetAddress() , pSession->GetPort() , pSession->GetSessionID()));
			} 

			RpcClientManager *  pRpcClientManager = m_pRpcInterface->GetRpcClientManager();
			if (pRpcClientManager)
			{ 
				Net::NetHandlerTransitPtr pNetHandler(NULL);
				pNetHandler = pRpcClientManager->GetHandlerByName(strRemoteRPCName.c_str());
				if (!pNetHandler)
				{  
					pNetHandler = pRpcClientManager->CreateNetHandler(strRemoteRPCName.c_str() , pSession->GetAddress() , pPing->usRemoteRPCPort); 
				}  
				else if(pNetHandler->GetSession() && pNetHandler->GetSession()->IsClosed())
				{
					if(ERR_SUCCESS == pNetHandler->Init())
					{
						pNetHandler->GetSession()->SetNetState(Net::NET_STATE_CONNECTING); 
						pNetHandler->GetSession()->SetClosed(FALSE);  
					}
				}

				if(pNetHandler && pNetHandler->GetSession()->GetNetState() == Net::NET_STATE_CONNECTING &&
					pSession->GetNetState() == Net::NET_STATE_CONNECTING)
				{   
					pSession->SetNetState(Net::NET_STATE_CONNECTED);
					pNetHandler->GetSession()->SetNetState(Net::NET_STATE_CONNECTED); 

					if (m_pRpcInterface->GetRpcListener())
					{ 
						m_pRpcInterface->GetRpcListener()->OnListenOn(m_pRpcInterface); 
					}
				} 

				if (pNetHandler->GetSession()->GetOtherSession() != pSession)
				{
					pNetHandler->GetSession()->SetOtherSession(pSession); 
					pSession->SetOtherSession(pNetHandler->GetSession()); 
				}
			}  

//			gDebugStream("recv client ping. " << strRemoteRPCName << std::endl);
		}  

		return TRUE;
	}  
#endif

	Net::NetHandlerTransitPtr RpcServerManager::OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/  , void * context/* = NULL*/)
	{
		Assert_Re0(pAddress);   
		std::string strRemoteName = Net::NetHelper::GenerateRemoteName(m_pRpcInterface->GetServerType()  , pAddress , usPort );

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(strRemoteName.c_str());
		if (!pNetHandler)
		{
#ifdef USE_ZMQ
			Net::ServerSession * pServerSession =  new Net::ServerSession(pAddress , usPort , pName , -1 , 0 , socket);
			pServerSession->SetNetState(Net::NET_STATE_CONNECTED); 
#else
			Net::ServerSession * pServerSession =  new Net::ServerSession(pAddress , 0 , pName , -1 , 0 , socket);
			pServerSession->SetNetState(Net::NET_STATE_CONNECTING);
#endif
			RemoteRpcServerPtr pRpcServer(new RemoteRpcServer(this , m_pNetReactor , pServerSession)); 
			pServerSession->SetClosed(FALSE);

			gDebugStream("accept: ID: " << pServerSession->GetSessionID());

			AddRemoteRpc(pServerSession->GetSessionID() , pRpcServer); 

			m_pNetReactor->AddNetHandler(pRpcServer);

			return pRpcServer;  
		}

		return pNetHandler;
	} 

	void RpcServerManager::CloseNet( const char * pName )
	{
		Net::NetHandlerTransitPtr pHandler = GetHandlerBySimilarName(pName); 
		if (pHandler.get())
		{
			pHandler->GetSession()->SetClosed(TRUE);
			pHandler->GetSession()->SetNetState(Net::NET_STATE_LOSTED);
			DelRemoteRpc(pHandler->GetSession()->GetSessionID()); 
		} 
	}

	void RpcServerManager::CloseNet( INT32 nSessionID )
	{ 
		DelRemoteRpc(nSessionID); 
	}

}