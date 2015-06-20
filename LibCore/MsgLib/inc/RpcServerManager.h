#ifndef __msg_rpc_server_manager_h__
#define __msg_rpc_server_manager_h__ 
#include "MsgLib/inc/MsgCommon.h" 
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcInterface.h"

namespace Msg
{ 
	class DLL_EXPORT  RpcServerManager : public RpcManager
	{ 
	public:
		RpcServerManager(RpcInterface * pRpcInterface , Net::INetReactor * pNetReactor) 
			: RpcManager(pRpcInterface , pNetReactor)
		{}
		virtual ~RpcServerManager(void){}  

	public:
		virtual INT32  Init(UINT32 unMsgThreadPriorityCount = 1 , UINT32 unMsgHandlerthreadPriorityCount = 1, UINT32 unMsgThreadPriority = DEFAULT_MSG_THREAD_ID ,UINT32 unMsgHandlerthreadPriority = DEFAULT_MSG_HANDLE_THREAD_ID);
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void);
		virtual void   CloseNet(const char * pName);
		virtual void   CloseNet(INT32 nSessionID);

	public:
		virtual INT32  SendMsg(const char * pRpcServerName , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE){ return m_pRpcInterface->SendMsg(pRpcServerName , pMsg , bForce , bAddRpc); } 
		virtual INT32  SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pRpcMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE ){ return m_pRpcInterface->SendMsg(pRemoteRpc , pRpcMsg , bForce , bAddRpc); }  
		virtual INT32  SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce = FALSE , BOOL bAddRpc = TRUE){ return m_pRpcInterface->SendMsg(pRemoteRpc , unMsgID , pBuffer , unLength , bForce , bAddRpc); }  
		virtual INT32  SendMsg(INT32 nSessionID , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE){ return m_pRpcInterface->SendMsg(nSessionID , pMsg , bForce , bAddRpc); }
		  
	public:  
		virtual INT32  HandleMsg(Net::ISession * pSession , RPCMsgCall * pMsg);    
		virtual INT32  HandlePing( Net::ISession * pSession , SPing * pPing );

	public:  
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0 , void * context = NULL);

	public: 
		INT32  UpdateCalls(void); 
		INT32  HandleServerMsg(Net::ISession * pSession , RPCMsgCall * pMsg);
		INT32  HandleClientMsg(Net::ISession * pSession , RPCMsgCall * pMsg);
	};  
	 
}


#endif