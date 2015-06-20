#include "GameDB/inc/DBServerManager.h"
#include "GameDB/inc/DBServerNetHandler.h"
#include "NetLib/inc/ServerSession.h"
#include "GameDB/inc/DBServerNetHandler.h"

namespace GameDB
{
	Net::NetHandlerTransitPtr DBServerManager::OnCreateNetHandler(const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/ , void * context/* = NULL*/)
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
 