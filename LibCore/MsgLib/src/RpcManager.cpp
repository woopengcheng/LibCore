#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RemoteRpcServer.h"
#include "MsgLib/inc/RemoteRpcClient.h" 
#include "MsgLib/inc/RpcBase.h"
#include "Marshal/CStream.h"

namespace Msg
{  
	Net::NetHandlerTransitPtr RpcManager::CreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/ , void * context/* = NULL*/ )
	{
		return OnCreateNetHandler(pName , pAddress , usPort , socket , context);
	} 

	Net::NetHandlerTransitPtr  RpcManager::CreateNetHandler( const char * pName , const char * pAddress , const char * pPort , Net::NetSocket socket /*= 0*/ , void * context/* = NULL*/)
	{ 
		return OnCreateNetHandler(pName , pAddress , atoi(pPort) , socket , context);
	}


	Net::NetHandlerTransitPtr RpcManager::CreateNetHandler( SRpcInfo & objRpcInfo , Net::NetSocket socket /*= 0*/  , void * context/* = NULL*/)
	{
		return OnCreateNetHandler(objRpcInfo.szRemoteName , objRpcInfo.szAddress , objRpcInfo.usPort , socket , context);
	}


	Net::NetHandlerTransitPtr RpcManager::GetNetHandlerByName( std::string strNetHandlerName )
	{
		SRpcInfo * pInfo = GetRpcInfo(strNetHandlerName);
		if (pInfo)
		{
			return GetNetHandlerBySessionID(pInfo->nSessionID);
		}

		return Net::NetHandlerTransitPtr(NULL);
	}


	INT32   RpcManager::CleanupRpcInfo( std::string strRpcInfo )
	{
		MapRpcInfosT::iterator iter = m_mapRpcInfos.find(strRpcInfo);
		if (iter != m_mapRpcInfos.end() )
		{ 
			iter->second.nSessionID = -1;     //5 代表断开了.需要重连.  
			return ERR_SUCCESS;
		}

		return ERR_FAILURE;
	}


	INT32 RpcManager::CleanupRemoteRpc( INT32 nSessionID )
	{
		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerBySessionID(nSessionID);
		if (pNetHandler)
		{  
			pNetHandler->Cleanup(); 

			return ERR_SUCCESS;
		}  

		return ERR_FAILURE;
	}


	INT32 RpcManager::UpdateHandlers( void )
	{
		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.begin();
		for (;iter != m_mapRemoteRpcs.end();)
		{
			{
				Net::NetHandlerTransitPtr pRemoteRpc = iter->second; 
				++iter; 

				pRemoteRpc->Update();   //5 maybe has closed. 
			}
		}

		return ERR_SUCCESS;
	}


	void RpcManager::DelRpcInfo( std::string strRpcInfo )
	{ 
		MapRpcInfosT::iterator iter = m_mapRpcInfos.find(strRpcInfo);
		if (iter != m_mapRpcInfos.end() )
		{
			m_mapRpcInfos.erase(iter);
		}
	}


	SRpcInfo * RpcManager::GetRpcInfo( std::string strRpcInfo )
	{
		MapRpcInfosT::iterator iter = m_mapRpcInfos.find(strRpcInfo);
		if (iter != m_mapRpcInfos.end() )
		{
			return & iter->second;
		}
		return NULL;
	}


	BOOL RpcManager::IsRpcInfoVaild( std::string strRpcInfo )
	{
		SRpcInfo * pInfo = GetRpcInfo(strRpcInfo);
		if ( !pInfo || strcmp(pInfo->szRemoteName , strRpcInfo.c_str()) != 0)
		{
			return ERR_FAILURE; 
		} 

		return ERR_SUCCESS;
	} 

	void RpcManager::InsertSendRpc( UINT64 ullRpcMsgID, Rpc * pRpc )
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

	BOOL RpcManager::ChangeNameBySesson( const INT32 nSessionID , const char * pName)
	{
		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.find(nSessionID);
		if (iter != m_mapRemoteRpcs.end())
		{
			if (strcmp(iter->second->GetSession()->GetRemoteName() , "") == 0)
			{
				iter->second->GetSession()->SetRemoteName(pName);
				return ERR_SUCCESS;
			} 
		}

		return ERR_FAILURE;
	}


	void RpcManager::DelNetHandler( INT32 nSessionID )
	{
		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.find(nSessionID);
		if (iter != m_mapRemoteRpcs.end())
		{
			m_mapRemoteRpcs.erase(iter); 
		}
	}


	void RpcManager::AddNetHandler( INT32 nSessionID , Net::NetHandlerTransitPtr pRpc )
	{
		MapSessionToHandlersT::iterator iterSessions = m_mapRemoteRpcs.find(nSessionID);
		if (iterSessions == m_mapRemoteRpcs.end())
		{
			m_mapRemoteRpcs.insert(std::make_pair(nSessionID , pRpc)); 
		}
		else
		{
			iterSessions->second = pRpc;
		}
	}


	void RpcManager::AddRpcInfo( SRpcInfo & objRpcInfo )
	{
		RpcManager::MapRpcInfosT::iterator iterName = m_mapRpcInfos.find(objRpcInfo.szRemoteName);
		if(iterName == m_mapRpcInfos.end() ) 
		{
			m_mapRpcInfos.insert(std::make_pair(objRpcInfo.szRemoteName , objRpcInfo)); 
		}
		else
		{ 
			iterName->second = objRpcInfo; 
		} 
	}


	BOOL RpcManager::IsHasSessionByName( const char * pRpcServerName )
	{
		Net::NetHandlerTransitPtr pHandler = RpcManager::GetHandlerByName( pRpcServerName ) ;
		if (pHandler.get() && pHandler->GetSession())
		{
			return (pHandler->GetSession()->GetSessionID() != -1) ? TRUE : FALSE;
		}

		return FALSE;
	}


	Net::NetHandlerTransitPtr RpcManager::GetNetHandlerBySessionID( INT32 nSessionID )
	{
		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.find(nSessionID);
		if (iter == m_mapRemoteRpcs.end())
		{
			return NULL;
		}
		else
		{
			return iter->second;
		} 
	}


	Net::NetHandlerTransitPtr RpcManager::GetHandlerBySimilarName( const char * pRpcServerName )
	{
		MapRpcInfosT::iterator iter = m_mapRpcInfos.begin();
		for(;iter != m_mapRpcInfos.end();++iter)
		{
			if (iter->first.find(pRpcServerName) != std::string::npos)
			{
				return GetHandlerByName(iter->first.c_str());
			}
		} 

		return Net::NetHandlerTransitPtr(NULL); 
	}


	Net::NetHandlerTransitPtr RpcManager::GetHandlerByName( const char * pRpcServerName ) 
	{ 
		int nSeesionID = -1;
		MapRpcInfosT::iterator iter = m_mapRpcInfos.find(pRpcServerName);
		if(iter != m_mapRpcInfos.end() )
		{
			nSeesionID = iter->second.nSessionID; 
		} 

		if (nSeesionID != -1)
		{
			return GetNetHandlerBySessionID(nSeesionID);
		}

		return Net::NetHandlerTransitPtr(NULL); 
	}


	INT32 RpcManager::HandleMsg( Net::ISession * pSession , RPCMsgCall * pMsg )
	{ 
		return ERR_SUCCESS;
	}


	INT32 RpcManager::SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		if (pRemoteRpc && pRemoteRpc->GetSession()->GetSessionID() != -1 && 
			!pRemoteRpc->GetSession()->IsClosed() && ( pRemoteRpc->GetSession()->GetNetState() != Net::NET_STATE_LOSTED && 
			bForce || pRemoteRpc->GetSession()->GetNetState() == Net::NET_STATE_CONNECTED)) 
		{  
			char szBuf[MAX_MESSAGE_LENGTH]; 
			((Net::MsgHeader*)szBuf)->unMsgID = unMsgID;
			((Net::MsgHeader*)szBuf)->unMsgLength = unLength + sizeof(Net::MsgHeader); 
			memcpy(szBuf + sizeof(Net::MsgHeader) , pBuffer , unLength); 

			return pRemoteRpc->SendMsg(szBuf , unLength + sizeof(Net::MsgHeader));
		}

		return ERR_FAILURE;
	}


	INT32 RpcManager::SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pRpcMsg , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{  
		if (pRemoteRpc && pRemoteRpc->GetSession()->GetSessionID() != -1 && 
			!pRemoteRpc->GetSession()->IsClosed() && ( pRemoteRpc->GetSession()->GetNetState() != Net::NET_STATE_LOSTED && 
			bForce || pRemoteRpc->GetSession()->GetNetState() == Net::NET_STATE_CONNECTED))
		{   

//  		char szBuf[MAX_MESSAGE_LENGTH]; 
// 			memset(szBuf , 0 , sizeof(szBuf));
// 			UINT32 unSerializationSize = pRpcMsg->Serialization(szBuf + sizeof(Net::MsgHeader)); 
			CUtil::CStream objStream;
			pRpcMsg->marshal(objStream);
			UINT32 unSerializationSize = objStream.GetDataLen();//pRpcMsg->GetPacketSize();
		
//			MsgAssert_ReF1(unSerializationSize == objStream.GetDataLen() , "sendMsg Length error. " << unSerializationSize << " stream: " <<objStream.GetDataLen());
			
			INT32 nMsgID = DEFAULT_RPC_MSG_ID , nMsgLength = unSerializationSize + sizeof(Net::MsgHeader);
			objStream.Insert(objStream.Begin() , &nMsgLength , sizeof(nMsgLength));
			objStream.Insert((char *)objStream.Begin() + sizeof(nMsgLength) , &nMsgID , sizeof(nMsgID));
//			((Net::MsgHeader*)szBuf)->unMsgID = DEFAULT_RPC_MSG_ID;
//			((Net::MsgHeader*)szBuf)->unMsgLength = unSerializationSize + sizeof(Net::MsgHeader);  

			return pRemoteRpc->SendMsg((const char *)objStream.Begin() , nMsgLength); 
		}

		return -1;
	}


	INT32 RpcManager::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{
		return ERR_FAILURE; 
	}


	INT32 RpcManager::SendMsg( const char * pRpcServerName , RPCMsgCall * pMsg  , BOOL bForce/* = FALSE*/ , BOOL bAddRpc/* = TRUE*/)
	{ 
		MapRpcInfosT::iterator iter = m_mapRpcInfos.find(pRpcServerName);
		if(iter != m_mapRpcInfos.end() ) 
		{
			return SendMsg(iter->second.nSessionID , pMsg , bForce , bAddRpc);
		}
		return ERR_FAILURE;
	}


	INT32 RpcManager::Update( void )
	{ 
		UpdateHandlers();

		return ERR_SUCCESS;
	}


	INT32 RpcManager::Cleanup( void )
	{  
		m_mapRemoteRpcs.clear();

		m_mapRpcInfos.clear();
		return ERR_SUCCESS;
	}


	INT32 RpcManager::Init( void )
	{ 

		return ERR_SUCCESS; 
	}


	INT32 RpcManager::DelRemoteRpc( INT32 nSessionID )
	{  
		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerBySessionID(nSessionID);
		if (pNetHandler)
		{
			std::string strRemoteName = pNetHandler->GetSession()->GetRemoteName(); 
			DelRpcInfo(strRemoteName);
		}

		DelNetHandler(nSessionID);

		return ERR_SUCCESS;
	}


	INT32 RpcManager::AddRemoteRpc( INT32 nSessionID , Net::NetHandlerTransitPtr pRpc )
	{
		Assert_ReF1(pRpc.get());

		AddNetHandler(nSessionID , pRpc);

		Net::ISession * pSeesion = pRpc->GetSession(); 
		SRpcInfo objRpcInfo(pSeesion->GetRemoteName() , pSeesion->GetAddress() , pSeesion->GetPort() , pSeesion->GetSessionID());

		AddRpcInfo(objRpcInfo);

		return ERR_SUCCESS;
	}

	BOOL RpcManager::IsConnected(const char * pRpcServerName)
	{
		Net::NetHandlerTransitPtr pHandler = GetHandlerByName(pRpcServerName);
		if (pHandler && pHandler->GetSession())
		{
			if(Net::NET_STATE_CONNECTED == pHandler->GetSession()->GetNetState())
				return TRUE;
		}
		return FALSE;
	}

	BOOL RpcManager::IsConnected(INT32 nSessionID)
	{
		Net::NetHandlerTransitPtr pHandler = GetNetHandlerBySessionID(nSessionID);
		if (pHandler && pHandler->GetSession())
		{
			if(Net::NET_STATE_CONNECTED == pHandler->GetSession()->GetNetState())
				return TRUE;
		}
		return FALSE;
	}

	BOOL RpcManager::IsAllConnected()
	{
		BOOL bSuccess = TRUE;
		MapSessionToHandlersT::iterator iter = m_mapRemoteRpcs.begin();
		for (;iter != m_mapRemoteRpcs.end();++iter)
		{
			Net::NetHandlerTransitPtr pHandler = iter->second; 
			 
			if (pHandler && pHandler->GetSession())
			{
				if(Net::NET_STATE_CONNECTED != pHandler->GetSession()->GetNetState())
					bSuccess = FALSE;
			}
		}

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