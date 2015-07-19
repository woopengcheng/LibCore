#ifndef __msg_rpc_interface_h__
#define __msg_rpc_interface_h__  
#include "MsgLib/inc/MsgCommon.h"
#include "NetLib/inc/NetHandlerTransit.h"
#include "json/json.h"

#ifdef WIN32
#pragma warning( disable :4996)
#endif

namespace XML
{
	class XML;
}

namespace Msg
{ 
	class RPCMsgCall; 
	class IRpcListener;
	class RpcServerManager;  
	class RpcClientManager;  
	 
	class DLL_EXPORT  RpcInterface
	{ 
	public:
		RpcInterface(void) ;
		virtual ~RpcInterface(void);

	public:
		virtual INT32  Init(std::string strFilePath);
		virtual INT32  Init(Json::Value & conf);
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void); 
		virtual void   OnRegisterRpcs(void){}
		virtual void   StartupRPCServer(const std::string & strNetNodeName , const std::string & strType , const std::string & strAddress , const std::string & strPort);
		virtual void   StartupRPCClient(XML::XML * pXML);
		virtual void   StartupRPCClient(const Json::Value & clients);

	public:
		virtual INT32  SendMsg(const std::string & strNetNodeName , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE);
		virtual INT32  SendMsg(const char * pRpcServerName , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE);
		virtual INT32  SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , RPCMsgCall * pRpcMsg  , BOOL bForce = FALSE , BOOL bAddRpc = TRUE);
		virtual INT32  SendMsg(INT32 nSessionID , RPCMsgCall * pMsg , BOOL bForce = FALSE , BOOL bAddRpc = TRUE); 
		virtual INT32  SendMsg(Net::NetHandlerTransitPtr pRemoteRpc , UINT32 unMsgID, const char* pBuffer, UINT32 unLength , BOOL bForce = FALSE , BOOL bAddRpc = TRUE);

	public:  
		void   RegisterRpc(void);
		INT32  CloseNet(const char * pName);  
		Net::INetReactor *  GetNetReactor(){ return m_pNetReactor; }
		RpcServerManager  *  GetRpcServerManager(){ return m_pRpcServerManager; }
		RpcClientManager  *  GetRpcClientManager(){ return m_pRpcClientManager; }
		UINT16  GetServerPort(){ return m_usServerPort; }
		char *  GetServerName(){ return m_szServerName; }
		char *  GetNetNodeName(){ return m_szNetNodeName; }
		char *  GetServerType(){ return m_szRpcType; }
		void    SetRpcListener(IRpcListener * pRpcListener ){ m_pRpcListener = pRpcListener; }
		IRpcListener * GetRpcListener( ){ return m_pRpcListener; } 

	private:
		void   TakeOverSync(RPCMsgCall * pMsg);

	protected: 
		UINT16               m_usServerPort;
		char                 m_szServerName[MAX_NAME_LENGTH];
		char                 m_szNetNodeName[MAX_NAME_LENGTH];
		char                 m_szRpcType[MAX_NAME_LENGTH]; 
		IRpcListener      *  m_pRpcListener;
		Net::INetReactor  *  m_pNetReactor;         //5 没有访问机会.不会加锁
		RpcServerManager  *  m_pRpcServerManager;
		RpcClientManager  *  m_pRpcClientManager;
	};  

}


#endif