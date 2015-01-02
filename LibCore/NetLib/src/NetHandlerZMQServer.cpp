extern "C"
{
#include "zmq.h" 
}
#include "NetHandlerZMQServer.h"
#include "NetHelper.h"
#include "INetReactor.h" 

namespace Net
{   
	NetHandlerZMQServer::NetHandlerZMQServer( INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess /*= NULL*/ ) 
		: NetHandlerTransit(pNetReactor , pSession)   
	{   
		void * pContext = zmq_init (1);
		if (!pContext) {
			PAssert(0 && "error in zmq_init", zmq_strerror (errno)); 
		}
		m_pZmqContext  = pContext;

		void * pSocket = zmq_socket (pContext, ZMQ_PULL);
		if (!pSocket) {
			PAssert(0 && "error in zmq_socket", zmq_strerror (errno)); 
		}
		m_pZmqSocket  = pSocket; 
		 
		m_pZmqMsg = new zmq_msg_t;

		Init(pSession->GetAddress() , pSession->GetPort());
	}

	NetHandlerZMQServer::~NetHandlerZMQServer()
	{  
		INT32 nResult = zmq_close (m_pZmqSocket);
		if (nResult != 0) {
			PAssert(0 && "error in zmq_close", zmq_strerror (errno)); 
		}

		nResult = zmq_term (m_pZmqContext);
		if (nResult != 0) {
			PAssert(0 && "error in zmq_term:", zmq_strerror (errno)); 
		} 

		SAFE_DELETE(m_pZmqMsg);
	} 

	INT32 NetHandlerZMQServer::Init( const char* ip,int port )
	{   
		m_pSession->SetAddress(ip);
		m_pSession->SetSocktPort(port);

		if (m_pSession->GetNetState() == Net::NET_STATE_LOSTED)
		{
			char szPort[20];
			std::string str = "tcp://";
			str += ip;
//			str += "*";
			str += ":";
			itoa(port , szPort , 10);
			str += szPort;  
			 
			INT32 nResult = zmq_bind (m_pZmqSocket , str.c_str());
			if (nResult != 0) 
			{
				printf ("error in zmq_bind: %s\n", zmq_strerror (errno));
				return -1;
			}
			 
			return INetHandler::Init();
		}
		return -1;  
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
			printf ("error in zmq_msg_init: %s\n", zmq_strerror (errno));
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
	
		HandleMsg(m_pSession , pHeader->unMsgID , (char *)pBuf + sizeof(MsgHeader) , usSize - sizeof(MsgHeader));

		nResult = zmq_msg_close (m_pZmqMsg);
		if (nResult != 0) {
			printf ("error in zmq_msg_close: %s\n", zmq_strerror (errno));
			return -1;
		} 
		return nResult;
	}


}