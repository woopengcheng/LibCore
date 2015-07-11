#include "GameDB/inc/DBClientManager.h"
#include "GameDB/inc/DBClientNetHandler.h"

namespace GameDB
{

	Net::NetHandlerTransitPtr DBClientManager::OnCreateNetHandler(const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/ , void * context/* = NULL*/)
	{ 
		Assert_Re0(pName && pAddress); 

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(pName);
		if (!pNetHandler)
		{
			Net::ClientSession * pClientSession =  new Net::ClientSession(pAddress , usPort , pName);
			DBClientNetHandlerPtr pNetHandlerClient = DBClientNetHandlerPtr(new DBClientNetHandler(this , m_pNetReactor , pClientSession)); 
			   
			int nResult = pNetHandlerClient->Init(pAddress, usPort); 
			AddRemoteRpc(pClientSession->GetSessionID() , pNetHandlerClient); 

			if(0 == nResult) 
			{  
				m_pNetReactor->AddNetHandler(pNetHandlerClient);  
				pClientSession->SetClosed(FALSE);
				pClientSession->SetNetState(Net::NET_STATE_CONNECTING);
				pClientSession->SetReconnect(FALSE);   //5 断线不重连
				return pNetHandlerClient; 
			}
			else
			{ 
				pClientSession->SetClosed(TRUE);
				pClientSession->SetNetState(Net::NET_STATE_LOSTED); 
				pClientSession->SetReconnect(FALSE);   //5 断线不重连
			}
		}

		return pNetHandler;
	} 
}
 