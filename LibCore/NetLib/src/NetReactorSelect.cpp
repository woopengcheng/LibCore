#include "NetReactorSelect.h"
#include "NetHandlerClient.h"
#include "TimerHelp.h"

#ifdef WIN32
#include <windows.h>
#endif

namespace Net
{ 
	INT32 InitNet()
	{
#ifdef WIN32
		WSADATA wsd;
		return WSAStartup(MAKEWORD(2,2),&wsd);  //5 0代表成功
#else
		return ERR_SUCCESS;
#endif
	}

	INT32 CleanNet()
	{
#ifdef _WIN32
		return WSACleanup();
#else
		return ERR_SUCCESS;
#endif

	}
	 
	NetReactorSelect::NetReactorSelect( UINT32 unMaxConnectionCount )
		: m_nNetHandlerCount(0)
		, m_unMaxConnectionCount(unMaxConnectionCount) 
		, m_pFdSetReads(NULL)
		, m_pFdSetWrites(NULL)
		, m_pFdSetExcepts(NULL)
	{  

		size_t  size = /*unMaxConnectionCount * sizeof(void*) +*/ sizeof(fd_set);
		m_pFdSetReads = malloc(size);
		m_pFdSetWrites = malloc(size);
		m_pFdSetExcepts = malloc(size);

		memset(m_pFdSetReads , 0 , size);
		memset(m_pFdSetWrites , 0 , size);
		memset(m_pFdSetExcepts , 0 , size);
	}

	NetReactorSelect::~NetReactorSelect( void )
	{  
		free(m_pFdSetReads);
		free(m_pFdSetWrites);
		free(m_pFdSetExcepts); 
	}

	INT32 NetReactorSelect::Init( void )
	{

		return ERR_SUCCESS;
	}

	INT32 NetReactorSelect::Cleanup( void )
	{  
		m_mapNetHandlers.clear();
		m_mapNetEvents.clear();

		return ERR_SUCCESS;
	}

	INT32 NetReactorSelect::Update( void )
	{
		if (m_nNetHandlerCount == 0)
		{
			return ERR_NET_FAILURE;
		}

		fd_set* pFdSetWrites = (fd_set*)m_pFdSetWrites;
		fd_set* pFdSetReads =  (fd_set*)m_pFdSetReads;
		fd_set* pFdSetExcepts = (fd_set*)m_pFdSetExcepts;

		FD_ZERO(pFdSetExcepts);
		FD_ZERO(pFdSetReads);
		FD_ZERO(pFdSetWrites); 

		{ 
			MapNetEventsT::iterator iterEvents = m_mapNetEvents.begin();
			MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.begin();
			for (;iterEvents != m_mapNetEvents.end() && iterHandlers != m_mapNetHandlers.end() ;++iterEvents , ++ iterHandlers)
			{
				SOCKET socket = -1;
				INetHandlerPtr pINetHandler = iterHandlers->second;
				if (pINetHandler)
				{
					socket = iterHandlers->second->GetSession()->GetSocket();
					if (iterEvents->second & (NET_FUNC_READ | NET_FUNC_ACCEPT)) 
						FD_SET(socket , pFdSetReads); 
					if (iterEvents->second & NET_FUNC_WRITE) 
						FD_SET(socket , pFdSetWrites); 
					if (iterEvents->second & NET_FUNC_EXCEPT) 
						FD_SET(socket , pFdSetExcepts);   
				}
			}
		}

		struct timeval objTimeout = {0};
		objTimeout.tv_usec = 100;
		objTimeout.tv_sec = 0;

		int nResult = select(m_nNetHandlerCount , pFdSetReads , pFdSetWrites , pFdSetExcepts , &objTimeout);
		if (nResult > 0)
		{
			MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.begin();
			for (; iterHandlers != m_mapNetHandlers.end();)
			{
				BOOL  bClosed = FALSE;
				INetHandlerPtr  pNetHandler  = iterHandlers->second;
				if (pNetHandler)
				{
					SOCKET socket = pNetHandler->GetSession()->GetSocket(); 

					if (FD_ISSET(socket , pFdSetReads))
					{
						bClosed = pNetHandler->OnMsgRecving() < 0 || bClosed;
					}

					if (FD_ISSET(socket , pFdSetWrites))
					{
						bClosed = pNetHandler->OnMsgSending() < 0 || bClosed;
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
						//++ iterHandlers;
						gDebugStream("delete " << pNetHandler->GetSession()->GetRemoteName());
						DelNetHandler(pNetHandler , FALSE); 
						m_mapNetHandlers.erase(iterHandlers++); 
					}  
					else
					{
						++ iterHandlers;
					}
				}
			}
		} 
		Timer::TimerHelper::sleep(1);

		return ERR_SUCCESS;
	}

	INT32 NetReactorSelect::AddNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/ )
	{
		Assert_ReF1(m_unMaxConnectionCount > m_nNetHandlerCount && pNetHandler->GetSession());
	
		INT32  nFDMask = 0; 
		if(objMask & NET_FUNC_READ) 
			nFDMask |= FD_READ;
		if(objMask & NET_FUNC_WRITE)  
			nFDMask |= FD_WRITE;
		if(objMask & NET_FUNC_ACCEPT)  
			nFDMask |= FD_ACCEPT;
		if(objMask & NET_FUNC_EXCEPT)  
			nFDMask |= FD_CLOSE; 
		 
		m_mapNetHandlers.insert(std::make_pair(pNetHandler->GetSession()->GetSessionID() , pNetHandler));
		m_mapNetEvents.insert(std::make_pair(pNetHandler->GetSession()->GetSessionID() , nFDMask));

		++m_nNetHandlerCount;

		return ERR_SUCCESS;
	}

	INT32 NetReactorSelect::DelNetHandler( INetHandlerPtr  pNetHandler , BOOL bEraseHandler/* = TRUE */)
	{
		if (pNetHandler.get())
		{
			MapNetEventsT::iterator iterEvents = m_mapNetEvents.find(pNetHandler->GetSession()->GetSessionID());
			if (iterEvents != m_mapNetEvents.end())
			{
				m_mapNetEvents.erase(iterEvents);
			}
			else
				MsgAssert_ReF1(0 , "cant find Net Handler\n" );
			 
			pNetHandler->OnClose();  

 			--m_nNetHandlerCount;
		}

		return ERR_SUCCESS;
	}

	INT32 NetReactorSelect::ModNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask )
	{
		Assert_ReF1(pNetHandler->GetSession());

		MapNetEventsT::iterator iterEvents = m_mapNetEvents.find(pNetHandler->GetSession()->GetSessionID());
		if (iterEvents != m_mapNetEvents.end())
		{
			iterEvents->second = objMask;
		}
		else
			return  ERR_NET_FAILURE;

		return ERR_SUCCESS;
	}

	Net::INetHandlerPtr NetReactorSelect::GetNetHandler( UINT32 unNetHandlerIndex )
	{ 

		MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.find(unNetHandlerIndex);
		if( iterHandlers != m_mapNetHandlers.end() )
		{
			return iterHandlers->second;
		}
		return Net::INetHandlerPtr(NULL);
	}


}