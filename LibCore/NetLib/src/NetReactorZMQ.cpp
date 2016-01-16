#include "NetLib/inc/NetReactorZMQ.h"
#include "NetLib/inc/NetHandlerClient.h"
#include "Timer/inc/TimerHelp.h"

#ifdef WIN32
#include <windows.h>
#endif

namespace Net
{   
	NetReactorZMQ::NetReactorZMQ(UINT32 unMaxConnectionCount, BOOL bIsMutilThread/* = FALSE*/)
		: INetReactor(REACTOR_TYPE_ZMQ, bIsMutilThread)
		, m_nNetHandlerCount(0)
		, m_unMaxConnectionCount(unMaxConnectionCount)
	{   
	}

	NetReactorZMQ::~NetReactorZMQ( void )
	{    
	}

	CErrno NetReactorZMQ::Init( void )
	{

		return CErrno::Success();
	}

	CErrno NetReactorZMQ::Cleanup( void )
	{  
		m_mapNetHandlers.clear(); 

		return CErrno::Success();
	}

	CErrno NetReactorZMQ::Update( void )
	{ 
		MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.begin();
		for (; iterHandlers != m_mapNetHandlers.end();)
		{ 
			BOOL  bClosed = FALSE;
			INetHandlerPtr  pNetHandler  = iterHandlers->second;
			if (pNetHandler)
			{  
				pNetHandler->OnMsgRecving();  //5 ZMQֱ�ӽ�����Ϣ.

				ISession * pSession = pNetHandler->GetSession();
				if (pSession && pSession->GetObjTimeout().IsExpired() || pSession->IsClosed())
				{
					bClosed = TRUE;
				}

				if (bClosed)
				{ 
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

		return CErrno::Success();
	}

	CErrno NetReactorZMQ::AddNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/ )
	{
		Assert_ReF(m_unMaxConnectionCount > m_nNetHandlerCount && pNetHandler->GetSession());
		  
		m_mapNetHandlers.insert(std::make_pair(pNetHandler->GetSession()->GetSessionID() , pNetHandler)); 

		++m_nNetHandlerCount;

		return INetReactor::AddNetHandler(pNetHandler, objMask);
	}

	CErrno NetReactorZMQ::DelNetHandler( INetHandlerPtr  pNetHandler , BOOL bEraseHandler/* = TRUE */)
	{
		if (pNetHandler.get())
		{  
			pNetHandler->OnClose();  

			--m_nNetHandlerCount;
		}

		return INetReactor::DelNetHandler(pNetHandler, bEraseHandler);
	}

	CErrno NetReactorZMQ::ModNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask )
	{ 

		return INetReactor::ModNetHandler(pNetHandler, objMask);
	}

	Net::INetHandlerPtr NetReactorZMQ::GetNetHandler( UINT32 unNetHandlerIndex )
	{  
		MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.find(unNetHandlerIndex);
		if( iterHandlers != m_mapNetHandlers.end() )
		{
			return iterHandlers->second;
		}
		return Net::INetHandlerPtr(NULL);
	}


}