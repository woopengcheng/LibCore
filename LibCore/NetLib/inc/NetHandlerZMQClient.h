#ifndef __net_net_handler_zmq_client_h__
#define __net_net_handler_zmq_client_h__ 
extern "C"
{
	#include "zmq.h" 
}
#include "NetHandlerTransit.h"  
#include "MsgProcess.h"

namespace Net 
{   
	typedef void * zmqSocketPtr;
	typedef void * zmqContextPtr;
// 	typedef boost::shared_ptr<zmqSocket> zmqSocketPtr;
// 	typedef boost::shared_ptr<zmqSocket> zmqContextPtr;

	class DLL_EXPORT NetHandlerZMQClient :public NetHandlerTransit
	{
	public:
		NetHandlerZMQClient(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL);
		virtual ~NetHandlerZMQClient();
		    
	public:
		virtual INT32  Init( const char* ip,int port );
		virtual INT32  Cleanup( void );
		virtual INT32  OnClose( void ); 

	public:
		virtual INT32  OnMsgRecving( void ){ return 0; }
		virtual INT32  OnMsgSending( void ){ return 0; }
		virtual INT32  SendMsg( const char * pBuf , UINT32 unSize );  
		virtual INT32  HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength){ return 0; }
		 
	protected:
		INT32  Connect( const char* ip,int port );

	protected: 
		MsgProcess *   m_pMsgProcess;
		zmqSocketPtr   m_pZmqSocket;
		zmqContextPtr  m_pZmqContext;
		zmq_msg_t      m_zmqMsg;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerZMQClient);
}

#endif


