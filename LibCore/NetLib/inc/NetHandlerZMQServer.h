#ifndef __net_net_handler_zmq_server_h__
#define __net_net_handler_zmq_server_h__ 
#include "NetLib/inc/NetHandlerTransit.h"  
#include "NetLib/inc/MsgProcess.h"

struct zmq_msg_t;

namespace Net 
{   
	typedef void * zmqSocketPtr;
	typedef void * zmqContextPtr; 

	class DLL_EXPORT NetHandlerZMQServer :public NetHandlerTransit
	{
	public:
		NetHandlerZMQServer(INetReactor * pNetReactor , ISession * pSession);
		virtual ~NetHandlerZMQServer();

	public:
		virtual CErrno  Init( const char* ip,int port );
		virtual CErrno  Cleanup( void );
		virtual CErrno  OnClose( void ); 
		  
	public:
		virtual CErrno  OnMsgRecving( void );
		virtual CErrno  OnMsgSending( void ){ return CErrno::Success(); }
		virtual INT32  SendMsg( const char * pBuf , UINT32 unSize ){ return -1; } 
		virtual CErrno  HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength){ return CErrno::Success(); }

	protected:  
		zmqSocketPtr   m_pZmqSocket;
		zmqContextPtr  m_pZmqContext;
		zmq_msg_t    * m_pZmqMsg;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerZMQServer);

}

#endif


