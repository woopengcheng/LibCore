#include "NetLib/inc/NetHandlerCommonServer.h"
#include "NetLib/inc/ISession.h"
#include "NetLib/inc/NetHelper.h" 

namespace Net
{   
	CErrno  NetHandlerCommonServer::HandleMsg( ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		printf("%s" , pBuffer);

		char pBuf[1024]; 
		((Net::MsgHeader*)pBuf)->unMsgID = 0;
		((Net::MsgHeader*)pBuf)->unMsgLength = 6 + sizeof(Net::MsgHeader);
		memcpy(pBuf + sizeof(Net::MsgHeader) , "woope" , 6);
		SendMsg(pBuf , 6 + sizeof(Net::MsgHeader)); 

		return CErrno::Success();
	}

	CErrno NetHandlerCommonServer::OnClose( void )
	{ 
		return NetHandlerTransit::OnClose();
	}

	NetHandlerCommonServer::~NetHandlerCommonServer()
	{  
	} 

}