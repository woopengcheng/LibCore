#ifndef __msg_remote_rpc_client_h__
#define __msg_remote_rpc_client_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "NetLib/inc/NetHandlerClient.h" 

namespace Msg
{ 
	class RpcManager; 
	 
	class DLL_EXPORT  RemoteRpcClient : public Net::NetHandlerClient 
	{ 
	public:
		RemoteRpcClient( RpcManager * pRpcManager ,  Net::INetReactor * pNetReactor , Net::ISession * pSession);
		virtual ~RemoteRpcClient();

	public: 
		virtual CErrno  Cleanup( void );
		virtual CErrno  Update(void);
		virtual CErrno  OnClose( void );   
		virtual CErrno  OnReconnect( void );
		virtual CErrno  HandleMsg(Net::ISession * pSession , UINT32 unMsgID, const char* pBuffer, UINT32 unLength); 

	private:
		RpcManager * m_pRpcManager;  
	};    
	 
	DECLARE_BOOST_POINTERS(RemoteRpcClient); 

}


#endif