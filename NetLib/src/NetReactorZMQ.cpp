#include "NetReactorZMQ.h"
#include "NetHandlerClient.h"
#include "TimerHelp.h"

#ifdef WIN32
#include <windows.h>
#endif

namespace Net
{   
	NetReactorZMQ::NetReactorZMQ( UINT32 unMaxConnectionCount )
		: m_nNetHandlerCount(0)
		, m_unMaxConnectionCount(unMaxConnectionCount)  
	{   
	}

	NetReactorZMQ::~NetReactorZMQ( void )
	{    
	}

	INT32 NetReactorZMQ::Init( void )
	{

		return ERR_SUCCESS;
	}

	INT32 NetReactorZMQ::Cleanup( void )
	{  
		m_mapNetHandlers.clear(); 

		return ERR_SUCCESS;
	}

	INT32 NetReactorZMQ::Update( void )
	{ 
		MapNetHandlersT::iterator iterHandlers = m_mapNetHandlers.begin();
		for (; iterHandlers != m_mapNetHandlers.end();)
		{ 
			BOOL  bClosed = FALSE;
			INetHandlerPtr  pNetHandler  = iterHandlers->second;
			if (pNetHandler)
			{  
				pNetHandler->OnMsgRecving();  //5 ZMQ直接接收消息.

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

		return ERR_SUCCESS;
	}

	INT32 NetReactorZMQ::AddNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask /*= NET_FUNC_DEFAULT*/ )
	{
		Assert_ReF1(m_unMaxConnectionCount > m_nNetHandlerCount && pNetHandler->GetSession());
		  
		m_mapNetHandlers.insert(std::make_pair(pNetHandler->GetSession()->GetSessionID() , pNetHandler)); 

		++m_nNetHandlerCount;
		return ERR_SUCCESS;
	}

	INT32 NetReactorZMQ::DelNetHandler( INetHandlerPtr  pNetHandler , BOOL bEraseHandler/* = TRUE */)
	{
		if (pNetHandler.get())
		{  
			pNetHandler->OnClose();  

			--m_nNetHandlerCount;
		}

		return ERR_SUCCESS;
	}

	INT32 NetReactorZMQ::ModNetHandler( INetHandlerPtr  pNetHandler  , ENetHandlerFuncMask objMask )
	{ 

		return ERR_SUCCESS;
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