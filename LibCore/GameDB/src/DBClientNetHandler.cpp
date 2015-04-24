#include "GameDB/inc/DBClientNetHandler.h"
#include "TimerLib/inc/TimerHelp.h"

namespace GameDB
{

	DBClientNetHandler::DBClientNetHandler(DBClient  * pDBClient , Net::INetReactor * pNetReactor , Net::ISession * pSession )
		: Net::NetHandlerCommonClient(pNetReactor , pSession)  
		, m_pDBClient(pDBClient)
	{

	}

	DBClientNetHandler::~DBClientNetHandler()
	{
		Cleanup();
		SAFE_DELETE(m_pSession);
	}

	INT32 DBClientNetHandler::Init(const char* ip,int port)
	{
		return Net::NetHandlerCommonClient::Init(ip , port);
	}

	INT32 DBClientNetHandler::Cleanup( void )
	{
		return Net::NetHandlerCommonClient::Cleanup();
	}  

	INT32 DBClientNetHandler::Update( void )
	{
		return Net::NetHandlerCommonClient::Update();
	}

	INT32 DBClientNetHandler::OnReconnect( void )
	{   
		int nResult = -1;
		if (m_pSession && m_pSession->IsClosed())
		{
			nResult = Connect(m_pSession->GetAddress() , m_pSession->GetPort());
			if (!nResult)
			{ 
				m_pSession->SetNetState(Net::NET_STATE_CONNECTING);
				m_pSession->SetClosed(FALSE);
			} 
		}

		return  nResult;  
	} 

	INT32 DBClientNetHandler::OnClose( void )
	{   
		return Net::NetHandlerCommonClient::OnClose(); 
	} 

	INT32 DBClientNetHandler::HandleMsg( Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{ 
		switch(unMsgID)
		{
		case 0:
			{
				std::cout << pBuffer << std::endl;
			}break; 
		default:
			break;
		}

		return ERR_FAILURE;
	} 

}
