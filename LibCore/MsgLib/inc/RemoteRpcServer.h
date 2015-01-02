#ifndef __msg_remote_rpc_server_h__
#define __msg_remote_rpc_server_h__ 
#include "NetHandlerZMQServer.h"
#include "MsgCommon.h"
#include "NetHandlerServer.h" 
#include "TimerHelp.h"
#include "Ping.h"

namespace Msg
{
	
	class RpcManager;


#ifdef USE_ZMQ
	class DLL_EXPORT RemoteRpcServer : public Net::NetHandlerZMQServer 
#else
	class DLL_EXPORT RemoteRpcServer : public Net::NetHandlerServer
#endif
	{
	public:
		DECLARE_BOOST_TEMPLATE_POINTERS(RemoteRpcServer , RemoteRpcServer); 

	public:
		RemoteRpcServer(RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~RemoteRpcServer();

	public: 
		virtual INT32  OnClose( void );    
		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);  

	public:
		INT32   Update( void );   
		INT32   UpdatePing( void );   
		void    SetLastRecvPingTime( INT64 ullLstRecfPing = 0);

	private:
		INT64                m_ullLastRecvPing; 
		RpcManager * m_pRpcManager; 
	};  

}


#endif