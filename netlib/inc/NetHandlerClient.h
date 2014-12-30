#ifndef __net_net_handler_client_h__
#define __net_net_handler_client_h__ 
#include "NetHandlerTransit.h"
#include "MsgProcess.h"
#include "ClientSession.h"

namespace Net 
{  
	class DLL_EXPORT NetHandlerClient :public NetHandlerTransit
	{
	public:
		NetHandlerClient(INetReactor * pNetReactor , ISession * pSession , MsgProcess * pMsgProcess = NULL);
		virtual ~NetHandlerClient();

	public:
		virtual INT32  Init( const char* ip,int port );
		virtual INT32  Cleanup( void );
		virtual INT32  OnClose( void );
		virtual INT32  OnReconnect( void );

	public:
		virtual INT32 HandleMsg(ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);

	public: 
		BOOL  Reconnect(void)
		{ 
			if (m_pSession && ((Net::ClientSession * )m_pSession)->IsReconnect() && 
				m_pSession->GetNetState() == NET_STATE_LOSTED && m_pSession->IsClosed())
			{
				OnReconnect();
			}
			return TRUE;
		}
	
	protected:
		INT32  Connect( const char* ip,int port );

    private: 
		MsgProcess * m_pMsgProcess;
	}; 

	DECLARE_BOOST_POINTERS(NetHandlerClient);
}

#endif


