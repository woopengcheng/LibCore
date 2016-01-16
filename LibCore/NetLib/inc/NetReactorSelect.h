#ifndef __net_i_net_reactor_select_h__
#define __net_i_net_reactor_select_h__ 
#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{   
	class DLL_EXPORT NetReactorSelect :public INetReactor
	{
	public:
		typedef std_unordered_map<UINT32 , UINT32> MapNetEventsT;
		typedef std_unordered_map<UINT32 , INetHandlerPtr> MapNetHandlersT;

	public:
		explicit NetReactorSelect(UINT32 unMaxConnectionCount = DEFAULT_MAX_CONNECTION_COUNT , NetThread * pThread = NULL);
		virtual ~NetReactorSelect( void );

	public:
		virtual CErrno			Init( void );
		virtual CErrno			Cleanup( void );
		virtual CErrno			Update( void );

	public:
		virtual CErrno			AddNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno			DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler = TRUE);
		virtual CErrno			ModNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask);

	private: //5 reactorһ�㶼�ǵ��߳�.���Բ��ؿ����̰߳�ȫ.������̵߳Ļ�һ������ȫ.
		UINT32					m_nNetHandlerCount;
		UINT32					m_unMaxConnectionCount;
		MapNetEventsT			m_mapNetEvents;
		MapNetHandlersT			m_mapNetHandlers;

	private:
		void				*	m_pFdSetReads;
		void				*	m_pFdSetWrites;
		void				*	m_pFdSetExcepts;
	}; 

	typedef Net::NetReactorSelect NetReactorDefault;
}

#endif
