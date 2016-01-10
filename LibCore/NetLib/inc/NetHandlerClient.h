#ifndef __net_net_handler_common_client_h__
#define __net_net_handler_common_client_h__ 
#include "NetLib/inc/NetHandlerTransit.h"
#include "NetLib/inc/MsgProcess.h"
#include "NetLib/inc/ClientSession.h"

struct zmq_msg_t;

namespace Net 
{
	typedef void * zmqSocketPtr;
	typedef void * zmqContextPtr;

	class DLL_EXPORT NetHandlerClient :public NetHandlerTransit
	{
	public:
		NetHandlerClient(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL);
		virtual ~NetHandlerClient();

	public:
		virtual CErrno	Init( void ); 
		virtual CErrno	Init( const char* ip,int port );
		virtual CErrno	Cleanup( void );
		virtual CErrno	OnClose( void );
		virtual CErrno	Update( void );
		virtual CErrno	OnReconnect(void);
		virtual INT32	SendMsg(const char * pBuf, UINT32 unSize);
		virtual CErrno	HandleMsg(ISession * pSession, UINT32 unMsgID, const char* pBuffer, UINT32 unLength);

	public: 
		BOOL			Reconnect(void);
	
	protected:
		BOOL			IsZMQ();
		CErrno			InitZMQ();
		CErrno			InitUDS();
		CErrno			InitRakNet();
		INT32			Connect(const char* ip, int port);
		INT32			ConnectUDS(const char* ip, int port);
		INT32			ConnectUDP(const char* ip, int port);
		INT32			ConnectZMQ(const char* ip, int port);
		INT32			ConnectRakNet(const char* ip, int port);
		INT32			ConnectCommon(const char* ip, int port);
		INT32			SendMsgZMQ(const char * pBuf, UINT32 unSize);

	protected: 
		MsgProcess	*	m_pMsgProcess;
		zmqSocketPtr	m_pZmqSocket;
		zmqContextPtr	m_pZmqContext;
		zmq_msg_t	*	m_pZmqMsg;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerClient);
	  
}

#endif


