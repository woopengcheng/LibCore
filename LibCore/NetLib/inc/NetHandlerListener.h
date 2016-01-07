#ifndef __net_net_handler_listener_h__
#define __net_net_handler_listener_h__  
#include "NetLib/inc/INetHandler.h"

struct sockaddr_in;

namespace Net 
{  
	class INetReactor;

	class DLL_EXPORT NetHandlerListener : public INetHandler
	{
	public:
		NetHandlerListener( INetReactor * pNetReactor , ISession * pSession);
		virtual ~NetHandlerListener( void ){}  

	public:
		virtual CErrno	Init(const char * pAddress , INT32 nPort , BOOL bResueAddr = TRUE , INT32  nListenerCount = DEFAULT_LISTENER_COUNT);
		virtual CErrno	Cleanup(); 
		virtual void	OnAccept(NetSocket socket, sockaddr_in * addr);
		virtual CErrno	OnMsgRecving(void);

	protected:
		void			InitUDS();
		void			InitCommon();
		CErrno			OnMsgRecvingIOCP(void);
		CErrno			OnMsgRecvingCommon(void);
		INT32			Listen(INT32  nListenerCount = DEFAULT_LISTENER_COUNT);
		INT32			Bind(const char * pAddress , INT32 nPort , BOOL bResueAddr = TRUE);
	}; 
	DECLARE_BOOST_POINTERS( NetHandlerListener ); 
}

#endif
