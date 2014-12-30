#ifndef __msg_rpc_interface_h__
#define __msg_rpc_interface_h__  
#include "MsgCommon.h"
#include "NetHandlerTransit.h"

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
		RpcInterface(void) 
			: m_usServerPort(0)
			, m_pNetReactor(NULL)
			, m_pRpcServerManager(NULL)
			, m_pRpcClientManager(NULL)
			, m_pRpcListener(NULL) 
		{
			memset(m_szServerName , 0 , sizeof(m_szServerName));
			memset(m_szRpcType , 0 , sizeof(m_szRpcType));
		}
		virtual ~RpcInterface(void){} 

	public:
		virtual INT32  Init(std::string strFilePath);
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void); 
		virtual void   OnRegisterRpcs(void){}

	public:
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
		char *  GetServerType(){ return m_szRpcType; }
		void    SetRpcListener(IRpcListener * pRpcListener ){ m_pRpcListener = pRpcListener; }
		IRpcListener * GetRpcListener( ){ return m_pRpcListener; } 

	private:
		void   StartupRPCServer(XML::XML * pXML);
		void   StartupRPCClient(XML::XML * pXML);

	protected: 
		UINT16               m_usServerPort;
		char                 m_szServerName[MAX_NAME_LENGTH];
		char                 m_szRpcType[MAX_NAME_LENGTH]; 
		IRpcListener      *  m_pRpcListener;
		Net::INetReactor  *  m_pNetReactor;         //5 û�з��ʻ���.�������
		RpcServerManager  *  m_pRpcServerManager;
		RpcClientManager  *  m_pRpcClientManager;
	};  

}


#endif