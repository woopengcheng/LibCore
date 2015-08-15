#ifndef __net_i_session_h__
#define __net_i_session_h__ 
#include "NetLib/inc/NetCommon.h"
#include "Timer/inc/TimeCount.h"

namespace Net 
{  
	enum ENetState
	{ 
		NET_STATE_LOSTED = 0 ,   //5 Á¬½Ó¶ªÊ§
		NET_STATE_CONNECTING ,     
		NET_STATE_CONNECTED ,     
	};

	class DLL_EXPORT ISession
	{
	public:
		ISession( const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID = -1 , INT32 nNetState = 0 , NetSocket socket = -1 , INT64 llTimeout = 0);
		virtual ~ISession( void )
		{
			Cleanup();
		}

	public:
		virtual    INT32   Init( const char * pAddress ,INT16 usSocktPort , const char * pRemoteName , INT32 nSessionID , NetSocket socket , INT64 llTimeout = 0);
		virtual    INT32   Cleanup( void ); 
		virtual    INT32   OnRecvMsg( void );
		virtual    INT32   OnSendMsg( void );
		virtual    INT32   OnClose( void ); 
		 
	public:
		INT32 GetSessionID() const { return m_nSessionID; }
		void SetSessionID(INT32 val) { m_nSessionID = val; }
		void  AutoSetSessionID( void );
		UINT16 GetPort() const { return m_usSocktPort; }
		void SetSocktPort(UINT16 val) { m_usSocktPort = val; }
		const char * GetAddress() { return m_szAddress; }
		void SetAddress(const char * val) { memcpy(m_szAddress , val ,strlen(val) + 1); }
		Timer::TimeCount GetObjTimeout() const { return m_objTimeout; } 
		BOOL IsClosed(void) const { return m_bClosed; }
		void SetClosed(BOOL val) { m_bClosed = val; }
		const char * GetRemoteName() { return m_szRemoteName; }
		void SetRemoteName(const char * pRemoteName) { memcpy(m_szRemoteName , pRemoteName , strlen(pRemoteName) + 1); }
		INT32 GetNetState() const { return m_nNetState; }
		void SetNetState(INT32 val) { m_nNetState = val; }
		NetSocket GetSocket() const { return m_socket; }
		void SetSocket(NetSocket val) { m_socket = val; }  
		BOOL IsCanWrite() const { return m_bCanWrite; }
		void SetCanWrite(BOOL val) { m_bCanWrite = val; }
		ISession * GetOtherSession() const { return m_pOtherSession; }
		void SetOtherSession(ISession * val) { m_pOtherSession = val; }
		BOOL IsTimeout(void)
		{ 
			if (m_objTimeout.IsStarted())
			{ 
				return m_objTimeout.IsExpired();
			} 
			else
			{
				return FALSE; 
			}
		} 

	protected:
		NetSocket            m_socket;  
		INT32             m_nNetState;
		BOOL              m_bClosed;
		INT32			  m_nSessionID;
		UINT16            m_usSocktPort;
		char		      m_szAddress[MAX_NAME_LENGTH];
		char              m_szRemoteName[MAX_NAME_LENGTH]; 
		ISession      *   m_pOtherSession;

	private:
		BOOL              m_bCanWrite;
		Timer::TimeCount  m_objTimeout; 
	}; 

}

#endif
