#include "MsgLib/inc/RpcServerManager.h"
#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/NetNode.h"
#include "MsgLib/inc/IRpcListener.h"
#include "NetLib/inc/ServerSession.h"

namespace Msg
{

	RpcServerManager::~RpcServerManager(void)
	{
		CollectionPostMsgsT::iterator iter = m_mapPostMsgs.begin();
		for (;iter != m_mapPostMsgs.end(); ++iter)
		{
			iter->second.clear();
		}
		m_mapPostMsgs.clear();
		m_mapDelayMsgs.clear();
	}

	CErrno RpcServerManager::UpdateCalls( void )
	{
		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		MapRpcsT::iterator iter = m_mapSendRpcs.begin();
		for (;iter != m_mapSendRpcs.end();)
		{
			Rpc * objRpc = iter->second;
			RPCMsgCall * pRpcMsgCall = objRpc->GetRpcMsgCall();
			MsgAssert_ReF(pRpcMsgCall , "RpcMsg is NULL.");

			if ( objRpc->IsTimeout() )
			{  
				pRpcMsgCall->m_bClientRequest = TRUE;
				pRpcMsgCall->SetRpcMsgCallType(RPCTYPE_TIMEOUT);

				objRpc->OnTimeout(pRpcMsgCall , vecObjectMsgCall);	

				SAFE_DELETE_NEW(pRpcMsgCall);
				vecObjectMsgCall.clear();
				SAFE_DELETE(iter->second);
				m_mapSendRpcs.erase(iter++);
			}
			else
			{
				++iter;
			}
		} 

		return CErrno::Success();
	} 


	CErrno RpcServerManager::HandleMsg(Net::ISession * pSession , RPCMsgCall * pMsg )
	{
		Assert_ReF(pMsg && strcmp(pMsg->m_szMsgMethod , "") != 0);

		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		if (!pMsg->m_bClientRequest)
		{
			HandleServerMsg(pSession , pMsg);
		}
		else
		{
			HandleClientMsg(pSession , pMsg);
		}

		if (pMsg->GetReturnType() & RETURN_TYPE_DELAY)
		{
			pMsg->ReplaceDelayTarget();
			PostDelayMsg(pSession->GetRemoteName() ,pMsg);
		}
		else if ((pMsg->GetReturnType() & RETURN_TYPE_IGNORE) || (pMsg->GetReturnType() & RETURN_TYPE_DONE))
		{
			SAFE_DELETE_NEW(pMsg);
		} 

		return CErrno::Success();
	}  


