#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcBase.h"
#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/IRpcListener.h"
#include "MsgLib/inc/MsgHelper.h"
#include "MsgLib/inc/NetNode.h"
#include "Marshal/inc/CStream.h"

namespace Msg
{  
	CErrno RpcManager::FetchSessions()
	{
		if (m_pRpcInterface)
		{
			Net::NetThread * pNet = m_pRpcInterface->GetNetThread();
			if (pNet)
			{
				std::vector<SPeerInfo> vecSessions;
				pNet->FetchSession(vecSessions);
				std::vector<SPeerInfo>::iterator iter = vecSessions.begin();
				for (;iter != vecSessions.end();++iter)
				{
					SPeerInfo & objInfo = *iter;
					EraseAndInsertPeerSession(objInfo);

					std::string strName = MsgHelper::GeneratePeerInfoKey(objInfo.strCurNodeName, objInfo.strRemoteNodeName);
					IRpcListener * pListener = m_pRpcInterface->GetRpcListener();
					if (pListener)
					{
						pListener->OnConnected(m_pRpcInterface, objInfo.nSessionID, strName);
					}
					gDebugStream("rpcmanager recv new session.NodeName=" << strName << ":address=" << objInfo.strAddress << ":port=" << objInfo.usPeerPort << ":bReconnect=" << objInfo.bReconect << ":clientSessionID=" << objInfo.nSessionID << ":PeerSessionID=" << objInfo.nPeerSessionID);
				}
			}
		}

		return CErrno::Success();
	}

	void RpcManager::EraseAndInsertPeerSession(const SPeerInfo & objInfo)
	{
		CollectSessionsIDT::iterator iter = m_mapSessions.find(objInfo.nSessionID);
		if (iter != m_mapSessions.end())
		{
			m_mapSessions.erase(iter);
		}
		m_mapSessions.insert(std::make_pair(objInfo.nSessionID, objInfo));

		iter = m_mapPeerSessions.find(objInfo.nPeerSessionID);
		if (iter != m_mapPeerSessions.end())
		{
			m_mapPeerSessions.erase(iter);
		}
		m_mapPeerSessions.insert(std::make_pair(objInfo.nPeerSessionID, objInfo));

		std::string strName = MsgHelper::GeneratePeerInfoKey(objInfo.strCurNodeName, objInfo.strRemoteNodeName);
		CollectSessionsStringT::iterator iter2 = m_mapSessionNodes.find(strName);
		if (iter2 != m_mapSessionNodes.end())
		{
			m_mapSessionNodes.erase(iter2);
		}
		m_mapSessionNodes.insert(std::make_pair(strName, objInfo));
	}

	CErrno RpcManager::FetchMsgs()
	{
		if (m_pRpcInterface)
		{
			Net::NetThread * pNet = m_pRpcInterface->GetNetThread();
			if (pNet)
			{
				CollectSessionsIDT::iterator iter = m_mapPeerSessions.begin();
				for (;iter != m_mapPeerSessions.end();)
				{
					std::vector<CUtil::Chunk> vecMsgs;
					if (pNet->FetchMsgs(iter->first, vecMsgs).IsFailure())
					{
						IRpcListener * pListener = m_pRpcInterface->GetRpcListener();
						if (pListener)
						{
							Net::SPeerInfo & objInfo = iter->second;
							pListener->OnDisconnected(m_pRpcInterface, objInfo.nSessionID, objInfo.nPeerSessionID);
						}

						std::string strName = MsgHelper::GeneratePeerInfoKey(iter->second.strCurNodeName, iter->second.strRemoteNodeName);
						m_mapSessionNodes.erase(strName);
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

				SPeerInfo peerInfo = GetPeerSessionInfo(nSessionID);
				pMsg->SetProxySessionID(peerInfo.nSessionID);

				return HandleMsg(peerInfo.nSessionID, pMsg);
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

		Rpc objRpc(this, pMsg->m_ullTimeout, DEFAULT_RPC_CALLABLE_ID, pMsg, nSessionID);

		if (HasSimilarRegisterFunc(pMsg->m_szMsgMethod, RPCServer))
		{
			pMsg->SetRpcMsgCallType(RPCTYPE_SERVER);
			objRpc.OnServer(pMsg, vecObjectMsgCall);

			Rpc::VecObjectMsgCallT::iterator iter = vecObjectMsgCall.begin();
			for (; iter != vecObjectMsgCall.end(); ++iter)
			{
				RPCMsgCall * pReturnMsg = (RPCMsgCall *)(*iter);
				if (pReturnMsg)
				{
					SendMsg(nSessionID, pReturnMsg, FALSE);
					SAFE_DELETE_NEW(pReturnMsg);
				}
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

				if (pReturnMsg)
				{
					SAFE_DELETE_NEW(pReturnMsg);
				}
			}
		}
		else
		{
			MsgAssert_ReF(0, "recv wrong rpc.may not register.name:" << pMsg->m_szMsgMethod);
		}

		vecObjectMsgCall.clear();
		return CErrno::Success();
	}

	CErrno RpcManager::HandleClientMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		Assert_ReF(pMsg && strcmp(pMsg->m_szMsgMethod, "") != 0);
		
		MapRpcsT::iterator result = m_mapSendRpcs.find(pMsg->m_ullMsgID);
		if (result != m_mapSendRpcs.end())
		{
			Rpc::VecObjectMsgCallT vecObjectMsgCall;

			Rpc * objRpc = result->second;
			RPCMsgCall * pTemp = objRpc->GetRpcMsgCall();
			pTemp->CopyExcludeNetDatas(pMsg);

			objRpc->SetSessionID(nSessionID);
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
								SendMsg(pMsg->GetProxySessionID(), pReturnMsg, FALSE);
								SAFE_DELETE_NEW(pReturnMsg);
							}
						}
					}
					else
					{
						MsgAssert_ReF(0, "�ͻ��˽��ܵ������RPC��.");
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

					if (m_pRpcInterface)
					{
						m_pRpcInterface->ResumeRpcCoTask(pTemp->m_ullMsgID);
					}
				}
				else
				{
					MsgAssert_ReF(0, "unkown sync_type packet.");
				}
			}
			else
			{
				MsgAssert_ReF(0, "�ͻ��˽��ܵ������RPC��.");
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

				objRpc->OnTimeout(pRpcMsgCall, vecObjectMsgCall); //5 todo.����Ҳ��Ҫ����ͬ����Э��resume

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
			StdQueueMsgsQueT & que = iter->second;

			while (!que.empty())
			{
				pMsg = que.front();
				HandleMsg(nSessionID, pMsg);
				que.pop();
			}
		}

		return CErrno::Success();
	}

