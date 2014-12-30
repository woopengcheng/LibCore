﻿#ifndef __msg_rpc_manager_h__
#define __msg_rpc_manager_h__ 
#include "MsgCommon.h"
#include "ThreadTask.h"
#include "MsgDispatcher.h"
#include "NetReactorSelect.h" 
#include "NetHandlerTransit.h"
#include "NetHelper.h" 
#include "ISession.h"
#include "Ping.h"

namespace Msg
{
	
	class RPCMsgCall;

	
	class Rpc;

	
	class RpcInterface;

	struct SRpcInfo 
	{
		char   szAddress[MAX_NAME_LENGTH];
		char   szRemoteName[MAX_NAME_LENGTH];
		UINT16 usPort;
		INT32  nSessionID;

		SRpcInfo()
			: usPort(0)
			, nSessionID(-1)
		{
			memset(szAddress , 0 , sizeof(szAddress));
			memset(szRemoteName , 0 , sizeof(szRemoteName)); 
		} 

		SRpcInfo(const char * pClientName ,const char * pAddress , UINT16 port ,INT32  sessionID) 
		{
			usPort = port;
			nSessionID = sessionID;
			memcpy(szAddress , pAddress , sizeof(szAddress));
			memcpy(szRemoteName , pClientName , sizeof(szRemoteName)); 
		}

		SRpcInfo & operator = (const SRpcInfo & objRpcInfo)
		{
			usPort = objRpcInfo.usPort;
			nSessionID = objRpcInfo.nSessionID;
			memcpy(szAddress , objRpcInfo.szAddress , sizeof(objRpcInfo.szAddress));
			memcpy(szRemoteName , objRpcInfo.szRemoteName , sizeof(objRpcInfo.szRemoteName)); 

			return *this;
		}
	}; 
	
	class DLL_EXPORT  RpcManager : public MsgDispatcher , public ThreadPool::ThreadSustainTask
	{
	public: 
		typedef std_unordered_map<UINT64 , Rpc *> MapRpcsT;  
		typedef std_unordered_map<INT32 , Net::NetHandlerTransitPtr> MapSessionToHandlersT;
		typedef std_unordered_map<std::string , SRpcInfo> MapRpcInfosT;; 

	public:
		RpcManager( RpcInterface * pRpcInterface , Net::INetReactor * pNetReactor )
			: ThreadPool::ThreadSustainTask(DEFAULT_RPC_MSG_THREAD_ID , "RpcManager")
			, m_pNetReactor(pNetReactor)
			, m_pRpcInterface(pRpcInterface)
		{}
		virtual ~RpcManager(void){} 
		 
	public:
		virtual INT32  Init(void);
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void);

	public:
		virtual INT32  AddRemoteRpc(INT32 nSessionID , Net::NetHandlerTransitPtr pRpc);
		virtual INT32  DelRemoteRpc(INT32 nSessionID);
		virtual void   AddNetHandler(INT32 nSessionID , Net::NetHandlerTransitPtr pRpc);
		virtual void   DelNetHandler(INT32 nSessionID);
		virtual void   AddRpcInfo(SRpcInfo & objRpcInfo);
		virtual void   DelRpcInfo(std::string strRpcInfo);
		virtual INT32  UpdateHandlers(void);
		virtual INT32  CleanupRemoteRpc(INT32 nSessionID);
		virtual INT32  CleanupRpcInfo(std::string strRpcInfo);
		virtual void   CloseNet(const char * pName){}
		virtual void   CloseNet(INT32 nSessionID){}

	public: 
		virtual INT32  SendMsg(const char * pRpcServerName , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE); 
		virtual INT32  SendMsg(INT32 nSessionID , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE); 
		virtual INT32  SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pRpcMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE); 
		virtual INT32  SendMsg( Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce = FALSE , BOOL bAddRpc = TRUE);
		virtual INT32  ProxySendMsg(INT32 nSessionID , RPCMsgCall * pMsg){ return -1; } 
		virtual INT32  ProxySendMsg(const char * pRpcServerName , RPCMsgCall * pMsg){ return -1; }
		virtual INT32  HandleMsg(Net::ISession * pSession , RPCMsgCall * pMsg);  
		virtual INT32  HandlePing( Net::ISession * pSession , SPing * pPing ){ return -1; }

		virtual Net::NetHandlerTransitPtr OnCreateNetHandler(const char * pName , const char * pAddress , UINT16 usPort , Net::SOCKET socket = 0){ return Net::NetHandlerTransitPtr(NULL); }
		  
	public: 
		Net::NetHandlerTransitPtr   GetNetHandlerBySessionID(INT32 nSessionID);
		Net::NetHandlerTransitPtr   GetNetHandlerByName(std::string strNetHandlerName);
		MapRpcsT & GetSendRpcs( void ){ return m_mapSendRpcs; }  
		Net::NetHandlerTransitPtr   GetHandlerByName(const char * pRpcServerName); 
		Net::NetHandlerTransitPtr   GetHandlerBySimilarName(const char * pRpcServerName); 
		MapRpcInfosT & GetMapRpcInfos() { return m_mapRpcInfos; }
		Net::INetReactor *  GetNetReactor() { return m_pNetReactor; }
		BOOL  IsHasSessionByName(const char * pRpcServerName);  
		BOOL  ChangeNameBySesson(const INT32 nSessionID , const char * pName);  
		void  InsertSendRpc(RPCMsgCall * pMsg);
		void  InsertSendRpc(UINT64 ullRpcMsgID, Rpc * objRpc);
		RpcInterface * GetRpcInterface(){ return m_pRpcInterface; }
		BOOL   IsRpcInfoVaild(std::string strRpcInfo);
		SRpcInfo * GetRpcInfo(std::string strRpcInfo);
		Net::NetHandlerTransitPtr CreateNetHandler( const char * pName , const char * pAddress , const char * pPort , Net::SOCKET socket = 0);
		Net::NetHandlerTransitPtr CreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::SOCKET socket = 0);
		Net::NetHandlerTransitPtr CreateNetHandler( SRpcInfo & objRpcInfo , Net::SOCKET socket = 0 );
		 
	protected: 
		MapRpcsT					  m_mapSendRpcs;   
		MapRpcInfosT				  m_mapRpcInfos;   //5 存下服务器的session.用来发送信息.
		Net::INetReactor			* m_pNetReactor;         //5 没有访问机会.不会加锁
		RpcInterface				* m_pRpcInterface;
		MapSessionToHandlersT		  m_mapRemoteRpcs;
		ThreadPool::ThreadSpinRWMutex m_objLock;   //5 用来锁住
	};  

}


#endif