#ifndef __net_i_net_reactor_iocp_h__
#define __net_i_net_reactor_iocp_h__ 

#ifdef _MSC_VER

#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{   
	class DLL_EXPORT NetReactorIOCP :public INetReactor
	{
	public:
		NetReactorIOCP(UINT32 unMaxConnectionCount);
		virtual ~NetReactorIOCP(void);

	public:
		virtual CErrno		Init( void );
		virtual CErrno		Cleanup( void );
		virtual CErrno		Update( void );

	public:
		virtual CErrno		AddNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno		DelNetHandler(INetHandlerPtr  pNetHandler  , BOOL bEraseHandler = TRUE);
		virtual CErrno		ModNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask);

	protected:
		UINT32				m_unMaxConnectionCount;
	}; 

}
#endif

#endif