	void RpcManager::InsertDelayMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		CollectionDelayMsgsT::iterator iter = m_mapDelayMsgs.find(nSessionID);
		if (iter != m_mapDelayMsgs.end())
		{
			StdQueueMsgsQueT & que = iter->second;
			que.push(pMsg);
		}
		else
		{
			StdQueueMsgsQueT que;
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
		pMsg->SetProxySessionID(nSessionID);

		RPCMsgCall * pCopyMsg = NULL;
		pMsg->CopyTo(pCopyMsg);
		InsertPostMsg(nSessionID, pCopyMsg);

		return CErrno::Success();
	}

	CErrno RpcManager::PostMsg(const std::string & strNodeName, RPCMsgCall * pMsg)
	{
		INT32 nSessionID = GetSessionIDByNode(strNodeName);
		if (nSessionID > 0)
		{
			return PostMsg(nSessionID, pMsg);
		}

		return CErrno::Failure();
	}

	CErrno RpcManager::PostDelayMsg(INT32 nSessionID, RPCMsgCall * pMsg)
	{
		InsertDelayMsg(nSessionID, pMsg);

		return CErrno::Success();
	}

	SPeerInfo  RpcManager::GetPeerSessionInfo(INT32 nSessionID)
	{
		CollectSessionsIDT::iterator iter = m_mapSessions.find(nSessionID);
		if (iter != m_mapSessions.end())
		{
			return iter->second;
		}
		else
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

	INT32 RpcManager::GetSessionIDByNode(const std::string & strNode)
	{
		CollectSessionsStringT::iterator iter = m_mapSessionNodes.find(strNode);
		if (iter != m_mapSessionNodes.end())
		{
			return iter->second.nSessionID;
		}

		return -1;
	}

	std::string RpcManager::GetNodeNameByID(INT32 nSessionID)
	{
		CollectSessionsIDT::iterator iter = m_mapSessions.find(nSessionID);
		if (iter != m_mapSessions.end())
		{
			return iter->second.strRemoteNodeName;
		}

		return std::string();
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

	INT32 RpcManager::SendMsg( INT32 nSessionID , RPCMsgCall * pRpcMsg, BOOL bAddRpc/* = TRUE*/, BOOL bCheck/* = TRUE*/)
	{
		if (bCheck)
		{
			SPeerInfo objInfo = GetPeerSessionInfo(nSessionID);
			std::string strNodeName = MsgHelper::GeneratePeerInfoKey(objInfo.strCurNodeName, objInfo.strRemoteNodeName);
			INT32 nRes = CheckAndHandlePostMsg(strNodeName, pRpcMsg, bAddRpc);
			if (nRes > 0)
			{
				return nRes;
			}
		}

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

				INT32 nResult = pNetThread->SendMsg(nSessionID, (const char *)objStream.Begin(), nMsgLength);
				if (nResult != -1 && bAddRpc)
				{
					InsertSendRpc(pRpcMsg);
				}
				return nResult;
			}
		}
		return -1; 
	}

	INT32 RpcManager::SendMsg(const std::string & strNodeName, RPCMsgCall * pMsg, BOOL bAddRpc /*= TRUE*/)
	{
		INT32 nRes = CheckAndHandlePostMsg(strNodeName, pMsg, bAddRpc);
		if (nRes <= 0)
		{
			INT32 nSessionID = GetSessionIDByNode(strNodeName);
			if (nSessionID > 0)
			{
				return SendMsg(nSessionID, pMsg, bAddRpc , FALSE);
			}
		}

		return -1;
	}

	INT32 RpcManager::CheckAndHandlePostMsg(const std::string & strNodeName, RPCMsgCall * pMsg , BOOL bAddRpc)
	{
		std::string strName = MsgHelper::GetSuffixNodeName(strNodeName);
		if (NetNode::GetInstance().IsInMyselfNodes(strName))
		{
			RpcInterface * pInterface = NetNode::GetInstance().GetMyselfNode(strName);
			if (pInterface != NULL)
			{
				strName = MsgHelper::ExchangeNodeName(strNodeName);
				if (pInterface->GetRpcManager()->PostMsg(strName, pMsg).IsFailure())
				{
					return 0;
				}

				if (bAddRpc)
				{
					InsertSendRpc(pMsg);
				}

				return 100;
			}
		}

		return 0;
	}

	CErrno RpcManager::Update(void)
	{
		FetchSessions();
		FetchMsgs();
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
	
	BOOL RpcManager::IsConnected(const std::string & strNodeName)
	{
		CollectSessionsStringT::iterator iter = m_mapSessionNodes.find(strNodeName);
		if (iter != m_mapSessionNodes.end())
		{
			return TRUE;
		}

		return FALSE;
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