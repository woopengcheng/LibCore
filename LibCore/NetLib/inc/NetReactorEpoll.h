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
		virtual INT32   Init( void );
		virtual INT32   Cleanup( void );
		virtual INT32   Update( void );

	public:
		virtual INT32   AddNetHandler(INetHandlerPtr  pNetHandler   , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual INT32   DelNetHandler(INetHandlerPtr  pNetHandler  );
		virtual INT32   ModNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask);

	}; 

}

#endif
