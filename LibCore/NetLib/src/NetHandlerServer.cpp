#include "NetHandlerServer.h"
#include "ISession.h"
#include "NetHelper.h" 

namespace Net
{   
	INT32  NetHandlerServer::HandleMsg( ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength )
	{
		printf("%s" , pBuffer);

		char pBuf[1024]; 
		((Net::MsgHeader*)pBuf)->unMsgID = 0;
		((Net::MsgHeader*)pBuf)->unMsgLength = 6 + sizeof(Net::MsgHeader);
		memcpy(pBuf + sizeof(Net::MsgHeader) , "woope" , 6);
		SendMsg(pBuf , 6 + sizeof(Net::MsgHeader)); 
		return TRUE;
	}

	INT32 NetHandlerServer::OnClose( void )
	{ 
		return NetHandlerTransit::OnClose();
	}

	NetHandlerServer::~NetHandlerServer()
	{  
	} 

}