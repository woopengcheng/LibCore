#include "GameDB/inc/DBServerNetHandler.h"
#include "TimerLib/inc/TimerHelp.h"

namespace GameDB
{


	DBServerNetHandler::DBServerNetHandler(DBServer	* pDBServer , Net::INetReactor * pNetReactor, Net::ISession * pSession )
		: Net::NetHandlerCommonServer(pNetReactor , pSession) 
		, m_pDBServer(pDBServer)
	{
		SetLastRecvPingTime();
	} 


	DBServerNetHandler::~DBServerNetHandler()
	{ 
		Cleanup();
		SAFE_DELETE(m_pSession);
	} 


	void DBServerNetHandler::SetLastRecvPingTime( INT64 ullLstRecfPing /*= 0*/ )
	{
		if (ullLstRecfPing == 0)
		{
			m_ullLastRecvPing = Timer::TimerHelper::GetTickCount(); 
		}
		else
		{
			m_ullLastRecvPing = ullLstRecfPing; 
		}  
	}


	INT32 DBServerNetHandler::Update( void )
	{  
		UpdatePing(); 
		return NetHandlerTransit::Update();
	}


	INT32 DBServerNetHandler::UpdatePing( void )
	{
// 		if (m_ullLastRecvPing == 0)
// 		{
// 			SetLastRecvPingTime();
// 		} 
//  
// 		INT64 ullCurTime = Timer::TimerHelper::GetTickCount();
// 		INT64 nDiffTime = Timer::TimerHelper::GetTickSecond(ullCurTime - m_ullLastRecvPing);
// 		if (nDiffTime >= DEFAULT_RPC_PING_TIMEOUT * 3 && m_pSession )
// 		{
// 			gErrorStream ("timeout close " << m_pSession->GetRemoteName());
// 			m_pSession->SetClosed(TRUE);  
// 		} 

		return ERR_SUCCESS;
	}


	INT32 DBServerNetHandler::OnClose( void )
	{   
		if(GetSession() && GetSession()->GetSessionID() != -1)
		{   
			GetSession()->SetClosed(TRUE);
			GetSession()->SetNetState(Net::NET_STATE_LOSTED); 
		}  

		return NetHandlerCommonServer::OnClose(); 
	}


	INT32 DBServerNetHandler::HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		switch(unMsgID)
		{
		case 0:
			{
				std::cout << pBuffer << std::endl;

				char pBuf[1024]; 
				((Net::MsgHeader*)pBuf)->unMsgID = 0;
				((Net::MsgHeader*)pBuf)->unMsgLength = 6+ sizeof(Net::MsgHeader);
				memcpy(pBuf + sizeof(Net::MsgHeader) , "ddddd" , 6);
				SendMsg(pBuf , 6 + sizeof(Net::MsgHeader));

// 				Assert_ReF1(pBuffer && unLength == sizeof(SPing));   
// 
// 				SPing objPing;
// 				memcpy(&objPing , pBuffer , unLength);
// 
// 				SetLastRecvPingTime();
//				return m_pRpcManager->HandlePing(pSession , &objPing);  
			}
			break;
		default:
			break;
		}

		return ERR_FAILURE;
	}}
