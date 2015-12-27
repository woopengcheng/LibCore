#ifndef __net_i_net_reactor_wes_h__
#define __net_i_net_reactor_wes_h__ 

#ifdef _MSC_VER
#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{   
#ifndef WSAEVENT
#define WSAEVENT                HANDLE
#endif

	const INT32 kMAX_EPOOL_WAIT_TIME_OUT = 25;

	class DLL_EXPORT NetReactorWES :public INetReactor
	{
	public:
		NetReactorWES(UINT32 unMaxConnectionCount = DEFAULT_MAX_CONNECTION_COUNT);
		virtual ~NetReactorWES(void);

	public:
		virtual CErrno		Init( void );
		virtual CErrno		Cleanup( void );
		virtual CErrno		Update( void );

	public:
		virtual CErrno		AddNetHandler(INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno		DelNetHandler(INetHandlerPtr  pNetHandler  , BOOL bEraseHandler = TRUE);
		virtual CErrno		ModNetHandler(INetHandlerPtr  pNetHandler, ENetHandlerFuncMask objMask);

	protected:
		INT32				GetIndexByNetHandler(INetHandlerPtr	pNetHandler);
		CErrno				iUpdate(INT32 start, INT32 end);

	protected:
		UINT32				m_unMaxConnectionCount;
		INT32				m_nNumConnection;
		INetHandlerPtr	*	m_pConnections;
		WSAEVENT		*	m_pEvents;
	}; 

	typedef Net::NetReactorWES NetReactorDefault;
}
#endif

#endif
