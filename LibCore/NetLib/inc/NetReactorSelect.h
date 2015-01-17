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
		NetReactorSelect(  UINT32 unMaxConnectionCount = DEFAULT_MAX_CONNECTION_COUNT  ); 
		virtual ~NetReactorSelect( void );

	public:
		virtual INT32   Init( void );
		virtual INT32   Cleanup( void );
		virtual INT32   Update( void );

	public:
		virtual INT32   AddNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual INT32   DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler = TRUE);
		virtual INT32   ModNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask);
		virtual INetHandlerPtr  GetNetHandler(UINT32  unNetHandlerIndex);

	private: //5 reactorһ�㶼�ǵ��߳�.���Բ��ؿ����̰߳�ȫ.������̵߳Ļ�һ������ȫ.
		UINT32          m_nNetHandlerCount;
		UINT32          m_unMaxConnectionCount;
		MapNetHandlersT m_mapNetHandlers;
		MapNetEventsT   m_mapNetEvents;

	private:
		void  * m_pFdSetReads;
		void  * m_pFdSetWrites;
		void  * m_pFdSetExcepts;

	}; 

}

#endif
