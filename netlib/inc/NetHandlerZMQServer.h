#ifndef __net_net_handler_zmq_server_h__
#define __net_net_handler_zmq_server_h__ 
extern "C"
{
	#include "zmq.h" 
}
#include "INetHandler.h"  
#include "MsgProcess.h"

namespace Net 
{   
	typedef void * zmqSocketPtr;
	typedef void * zmqContextPtr;
	// 	typedef boost::shared_ptr<zmqSocket> zmqSocketPtr;
	// 	typedef boost::shared_ptr<zmqSocket> zmqContextPtr;

	class DLL_EXPORT NetHandlerZMQServer :public INetHandler
	{
	public:
		NetHandlerZMQServer(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL);
		virtual ~NetHandlerZMQServer();

	public:
		virtual INT32  Init( const char* ip,int port );
		virtual INT32  Cleanup( void );
		virtual INT32  OnClose( void ); 
		 
	public:
		virtual INT32  OnMsgRecving( void );
		virtual INT32  HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength){ return 0; }

	protected:  
		zmqSocketPtr   m_pZmqSocket;
		zmqContextPtr  m_pZmqContext;
		zmq_msg_t      m_zmqMsg;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerZMQServer);
}

#endif


