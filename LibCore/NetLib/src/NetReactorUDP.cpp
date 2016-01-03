#include "NetLib/inc/NetReactorUDP.h"
#include "NetLib/inc/NetHandlerClient.h"
#include "Timer/inc/TimerHelp.h"

#ifdef WIN32
#include <windows.h>
#endif

namespace Net
{ 
	NetReactorUDP::NetReactorUDP( UINT32 unMaxConnectionCount )
		: m_unMaxConnectionCount(unMaxConnectionCount)
		, m_pFdSetReads(NULL)
		, m_pFdSetExcepts(NULL)
		, INetReactor(REACTOR_TYPE_UDP)
	{  

		size_t  size = unMaxConnectionCount * sizeof(INT32) + sizeof(fd_set);
		m_pFdSetReads = malloc(size);
		m_pFdSetExcepts = malloc(size);

		memset(m_pFdSetReads , 0 , size);
		memset(m_pFdSetExcepts , 0 , size);
	}

	NetReactorUDP::~NetReactorUDP( void )
	{  
		free(m_pFdSetReads);
		free(m_pFdSetExcepts); 
	}

	CErrno NetReactorUDP::Init( void )
	{

		return CErrno::Success();
	}

	CErrno NetReactorUDP::Cleanup( void )
	{  
		m_mapNetHandlers.clear();

		return CErrno::Success();
	}

	CErrno NetReactorUDP::Update( void )
	{
		fd_set* pFdSetWrites = NULL;
		fd_set* pFdSetReads =  (fd_set*)m_pFdSetReads;
		fd_set* pFdSetExcepts = (fd_set*)m_pFdSetExcepts;

		FD_ZERO(pFdSetExcepts);
		FD_ZERO(pFdSetReads);

		{ 
			MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.begin();
			for (;iterHandlers != m_mapNetHandlers.end() ;++ iterHandlers)
			{
				NetSocket socket = -1;
				INetHandlerPtr pINetHandler = iterHandlers->second;
				if (pINetHandler)
				{
					socket = iterHandlers->second->GetSession()->GetSocket();
					FD_SET(socket, pFdSetReads);
					FD_SET(socket, pFdSetExcepts);
				}
			}
		}

		struct timeval objTimeout = {0};
		objTimeout.tv_usec = 100;
		objTimeout.tv_sec = 0;

		int nResult = select(0 , pFdSetReads , pFdSetWrites , pFdSetExcepts , &objTimeout);
		if (nResult > 0)
		{
			MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.begin();
			for (; iterHandlers != m_mapNetHandlers.end();)
			{
				BOOL  bClosed = FALSE;
				INetHandlerPtr  pNetHandler  = iterHandlers->second;
				if (pNetHandler)
				{
					NetSocket socket = pNetHandler->GetSession()->GetSocket(); 

					if (FD_ISSET(socket , pFdSetReads))
					{
						UDPContext * pContext = new UDPContext;

						sockaddr_in addr = pContext->GetPeerAddr();
						int nRecLen = sizeof(addr);
						char recv_buf[1024];
						int nRecEcho = recvfrom(socket, recv_buf, sizeof(recv_buf), 0, (sockaddr*)&addr, &nRecLen);
						if (nRecEcho == INVALID_SOCKET)
						{
							bClosed = true;
							break;
						}

						pContext->SetPeerAddr(addr);

						bClosed = !pNetHandler->OnMsgRecving().IsSuccess() || bClosed;
					}

					if (FD_ISSET(socket , pFdSetExcepts))
					{
						bClosed = TRUE;
					}

					ISession * pSession = pNetHandler->GetSession();
					if (pSession && pSession->GetObjTimeout().IsExpired() || pSession->IsClosed())
					{
						bClosed = TRUE;
					}

					if (bClosed)
					{
						gDebugStream("delete " << pNetHandler->GetSession()->GetRemoteName() << ":addr=" << pNetHandler->GetSession()->GetAddress() << ":port=" <<pNetHandler->GetSession()->GetPort());
						DelNetHandler(pNetHandler , FALSE); 
						m_mapNetHandlers.erase(iterHandlers++); 
					}  
					else
					{
						++ iterHandlers;
					}

					if (pNetHandler->GetSession()->GetContext())
					{
						delete pNetHandler->GetSession()->GetContext();
						pNetHandler->GetSession()->SetContext(NULL);
					}
				}
			}
		} 
		Timer::TimerHelper::sleep(1);

		return CErrno::Success();
	}

	CErrno NetReactorUDP::AddNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/ )
	{
		Assert_ReF(pNetHandler->GetSession());
	
		m_mapNetHandlers.insert(std::make_pair(pNetHandler->GetSession()->GetSessionID() , pNetHandler));

		return CErrno::Success();
	}

	CErrno NetReactorUDP::DelNetHandler( INetHandlerPtr  pNetHandler , BOOL bEraseHandler/* = TRUE */)
	{
		if (pNetHandler.get())
		{
			pNetHandler->OnClose();  
		}

		return CErrno::Success();
	}

	CErrno NetReactorUDP::ModNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask )
	{

		return CErrno::Success();
	}


}