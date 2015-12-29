#ifndef __net_i_net_reactor_epoll_h__
#define __net_i_net_reactor_epoll_h__ 

#ifdef _LINUX

#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{   
	const INT32 kMAX_EPOOL_WAIT_TIME_OUT = 25;

	class DLL_EXPORT NetReactorEpoll :public INetReactor
	{
	public:
		NetReactorEpoll(UINT32 unMaxConnectionCount);
		virtual ~NetReactorEpoll(void);

	public:
		virtual CErrno		Init( void );
		virtual CErrno		Cleanup( void );
		virtual CErrno		Update( void );

	public:
		virtual CErrno		AddNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno		DelNetHandler(INetHandlerPtr  pNetHandler  , BOOL bEraseHandler = TRUE);
		virtual CErrno		ModNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask);

	protected:
		INT32				m_nEpoll;
		UINT32				m_unMaxConnectionCount;
		struct epoll_event* m_pEvents;
	}; 

	typedef Net::NetReactorEpoll NetReactorDefault;
}
#endif

#endif
