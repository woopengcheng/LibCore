#include "NetHandlerZMQClient.h"
#include "NetHelper.h"
#include "INetReactor.h" 

namespace Net
{   
	NetHandlerZMQClient::NetHandlerZMQClient( INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess /*= NULL*/ ) 
		: NetHandlerTransit(pNetReactor , pSession)  
		, m_pMsgProcess(pMsgProcess)
	{   
		void * pContext = zmq_init (1);
		if (!pContext) {
			PAssert(0 && "error in zmq_init", zmq_strerror (errno)); 
		}
		m_pZmqContext  = pContext;

		void * pSocket = zmq_socket (pContext, ZMQ_PUSH);
		if (!pSocket) {
			PAssert(0 && "error in zmq_socket", zmq_strerror (errno)); 
		}
		m_pZmqSocket  = pSocket; 
	}

	NetHandlerZMQClient::~NetHandlerZMQClient()
	{  
		INT32 nResult = zmq_close (m_pZmqSocket);
		if (nResult != 0) {
			PAssert(0 && "error in zmq_close", zmq_strerror (errno)); 
		}

		nResult = zmq_term (m_pZmqContext);
		if (nResult != 0) {
			PAssert(0 && "error in zmq_term:", zmq_strerror (errno)); 
		} 
	} 

	INT32 NetHandlerZMQClient::Init( const char* ip,int port )
	{   
		m_pSession->SetAddress(ip);
		m_pSession->SetSocktPort(port);
		 
		if (m_pSession->IsClosed() && !Connect(ip , port))
		{

// 			INT32 nResult = zmq_bind (m_pZmqSocket.get() , str.c_str());
// 			if (nResult != 0) {
// 				printf ("error in zmq_bind: %s\n", zmq_strerror (errno));
// 				return -1;
// 			}
			gDebugStream("Connect Init " << m_pSession->GetRemoteName());
			return INetHandler::Init();
		}
		return -1;  
	}

	INT32 NetHandlerZMQClient::Cleanup(void)
	{ 
		return INetHandler::Cleanup();
	}

	INT32 NetHandlerZMQClient::Connect( const char* ip,int port )
	{ 
		char szPort[20];
		std::string str = "TCP://";
		str += ip;
		str += ":";
		itoa(port , szPort , 10);
		str += szPort;  

		INT32 nResult = zmq_connect (m_pZmqSocket , str.c_str());
		if (nResult != 0) {
			printf ("error in zmq_connect: %s\n", zmq_strerror (errno));
			return -1;
		}

		return  0;
	}

	INT32 NetHandlerZMQClient::OnClose(void)
	{
		return INetHandler::OnClose();
	}

	INT32 NetHandlerZMQClient::SendMsg( const char * pBuf , UINT32 unSize )
	{ 
// 		int nResult = zmq_msg_init_size (&m_zmqMsg, unSize);
// 		if (nResult != 0) {
// 			printf ("error in zmq_msg_init_size: %s\n", zmq_strerror (errno));
// 			return -1;
// 		}

		int nResult = zmq_msg_init_data(&m_zmqMsg, (void *)pBuf , unSize , NULL , NULL);
		if (nResult != 0) {
			printf ("error in zmq_msg_init_size: %s\n", zmq_strerror (errno));
			return -1;
		}

		nResult = zmq_sendmsg (m_pZmqSocket, &m_zmqMsg, 0);
		if (nResult < 0) {
			printf ("error in zmq_sendmsg: %s\n", zmq_strerror (errno));
			return -1;
		}

		nResult = zmq_msg_close (&m_zmqMsg);
		if (nResult != 0) {
			printf ("error in zmq_msg_close: %s\n", zmq_strerror (errno));
			return -1;
		} 

		return nResult;
	}



}