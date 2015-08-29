#ifndef __msg_remote_rpc_server_h__
#define __msg_remote_rpc_server_h__ 
#include "NetLib/inc/NetHandlerZMQServer.h"
#include "MsgLib/inc/MsgCommon.h"
#include "NetLib/inc/NetHandlerServer.h" 
#include "Timer/inc/TimerHelp.h"
#include "MsgLib/inc/Ping.h"

namespace Msg
{
	
	class RpcManager;
	 
	class DLL_EXPORT RemoteRpcServer : public Net::NetHandlerServer
	{
	public:
		RemoteRpcServer(RpcManager * pRpcManager , Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~RemoteRpcServer();

	public: 
		virtual CErrno  OnClose( void );    
		virtual CErrno  UpdatePing( void ); 
		virtual CErrno  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);  

	public:
		CErrno   Update( void );     
		void    SetLastRecvPingTime( INT64 ullLstRecfPing = 0);

	protected:
		INT64        m_ullLastRecvPing; 
		RpcManager * m_pRpcManager; 
	};  

	DECLARE_BOOST_POINTERS(RemoteRpcServer); 
}


#endif