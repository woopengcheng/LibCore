#ifndef __net_i_net_reactor_epoll_h__
#define __net_i_net_reactor_epoll_h__ 
#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{   
	class DLL_EXPORT NetReactorEpoll :public INetReactor
	{
	public:
		NetReactorEpoll( void ){}
		virtual ~NetReactorEpoll( void ){}

	public:
		virtual CErrno   Init( void );
		virtual CErrno   Cleanup( void );
		virtual CErrno   Update( void );

	public:
		virtual CErrno   AddNetHandler(INetHandlerPtr  pNetHandler   , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno   DelNetHandler(INetHandlerPtr  pNetHandler  );
		virtual CErrno   ModNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask);

	}; 

}

#endif
