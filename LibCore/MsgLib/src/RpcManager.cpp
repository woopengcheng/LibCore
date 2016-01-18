#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcBase.h"
#include "Marshal/inc/CStream.h"
#include "MsgLib/inc/RpcInterface.h"

namespace Msg
{  
	CErrno RpcManager::FetchSessions()
	{
		if (m_pRpcInterface)
		{
			Net::NetThread * pNet = m_pRpcInterface->GetNetThread();
			if (pNet)
			{
				std::vector<Net::SPeerInfo> vecSessions;
				pNet->FetchSession(vecSessions);
				std::vector<Net::SPeerInfo>::iterator iter = vecSessions.begin();
				for (;iter != vecSessions.end();++iter)
				{
					Net::SPeerInfo & objInfo = *iter;
					m_mapSessions.insert(std::make_pair(objInfo.nSessionID , objInfo));
					m_mapPeerSessions.insert(std::make_pair(objInfo.nPeerSessionID, objInfo));
					m_mapSessionNodes.insert(std::make_pair(objInfo.szNodeName, objInfo));
				}
			}
		}

		return CErrno::Success();
	}

	CErrno RpcManager::FetchMsgs()
	{
		if (m_pRpcInterface)
		{
			Net::NetThread * pNet = m_pRpcInterface->GetNetThread();
			if (pNet)
			{
				CollectSessionsIDT::iterator iter = m_mapPeerSessions.begin();
				for (;iter != m_mapSessions.end();)
				{
					std::vector<CUtil::Chunk> vecMsgs;
					if (pNet->FetchMsgs(iter->first, vecMsgs).IsFailure())
					{
						m_mapSessionNodes.erase(iter->second.szNodeName);
						m_mapSessions.erase(iter->second.nSessionID);
						iter = m_mapPeerSessions.erase(iter);
					}
					else
					{
						HandleMsgs(iter->first, vecMsgs);
						++iter;
					}
				}
			}
			return CErrno::Success();
		}

		return CErrno::Failure();
	}

	CErrno RpcManager::HandleMsgs(INT32 nSessionID, std::vector<CUtil::Chunk> & vecMsgs)
	{
		UINT32 unMsgID = 0;
		char * pBuf = NULL;
		std::vector<CUtil::Chunk>::iterator iter = vecMsgs.begin();
		for (;iter != vecMsgs.end();++iter)
		{
			pBuf = (char *)((*iter).Begin());
			unMsgID = ((Net::MsgHeader*)pBuf)->unMsgID;
			UINT32 unLength = ((Net::MsgHeader*)pBuf)->unMsgLength - sizeof(Net::MsgHeader);
			
			HandleMsg(nSessionID, unMsgID, pBuf + sizeof(Net::MsgHeader), unLength);
		}

		return CErrno::Success();
	}
	
	CErrno RpcManager::HandleMsg(INT32 nSessionID, UINT32 unMsgID, const char* pBuffer, UINT32 unLength)
	{
		if (!pBuffer)
		{
			return CErrno::Failure();
		}

		switch (unMsgID)
		{
			case DEFAULT_RPC_MSG_ID:
			{
				Assert_ReF(pBuffer);

				CUtil::CStream cs(pBuffer, unLength);
				UINT32 unTargetsCount = 0;
				cs >> CUtil::Marshal::Begin >> unTargetsCount >> CUtil::Marshal::Rollback;

				RPCMsgCall * pMsg = new(unTargetsCount * sizeof(Object))RPCMsgCall;
				pMsg->unMarshal(cs);

				pMsg->SetSessionName(pMsg->m_szRemoteName);
				memcpy(pMsg->m_szRemoteName, GetRpcInterface()->GetServerName(), strlen(GetRpcInterface()->GetServerName()) + 1);

				return HandleMsg(nSessionID , pMsg);
			}
			default:
				break;
		}

		return CErrno::Success();
	}

	CErrno RpcManager::HandleMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		Assert_ReF(pMsg && strcmp(pMsg->m_szMsgMethod, "") != 0);

		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		if (!pMsg->m_bClientRequest)
		{
			HandleServerMsg(nSessionID, pMsg);
		}
		else
		{
			HandleClientMsg(nSessionID, pMsg);
		}

