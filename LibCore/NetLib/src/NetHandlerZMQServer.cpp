extern "C"
{
#include "zmq.h" 
}
#include "NetLib/inc/NetHandlerZMQServer.h"
#include "NetLib/inc/NetHelper.h"
#include "NetLib/inc/INetReactor.h" 
#include "Common/CUtil.h"

namespace Net
{   
	NetHandlerZMQServer::NetHandlerZMQServer( INetReactor * pNetReactor , ISession * pSession ) 
		: NetHandlerTransit(pNetReactor , pSession)   
	{   
		void * pContext = zmq_init (1);
		MsgAssert(pContext , zmq_strerror (errno) << "error in zmq_init"); 

		m_pZmqContext  = pContext;

		void * pSocket = zmq_socket (pContext, ZMQ_PULL);
		MsgAssert(pSocket , zmq_strerror (errno) << "error in zmq_socket"); 

		m_pZmqSocket  = pSocket; 
		 
		m_pZmqMsg = new zmq_msg_t;

		Init(pSession->GetAddress() , pSession->GetPort());
	}

	NetHandlerZMQServer::~NetHandlerZMQServer()
	{  
		MsgAssert(!zmq_close (m_pZmqSocket) , zmq_strerror (errno) << "error in zmq_close");   
		MsgAssert(!zmq_term (m_pZmqContext) , zmq_strerror (errno) << "error in zmq_term:"); 

		SAFE_DELETE(m_pZmqMsg);
	} 

	INT32 NetHandlerZMQServer::Init( const char* ip,int port )
	{   
		m_pSession->SetAddress(ip);
		m_pSession->SetSocktPort(port);
		  
		std::string str = "tcp://";
		str += ip; 
		str += ":";
		str += CUtil::itoa(port); 
			 
		MsgAssert_ReF1(!zmq_bind (m_pZmqSocket , str.c_str()) , zmq_strerror (errno)); 
			 
		return INetHandler::Init(); 
	}

	INT32 NetHandlerZMQServer::Cleanup(void)
	{ 
		return INetHandler::Cleanup();
	}
	 
	INT32 NetHandlerZMQServer::OnClose(void)
	{
		return INetHandler::OnClose();
	}

	INT32 NetHandlerZMQServer::OnMsgRecving( void )
	{
		int nResult = zmq_msg_init (m_pZmqMsg);
		if (nResult != 0) 
		{
			gErrorStream("error in zmq_msg_init: %s\n" << zmq_strerror (errno));
			return -1;
		}

		nResult = zmq_recvmsg (m_pZmqSocket , m_pZmqMsg, ZMQ_DONTWAIT);
		if (nResult < 0) 
		{
			if (zmq_errno() == EAGAIN)
			{
				nResult = zmq_msg_close (m_pZmqMsg);
				if (nResult != 0) {
					printf ("error in zmq_msg_close: %s\n", zmq_strerror (errno));
					return -1;
				} 
				return 0;
			}
			
			printf ("error in zmq_recvmsg: %s\n", zmq_strerror (errno));
			return -1;
		}
		void * pBuf = zmq_msg_data(m_pZmqMsg);
		size_t usSize = zmq_msg_size(m_pZmqMsg);
		MsgHeader * pHeader = (MsgHeader*)pBuf;
	
		HandleMsg(m_pSession , pHeader->unMsgID , (char *)pBuf + sizeof(MsgHeader) , (UINT32)(usSize - sizeof(MsgHeader)));

		nResult = zmq_msg_close (m_pZmqMsg);
		if (nResult != 0) {
			printf ("error in zmq_msg_close: %s\n", zmq_strerror (errno));
			return -1;
		} 
		return nResult;
	}


}