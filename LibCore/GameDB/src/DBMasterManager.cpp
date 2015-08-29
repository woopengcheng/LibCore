#include "GameDB/inc/DBMasterManager.h"
#include "GameDB/inc/DBServerNetHandler.h"
#include "GameDB/inc/MasterSession.h"
#include "MsgLib/inc/RpcClientManager.h"
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBServerNetHandler.h"
#include "MsgLib/inc/IRpcListener.h"
#include "MsgLib/inc/ping.h"
#include "MsgLib/inc/NetNode.h"

namespace GameDB
{
#ifdef USE_ZMQ
	CErrno DBMasterManager::HandlePing( Net::ISession * pSession , Msg::SPing * pPing )
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
					m_pRpcInterface->GetRpcListener()->OnConnected(m_pRpcInterface);  
				} 
			}  

			gDebugStream("zmq recv client ping. " << strRemoteRPCName << std::endl);
		}  

		return TRUE;
	} 

#else
	CErrno DBMasterManager::HandlePing( Net::ISession * pSession , Msg::SPing * pPing )
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

				AddRpcInfo(Msg::SRpcInfo(pSession->GetRemoteName() , pSession->GetAddress() , pSession->GetPort() , pSession->GetSessionID()));
			} 

			Msg::RpcClientManager *  pRpcClientManager = m_pRpcInterface->GetRpcClientManager();
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

			//			gDebugStream("recv client ping. " << strRemoteRPCName << std::endl);
		}  

		return CErrno::Success();
	}  
#endif

	Net::NetHandlerTransitPtr DBMasterManager::OnCreateNetHandler(const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/ , void * context/* = NULL*/)
	{ 
		Assert_Re0(pAddress);   
		std::string strRemoteName = Net::NetHelper::GenerateRemoteName(m_pRpcInterface->GetServerType()  , pAddress , usPort );

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(strRemoteName.c_str());
		if (!pNetHandler)
		{
#ifdef USE_ZMQ
			MasterSession * pServerSession =  new MasterSession((SDBMasterInfo *)context , pAddress , usPort , pName , -1 , 0 , socket);
			pServerSession->SetNetState(Net::NET_STATE_CONNECTED); 
#else
			MasterSession * pServerSession =  new MasterSession((SDBMasterInfo *)context , pAddress , 0 , pName , -1 , 0 , socket);
			pServerSession->SetNetState(Net::NET_STATE_CONNECTING);
#endif
			DBServerNetHandlerPtr pRpcServer(new DBServerNetHandler(this , m_pNetReactor , pServerSession)); 
			pServerSession->SetClosed(FALSE);

			gDebugStream("accept: ID: " << pServerSession->GetSessionID());

			AddRemoteRpc(pServerSession->GetSessionID() , pRpcServer); 

			m_pNetReactor->AddNetHandler(pRpcServer);

			return pRpcServer;  
		}

		return pNetHandler;
	} 

}
