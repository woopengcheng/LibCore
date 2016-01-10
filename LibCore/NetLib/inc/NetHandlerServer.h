#ifndef __net_net_handler_common_server_h__
#define __net_net_handler_common_server_h__ 
#include "NetLib/inc/NetHandlerTransit.h"

struct zmq_msg_t;

namespace Net 
{
	typedef void * zmqSocketPtr;
	typedef void * zmqContextPtr;

	class DLL_EXPORT NetHandlerServer :public NetHandlerTransit
	{
	public:
		NetHandlerServer(INetReactor * pNetReactor, ISession * pSession);
		virtual ~NetHandlerServer();

	public:
		virtual CErrno  OnClose( void )     ;

	public:
		virtual CErrno  OnMsgRecving(void);
		virtual INT32	SendMsg(const char * pBuf, UINT32 unSize);
		virtual CErrno	HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);

	protected:
		BOOL			IsZMQ();
		CErrno			InitZMQ();
		CErrno			InitUDP();
		CErrno			InitUDS();
		CErrno			InitRakNet();
		CErrno			Init(const char* ip, int port);
		CErrno			OnMsgRecvingZMQ(void);

	protected:
		zmqSocketPtr   m_pZmqSocket;
		zmqContextPtr  m_pZmqContext;
		zmq_msg_t    * m_pZmqMsg;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerServer);
	 
}

#endif 