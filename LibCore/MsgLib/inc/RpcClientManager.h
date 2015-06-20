#ifndef __msg_rpc_client_manager_h__
#define __msg_rpc_client_manager_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "ThreadPoolLib/inc/ThreadTask.h" 
#include "NetLib/inc/NetReactorSelect.h"
#include "MsgLib/inc/InnerMsg.h"
#include "MsgLib/inc/RemoteRpcServer.h"
#include "MsgLib/inc/RemoteRpcClient.h"
#include "MsgLib/inc/NetHandlerRpcListener.h"
#include "MsgLib/inc/RpcBase.h"
#include "NetLib/inc/ISession.h"
#include "MsgLib/inc/RpcManager.h"
#include "TimerLib/inc/TimeCount.h"

#ifdef WIN32
#pragma warning( disable :4996)
#endif

namespace Msg
{ 
	class Rpc;  
	class RemoteRpcClient;  
	
	class DLL_EXPORT RpcClientManager : public RpcManager
	{
	public:
		RpcClientManager(RpcInterface * pRpcInterface ,Net::INetReactor * pNetReactor) 
			: RpcManager(pRpcInterface , pNetReactor)
			, m_ullLastSendPing(0)
		{}
		virtual ~RpcClientManager(void){}  

	public:
		virtual INT32  Init( void );
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void); 
		virtual void   CloseNet(const char * pName);

	public:
		virtual INT32  SendMsg(INT32 nSessionID , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE); 
		virtual INT32  SendMsg(const char * pRpcServerName , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE){ return RpcManager::SendMsg(pRpcServerName , pMsg , bForce , bAddRpc); } 
		virtual INT32  SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pRpcMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE){ return RpcManager::SendMsg(pRemoteRpc , pRpcMsg , bForce , bAddRpc); }  
		virtual INT32  SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce = FALSE , BOOL bAddRpc = TRUE){ return RpcManager::SendMsg(pRemoteRpc , unMsgID , pBuffer , unLength , bForce , bAddRpc); }  

	public: 
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0 , void * context = NULL);
 		  
	public: 
		INT32  UpdatePing(void);   
		INT32  Ping( void );  

	private:  
		INT64        m_ullLastSendPing;  
	};    
	  
}


#endif