		if (pMsg->GetReturnType() & RETURN_TYPE_DELAY)
		{
			pMsg->ReplaceDelayTarget();
			PostDelayMsg(nSessionID , pMsg);
		}
		else if ((pMsg->GetReturnType() & RETURN_TYPE_IGNORE) || (pMsg->GetReturnType() & RETURN_TYPE_DONE))
		{
			SAFE_DELETE_NEW(pMsg);
		}

		return CErrno::Success();
	}

	CErrno RpcManager::HandleServerMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		Rpc::VecObjectMsgCallT vecObjectMsgCall;
		SPeerInfo peerInfo = GetPeerSessions(nSessionID);
		Assert_ReF(peerInfo.nPeerSessionID > 0);

		Rpc objRpc(this, pMsg->m_ullTimeout, DEFAULT_RPC_CALLABLE_ID, pMsg, peerInfo.nPeerSessionID);

		if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod, RPCServer))
		{
			pMsg->SetRpcMsgCallType(RPCTYPE_SERVER);
			objRpc.OnServer(pMsg, vecObjectMsgCall);

			Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
			for (; iter != vecObjectMsgCall.end(); ++iter)
			{
				RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);

				SendMsg(peerInfo.nPeerSessionID , pReturnMsg, FALSE);
				SAFE_DELETE_NEW(pReturnMsg);
			}
		}
		else if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod, RPCServerProxy))
		{
			pMsg->SetRpcMsgCallType(RPCTYPE_SERVER_PROXY);
			objRpc.OnProxy(pMsg, vecObjectMsgCall);

			Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
			for (; iter != vecObjectMsgCall.end(); ++iter)
			{
				RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);

				SAFE_DELETE_NEW(pReturnMsg);
			}
		}
		else
		{
			MsgAssert_ReF(0, "recv wrong rpc.may not register.name:" << pMsg->m_szMsgMethod << ",from:" << pMsg->GetSessionName());
		}

		vecObjectMsgCall.clear();
		return CErrno::Success();
	}

	CErrno RpcManager::HandleClientMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		Assert_ReF(pMsg && strcmp(pMsg->m_szMsgMethod, "") != 0);

		SPeerInfo peerInfo = GetPeerSessions(nSessionID);
		Assert_ReF(peerInfo.nPeerSessionID > 0);

		MapRpcsT::iterator result = m_mapSendRpcs.find(pMsg->m_ullMsgID);
		if (result != m_mapSendRpcs.end())
		{
			Rpc::VecObjectMsgCallT vecObjectMsgCall;

			Rpc * objRpc = result->second;
			RPCMsgCall * pTemp = objRpc->GetRpcMsgCall();
			pTemp->CopyExcludeNetDatas(pMsg);

			objRpc->SetSessionID(peerInfo.nPeerSessionID);
			if (pMsg->m_bClientRequest)
			{
				if (pTemp->GetSyncType() == SYNC_TYPE_NONSYNC)
				{
					if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod, RPCClient))
					{
						pMsg->SetRpcMsgCallType(RPCTYPE_CLIENT);
						objRpc->OnClient(pMsg, vecObjectMsgCall);
					}
					else if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod, RPCClientProxy))
					{
						pMsg->SetRpcMsgCallType(RPCTYPE_CLIENT_PROXY);

						objRpc->OnProxy(pMsg, vecObjectMsgCall);

						Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
						for (; iter != vecObjectMsgCall.end(); ++iter)
						{
							RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);
							if (pReturnMsg)
							{
								SendMsg(peerInfo.nPeerSessionID, pReturnMsg, FALSE);
								SAFE_DELETE_NEW(pReturnMsg);
							}
						}
					}
					else
					{
						MsgAssert_ReF(0, "客户端接受到错误的RPC包.");
					}
				}
				else if (pTemp->GetSyncType() == SYNC_TYPE_SYNC)
				{
					if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod, RPCClient))
					{
						pMsg->SetRpcMsgCallType(RPCTYPE_CLIENT);
						if (FALSE == objRpc->OnClient(pMsg, vecObjectMsgCall))
						{
							pTemp->SetSyncResult(SYNC_RESULT_FALSE);
						}
						else
						{
							pTemp->SetSyncResult(SYNC_RESULT_SUCCESS);
						}

						Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
						for (; iter != vecObjectMsgCall.end(); ++iter)
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
						MsgAssert_ReF(0, "error sync rpc packet.");
						pTemp->SetSyncResult(SYNC_RESULT_FALSE);
					}
				}
				else
				{
					MsgAssert_ReF(0, "unkown sync_type packet.");
				}
			}
			else
			{
				MsgAssert_ReF(0, "客户端接受到错误的RPC包.");
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

	CErrno RpcManager::UpdateCalls(void)
	{
		Rpc::VecObjectMsgCallT vecObjectMsgCall;

		MapRpcsT::iterator iter = m_mapSendRpcs.begin();
		for (; iter != m_mapSendRpcs.end();)
		{
			Rpc * objRpc = iter->second;
			RPCMsgCall * pRpcMsgCall = objRpc->GetRpcMsgCall();
			MsgAssert_ReF(pRpcMsgCall, "RpcMsg is NULL.");

			if (objRpc->IsTimeout())
			{
				pRpcMsgCall->m_bClientRequest = TRUE;
				pRpcMsgCall->SetRpcMsgCallType(RPCTYPE_TIMEOUT);

				objRpc->OnTimeout(pRpcMsgCall, vecObjectMsgCall);

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

	CErrno RpcManager::UpdatePostMsgs(void)
	{
		RPCMsgCall * pMsg = NULL;
		CollectionPostMsgsT::iterator iter = m_mapPostMsgs.begin();
		for (; iter != m_mapPostMsgs.end(); ++iter)
		{
			INT32 nSessionID = iter->first;
			CollectionMsgsQueT & que = iter->second;
			 
			while (que.try_pop(pMsg))
			{
				HandleMsg(nSessionID, pMsg);
			}
		}

		return CErrno::Success();
	}

	CErrno RpcManager::UpdateDelayMsgs(void)
	{
		RPCMsgCall * pMsg = NULL;
		CollectionDelayMsgsT::iterator iter = m_mapDelayMsgs.begin();
		for (; iter != m_mapDelayMsgs.end(); ++iter)
		{
			INT32 nSessionID = iter->first;
			CollectionMsgsQueT & que = iter->second;

			while (que.try_pop(pMsg))
			{
				HandleMsg(nSessionID, pMsg);
			}
		}

		return CErrno::Success();
	}

	void RpcManager::InsertDelayMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		CollectionDelayMsgsT::iterator iter = m_mapDelayMsgs.find(nSessionID);
		if (iter != m_mapDelayMsgs.end())
		{
			CollectionMsgsQueT & que = iter->second;
			que.push(pMsg);
		}
		else
		{
			CollectionMsgsQueT que;
			que.push(pMsg);

			m_mapDelayMsgs.insert(std::make_pair(nSessionID, que));
		}
	}

	void RpcManager::InsertPostMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		CollectionPostMsgsT::iterator iter = m_mapPostMsgs.find(nSessionID);
		if (iter != m_mapPostMsgs.end())
		{
			CollectionMsgsQueT & que = iter->second;
			que.push(pMsg);
		}
		else
		{
			CollectionMsgsQueT que;
			que.push(pMsg);

			m_mapPostMsgs.insert(std::make_pair(nSessionID, que));
		}
	}

	CErrno RpcManager::PostMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		pMsg->SetSessionName(pMsg->m_szRemoteName);
		memcpy(pMsg->m_szRemoteName, GetRpcInterface()->GetServerName(), strlen(GetRpcInterface()->GetServerName()) + 1);

		RPCMsgCall * pCopyMsg = NULL;
		pMsg->Copy(pCopyMsg);
		InsertPostMsg(nSessionID, pCopyMsg);

		return CErrno::Success();
	}

	CErrno RpcManager::PostMsg(const std::string & strNodeName, RPCMsgCall * pMsg)
	{
		INT32 nPeerSessionID = GetPeerSessionIDByNode(strNodeName);
		if (nPeerSessionID > 0)
		{
			return PostMsg(nPeerSessionID, pMsg);
		}

		return CErrno::Failure();
	}

	CErrno RpcManager::PostDelayMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		InsertDelayMsg(nSessionID, pMsg);

		return CErrno::Success();
	}

	SPeerInfo  RpcManager::GetPeerSessions(INT32 nSessionID)
	{
		CollectSessionsIDT::iterator iter = m_mapSessions.find(nSessionID);
		if (iter == m_mapSessions.end())
		{
			CollectSessionsIDT::iterator iter2 = m_mapPeerSessions.find(nSessionID);
			if (iter2 == m_mapPeerSessions.end())
			{
				return SPeerInfo();
			}
			return iter2->second;
		}

		return SPeerInfo();
	}
	
	INT32 RpcManager::GetPeerSessionIDByNode(const std::string & strNode)
	{
		CollectSessionsStringT::iterator iter = m_mapSessionNodes.find(strNode);
		if (iter != m_mapSessionNodes.end())
		{
			return iter->second.nPeerSessionID;
		}

		return -1;
	}

	void RpcManager::InsertSendRpc(UINT64 ullRpcMsgID, Rpc * pRpc)
	{ 
		Assert(pRpc);

		MapRpcsT::iterator result = m_mapSendRpcs.find(ullRpcMsgID);
		if (result == m_mapSendRpcs.end())
		{
			m_mapSendRpcs.insert(std::make_pair(ullRpcMsgID , pRpc));
		} 
	}

	void RpcManager::InsertSendRpc( RPCMsgCall * pMsg )
	{
		Assert(pMsg);

		Rpc * pRpc = new Rpc(this , pMsg->m_ullTimeout , DEFAULT_RPC_CALLABLE_ID , pMsg);
		InsertSendRpc(pMsg->m_ullMsgID , pRpc);
	} 

	INT32 RpcManager::SendMsg( INT32 nSessionID , RPCMsgCall * pRpcMsg, BOOL bAddRpc/* = TRUE*/)
	{
		if (m_pRpcInterface && m_pRpcInterface->GetNetThread())
		{
			Net::NetThread * pNetThread = m_pRpcInterface->GetNetThread();
			if (pNetThread)
			{
				CUtil::CStream objStream;
				pRpcMsg->marshal(objStream);
				UINT32 unSerializationSize = objStream.GetDataLen();

				INT32 nMsgID = DEFAULT_RPC_MSG_ID, nMsgLength = unSerializationSize + sizeof(Net::MsgHeader);
				objStream.Insert(objStream.Begin(), &nMsgLength, sizeof(nMsgLength));
				objStream.Insert((char *)objStream.Begin() + sizeof(nMsgLength), &nMsgID, sizeof(nMsgID));

				return pNetThread->SendMsg(nSessionID, (const char *)objStream.Begin(), nMsgLength);
			}
		}
		return -1; 
	}

	INT32 RpcManager::SendMsg(const std::string & strNodeName, RPCMsgCall * pMsg, BOOL bAddRpc /*= TRUE*/)
	{
		INT32 nPeerSessionID = GetPeerSessionIDByNode(strNodeName);
		if (nPeerSessionID > 0)
		{
			return SendMsg(nPeerSessionID, pMsg , bAddRpc);
		}

		return -1;
	}

	CErrno RpcManager::Update(void)
	{
#ifndef CLOSE_RPC_TIMEOUT
		UpdateCalls();
#endif
		UpdatePostMsgs();
		UpdateDelayMsgs();

		return CErrno::Success();
	}
	 
	CErrno RpcManager::Cleanup( void )
	{  
		return CErrno::Success();
	}


	CErrno RpcManager::Init( void )
	{ 

		return CErrno::Success(); 
	}


	BOOL RpcManager::IsAllConnected()
	{
		BOOL bSuccess = TRUE;


		return bSuccess; 
	}

	Rpc * RpcManager::GetSendRpc(UINT64 ullMsgID)
	{
		MapRpcsT::iterator iter = m_mapSendRpcs.find(ullMsgID);
		if (iter != m_mapSendRpcs.end())
		{
			return iter->second;
		}

		return NULL;
	}

}