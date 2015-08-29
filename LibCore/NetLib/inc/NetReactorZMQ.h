#ifndef __net_i_net_reactor_zmq_h__
#define __net_i_net_reactor_zmq_h__ 
#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{   
	class DLL_EXPORT NetReactorZMQ :public INetReactor
	{
	public:
		typedef std_unordered_map<UINT32 , UINT32> MapNetEventsT;
		typedef std_unordered_map<UINT32 , INetHandlerPtr> MapNetHandlersT;

	public:
		NetReactorZMQ(  UINT32 unMaxConnectionCount = DEFAULT_MAX_CONNECTION_COUNT  ); 
		virtual ~NetReactorZMQ( void );

	public:
		virtual CErrno   Init( void );
		virtual CErrno   Cleanup( void );
		virtual CErrno   Update( void );

	public:
		virtual CErrno   AddNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno   DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler = TRUE);
		virtual CErrno   ModNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask);
		virtual INetHandlerPtr  GetNetHandler(UINT32  unNetHandlerIndex);

	private: //5 reactor一般都是单线程.所以不必考虑线程安全.如果多线程的话一定不安全.
		UINT32          m_nNetHandlerCount; 
		UINT32          m_unMaxConnectionCount;
		MapNetHandlersT m_mapNetHandlers; 
		 

	}; 

}

#endif
