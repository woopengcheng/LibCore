#include "GameDB/inc/DBSlaveManager.h"
#include "GameDB/inc/DBSlaveNetHandler.h"
#include "GameDB/inc/SlaveSession.h"

namespace GameDB
{


	Net::NetHandlerTransitPtr DBSlaveManager::OnCreateNetHandler(const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket /*= 0*/ , void * context/* = NULL*/)
	{

		Assert_Re0(pName && pAddress); 

		Net::NetHandlerTransitPtr pNetHandler = GetNetHandlerByName(pName);
		if (!pNetHandler)
		{
			SlaveSession * pClientSession =  new SlaveSession((SDBSlaveInfo *)context , pAddress , usPort , pName );
			DBSlaveNetHandlerPtr pNetHandlerClient = DBSlaveNetHandlerPtr(new DBSlaveNetHandler(this , m_pNetReactor , pClientSession)); 

			int nResult = pNetHandlerClient->Init(pAddress, usPort); 
			AddRemoteRpc(pClientSession->GetSessionID() , pNetHandlerClient); 

			if(0 == nResult) 
			{  
				m_pNetReactor->AddNetHandler(pNetHandlerClient);  
				pClientSession->SetClosed(FALSE);
				pClientSession->SetNetState(Net::NET_STATE_CONNECTING);
				pClientSession->SetReconnect(TRUE);   //5 断线重连
				return pNetHandlerClient; 
			}
			else
			{ 
				pClientSession->SetClosed(TRUE);
				pClientSession->SetNetState(Net::NET_STATE_LOSTED); 
				pClientSession->SetReconnect(TRUE);   //5 断线重连
			}
		}

		return pNetHandler;
	}

}