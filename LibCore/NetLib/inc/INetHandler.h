#ifndef __net_i_net_handler_h__
#define __net_i_net_handler_h__ 
#include "NetLib/inc/NetCommon.h"
#include "NetLib/inc/ISession.h"

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
		virtual CErrno  Init( void )         { return CErrno::Success(); }
		virtual CErrno  Cleanup( void )
		{
			if (m_pSession)
			{
				return m_pSession->Cleanup();
			}
			return CErrno::Success();
		}
		virtual CErrno  Update( void )       { return CErrno::Success(); }
		virtual CErrno  OnClose( void )      { return CErrno::Success(); } 
		virtual CErrno  OnMsgRecving( void ) { return CErrno::Success(); }
		virtual CErrno  OnMsgSending( void ) { return CErrno::Success(); }  

	public: 
		ISession	* GetSession(){ return m_pSession; }
		INetReactor * GetNetReactor(){ return m_pNetReactor; }

	protected: 
		ISession    *  m_pSession;             //5 session must be delete
		INetReactor *  m_pNetReactor;          //5 use it for delete
	}; 

	DECLARE_BOOST_POINTERS(INetHandler);
}

#endif
