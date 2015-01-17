#ifndef __net_net_handler_zmq_client_h__
#define __net_net_handler_zmq_client_h__ 
#include "NetLib/inc/NetHandlerTransit.h"  
#include "NetLib/inc/MsgProcess.h"
#include "NetLib/inc/ClientSession.h"

struct zmq_msg_t;

namespace Net 
{   
	typedef void * zmqSocketPtr;
	typedef void * zmqContextPtr; 

	class DLL_EXPORT NetHandlerZMQClient :public NetHandlerTransit
	{
	public:
		NetHandlerZMQClient(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL);
		virtual ~NetHandlerZMQClient();
		    
	public:
		virtual INT32  Init( const char* ip,int port );
		virtual INT32  Cleanup( void );
		virtual INT32  OnClose( void ); 
		virtual INT32  Update( void );
		virtual INT32  OnReconnect( void ){ return TRUE; }

	public:
		virtual INT32  OnMsgRecving( void ){ return 0; }
		virtual INT32  OnMsgSending( void ){ return 0; }
		virtual INT32  SendMsg( const char * pBuf , UINT32 unSize );  
		virtual INT32  HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength){ return 0; }
		 
	protected:
		INT32  Connect( const char* ip,int port );
		BOOL   Reconnect(void) 
		{ 
			if (m_pSession && ((Net::ClientSession * )m_pSession)->IsReconnect() && 
				m_pSession->GetNetState() == NET_STATE_LOSTED && m_pSession->IsClosed())
			{
				OnReconnect();
			}
			return TRUE;  
		}

	protected: 
		MsgProcess *   m_pMsgProcess;
		zmqSocketPtr   m_pZmqSocket;
		zmqContextPtr  m_pZmqContext;
		zmq_msg_t   *  m_pZmqMsg;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerZMQClient);
  
}

#endif


