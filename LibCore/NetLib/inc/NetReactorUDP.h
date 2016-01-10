#ifndef __net_i_net_reactor_udp_h__
#define __net_i_net_reactor_udp_h__ 
#include "NetLib/inc/INetHandler.h"
#include "NetLib/inc/INetReactor.h"

namespace Net 
{
	class UDPContext
	{
	public:
		UDPContext() {}
		virtual ~UDPContext() {}

		sockaddr_in GetPeerAddr() 
		{
			return m_objAddr;
		}

		void SetPeerAddr(sockaddr_in cli)
		{
			m_objAddr = cli;
		}

	private:
		sockaddr_in m_objAddr;
	};

	class DLL_EXPORT NetReactorUDP :public INetReactor
	{
	public:
		typedef std_unordered_map<UINT32 , INetHandlerPtr> MapNetHandlersT;

	public:
		NetReactorUDP(  UINT32 unMaxConnectionCount = DEFAULT_MAX_CONNECTION_COUNT  ); 
		virtual ~NetReactorUDP( void );

	public:
		virtual CErrno   Init( void );
		virtual CErrno   Cleanup( void );
		virtual CErrno   Update( void );

	public:
		virtual CErrno   AddNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask = NET_FUNC_DEFAULT);
		virtual CErrno   DelNetHandler(INetHandlerPtr  pNetHandler , BOOL bEraseHandler = TRUE);
		virtual CErrno   ModNetHandler(INetHandlerPtr  pNetHandler , ENetHandlerFuncMask objMask);

	private: //5 reactorһ�㶼�ǵ��߳�.���Բ��ؿ����̰߳�ȫ.������̵߳Ļ�һ������ȫ.
		UINT32          m_nNetHandlerCount;
		UINT32          m_unMaxConnectionCount;
		MapNetHandlersT m_mapNetHandlers;

	private:
		void  * m_pFdSetReads;
		void  * m_pFdSetExcepts;

	}; 

//	typedef Net::NetReactorSelect NetReactorDefault;
}

#endif