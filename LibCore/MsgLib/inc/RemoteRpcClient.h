#ifndef __msg_remote_rpc_client_h__
#define __msg_remote_rpc_client_h__ 
#include "MsgCommon.h"
#include "NetHandlerClient.h" 

namespace Msg
{ 
	class RpcManager; 
	
#ifdef USE_ZMQ
	class DLL_EXPORT  RemoteRpcClient : public Net::NetHandlerZMQClient
#else
	class DLL_EXPORT  RemoteRpcClient : public Net::NetHandlerClient
#endif
	{ 
	public:
		DECLARE_BOOST_TEMPLATE_POINTERS(RemoteRpcClient , RemoteRpcClient); 

	public:
		RemoteRpcClient( RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~RemoteRpcClient();

	public: 
		virtual INT32  Cleanup( void );
		virtual INT32  Update(void);
		virtual INT32  OnClose( void );   
		virtual INT32  OnReconnect( void );
		virtual INT32  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength); 

	private:
		RpcManager * m_pRpcManager;  
	};   
}


#endif