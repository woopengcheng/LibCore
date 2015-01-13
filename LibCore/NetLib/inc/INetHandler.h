#ifndef __net_i_net_handler_h__
#define __net_i_net_handler_h__ 
#include "NetCommon.h"
#include "ISession.h"

namespace Net 
{  
	class ISession;
	class INetReactor;

	class DLL_EXPORT INetHandler
	{
	public:
		INetHandler( INetReactor * pNetReactor , ISession * pSession )
			: m_pSession(pSession) 
			, m_pNetReactor(pNetReactor)
		{ 
		}
		virtual ~INetHandler( void )
		{ 
		} 

	public:
		virtual INT32  Init( void )         { return ERR_SUCCESS; }
		virtual INT32  Cleanup( void )
		{
			if (m_pSession)
			{
				return m_pSession->Cleanup();
			}
			return ERR_SUCCESS;
		}
		virtual INT32  Update( void )       { return ERR_SUCCESS; }
		virtual INT32  OnClose( void )      { return ERR_SUCCESS; } 
		virtual INT32  OnMsgRecving( void ) { return ERR_SUCCESS; }
		virtual INT32  OnMsgSending( void ) { return ERR_SUCCESS; }  

	public: 
		ISession * GetSession(){ return m_pSession; }
		INetReactor * GetNetReactor(){ return m_pNetReactor; }

	protected: 
		ISession    *  m_pSession;             //5 session must be delete
		INetReactor *  m_pNetReactor;          //5 use it for delete
	}; 

	DECLARE_BOOST_POINTERS(INetHandler);
}

#endif