	CErrno RpcServerManager::HandleClientMsg( Net::ISession * pSession , RPCMsgCall * pMsg )
	{
		Assert_ReF(pMsg && strcmp(pMsg->m_szMsgMethod , "") != 0);

		MapRpcsT::iterator result = m_mapSendRpcs.find(pMsg->m_ullMsgID);
		if (result != m_mapSendRpcs.end())
		{  
			Rpc::VecObjectMsgCallT vecObjectMsgCall;

			Rpc * objRpc = result->second;
			RPCMsgCall * pTemp = objRpc->GetRpcMsgCall();  
			pTemp->CopyExcludeNetDatas(pMsg);

//			objRpc->SetRpcMsgCall(pMsg); 
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

						objRpc->OnProxy(pMsg , vecObjectMsgCall);   

						Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
						for (;iter != vecObjectMsgCall.end();++iter)  
						{
							RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);
							if (pReturnMsg)
							{ 
								SendMsg(pMsg->GetSessionName(), pReturnMsg , FALSE);
								SAFE_DELETE_NEW(pReturnMsg);
							}
						}  
					}
					else
					{
						MsgAssert_ReF(0 , "客户端接受到错误的RPC包.");
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
								SAFE_DELETE_NEW(pReturnMsg);
							}
						} 
					} 
					else
					{
						MsgAssert_ReF(0 , "error sync rpc packet.");
						pTemp->SetSyncResult(SYNC_RESULT_FALSE);
					} 
				}
				else
				{
					MsgAssert_ReF(0 , "unkown sync_type packet.");
				}
			}
			else
			{
				MsgAssert_ReF(0 , "客户端接受到错误的RPC包.");
			}

			SAFE_DELETE(result->second);
			m_mapSendRpcs.erase(result);
			vecObjectMsgCall.clear();

			if (pTemp->GetSyncType() == SYNC_TYPE_NONSYNC)
			{
				SAFE_DELETE_NEW(pTemp);
			}
		} 

		return CErrno::Success();
	}


	CErrno RpcServerManager::HandleServerMsg( Net::ISession * pSession , RPCMsgCall * pMsg )
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

				SendMsg(pMsg->GetSessionName() , pReturnMsg , FALSE);
				SAFE_DELETE_NEW(pReturnMsg);
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

				SAFE_DELETE_NEW(pReturnMsg);
			} 
		}
		else
		{
			MsgAssert_ReF(0 , "recv wrong rpc.may not register.name:" << pMsg->m_szMsgMethod << ",from:" << pMsg->GetSessionName());
		}  

		vecObjectMsgCall.clear(); 
		return CErrno::Success();
	} 

	CErrno RpcServerManager::Init()
	{ 

		return RpcManager::Init();
	}


	CErrno RpcServerManager::Cleanup( void )
	{  

		return RpcManager::Cleanup(); 
	}  


	CErrno RpcServerManager::Update( void )
	{  
#ifndef CLOSE_RPC_TIMEOUT
		UpdateCalls();
#endif
		UpdatePostMsgs();
		UpdateDelayMsgs();
		return RpcManager::Update();
	} 

	CErrno RpcServerManager::HandlePing( Net::ISession * pSession , SPing * pPing )
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
					if(CErrno::Success() == pNetHandler->Init())
					{
						pNetHandler->GetSession()->SetNetState(Net::NET_STATE_CONNECTING); 
						pNetHandler->GetSession()->SetClosed(FALSE);  
					}
				}

				if (pNetHandler->GetSession()->GetOtherSession() != pSession)
				{
					pNetHandler->GetSession()->SetOtherSession(pSession); 
					pSession->SetOtherSession(pNetHandler->GetSession()); 
				}

				if(pNetHandler && pNetHandler->GetSession()->GetNetState() == Net::NET_STATE_CONNECTING &&
					pSession->GetNetState() == Net::NET_STATE_CONNECTING)
				{   
					pSession->SetNetState(Net::NET_STATE_CONNECTED);
					pNetHandler->GetSession()->SetNetState(Net::NET_STATE_CONNECTED); 

					Msg::NetNode::GetInstance().InsertRemoteNodes(pPing->szNetNodeName , pNetHandler->GetSession());
					if (m_pRpcInterface->GetRpcListener())
					{ 
						m_pRpcInterface->GetRpcClientManager()->Ping();
						m_pRpcInterface->GetRpcListener()->OnConnected(m_pRpcInterface , pNetHandler->GetSession() , pPing->szNetNodeName); 
					}
				} 
			}  
		}  

		return CErrno::Success();
	}  

	Net::NetHandlerTransitPtr RpcServerManager::OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/  , void * context/* = NULL*/)
	{
		Assert_Re0(pAddress);   
		std::string strRemoteName = Net::NetHelper::GenerateRemoteName(m_pRpcInterface->GetServerType()  , pAddress , usPort );

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(strRemoteName.c_str());
		if (!pNetHandler)
		{
			Net::ServerSession * pServerSession =  new Net::ServerSession(pAddress , 0 , pName , -1 , 0 , socket);
			pServerSession->SetNetState(Net::NET_STATE_CONNECTING);

			RemoteRpcServerPtr pRpcServer(new RemoteRpcServer(this , m_pNetReactor , pServerSession));

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
	
	CErrno RpcServerManager::PostMsg(const char * pRpcServerName , RPCMsgCall * pMsg)
	{
		Net::NetHandlerTransitPtr pHandler = GetHandlerByName(pRpcServerName);
		if (pHandler)
		{
			pMsg->SetSessionName(pMsg->m_szRemoteName);
			memcpy(pMsg->m_szRemoteName , GetRpcInterface()->GetServerName() , strlen( GetRpcInterface()->GetServerName()) + 1);

			RPCMsgCall * pCopyMsg = NULL;
			pMsg->Copy(pCopyMsg);
			InsertPostMsg(pRpcServerName , pCopyMsg); 
		}
		return CErrno::Success();
	}

	CErrno RpcServerManager::PostDelayMsg(const char * pRpcServerName , RPCMsgCall * pMsg)
	{
		InsertDelayMsg(pRpcServerName , pMsg); 

		return CErrno::Success();
	}

	void RpcServerManager::InsertDelayMsg(const std::string strRpcServerName , RPCMsgCall * pMsg)
	{
		CollectionDelayMsgsT::iterator iter = m_mapDelayMsgs.find(strRpcServerName);
		if (iter != m_mapDelayMsgs.end())
		{
			CollectionMsgsQueT & que = iter->second;
			que.push(pMsg);
		}
		else
		{
			CollectionMsgsQueT que;
			que.push(pMsg);

			m_mapDelayMsgs.insert(std::make_pair(strRpcServerName , que));
		}
	}

	void RpcServerManager::InsertPostMsg(const std::string & strRpcServerName , RPCMsgCall * pMsg)
	{
		CollectionPostMsgsT::iterator iter = m_mapPostMsgs.find(strRpcServerName);
		if (iter != m_mapPostMsgs.end())
		{
			CollectionMsgsQueT & que = iter->second;
			que.push(pMsg);
		}
		else
		{
			CollectionMsgsQueT que;
			que.push(pMsg);

			m_mapPostMsgs.insert(std::make_pair(strRpcServerName , que));
		}
	}

	CErrno RpcServerManager::UpdatePostMsgs(void)
	{
		RPCMsgCall * pMsg = NULL;
		CollectionPostMsgsT::iterator iter = m_mapPostMsgs.begin();
		for (;iter != m_mapPostMsgs.end();++iter)
		{
			std::string strRpcServerName = iter->first;
			CollectionMsgsQueT & que = iter->second;

			Net::NetHandlerTransitPtr pHandler = GetHandlerByName(strRpcServerName.c_str()); 
			MsgAssert_ReF(pHandler , "no this handler" << strRpcServerName);
			
			while(que.try_pop(pMsg))
			{
				HandleMsg(pHandler->GetSession() , pMsg);
			}
		}

		return CErrno::Success();
	}

	CErrno RpcServerManager::UpdateDelayMsgs(void)
	{
		RPCMsgCall * pMsg = NULL;
		CollectionDelayMsgsT::iterator iter = m_mapDelayMsgs.begin();
		for (;iter != m_mapDelayMsgs.end();++iter)
		{
			std::string strRpcServerName = iter->first;
			CollectionMsgsQueT & que = iter->second;

			Net::NetHandlerTransitPtr pHandler = GetHandlerByName(strRpcServerName.c_str()); 
			MsgAssert_ReF(pHandler , "no this handler" << strRpcServerName); 

			while(que.try_pop(pMsg))
			{
				HandleMsg(pHandler->GetSession() , pMsg);
			}
		}

		return CErrno::Success();
	}


}