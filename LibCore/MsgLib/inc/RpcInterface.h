#ifndef __msg_rpc_interface_h__
#define __msg_rpc_interface_h__  
#include "MsgLib/inc/MsgCommon.h"
#include "json/json.h"

#ifdef WIN32
#pragma warning( disable :4996)
#endif

namespace Net
{
	class NetThread;
}

namespace Msg
{
	class IRpcListener;
	class RPCMsgCall;
	class RpcManager;

	class DLL_EXPORT  RpcInterface
	{
	public:
		RpcInterface(void);
		virtual ~RpcInterface(void);

	public:
		virtual CErrno			Init(Json::Value & conf);
		virtual CErrno			Cleanup(void);
		virtual CErrno			Update(void);
		virtual void			OnRegisterRpcs(void) {}

	public:
		virtual INT32			SendMsg(INT32 nSessionID, RPCMsgCall * pMsg, BOOL bAddRpc = TRUE);
		virtual INT32			SendMsg(const std::string & strNodeName, RPCMsgCall * pMsg, BOOL bAddRpc = TRUE);

	public:
		RpcManager			*	GetRpcManager() { return m_pRpcManager; }
		UINT16					GetServerPort() { return m_usServerPort; }
		char				*	GetServerName() { return m_szServerName; }
		char				*	GetNetNodeName() { return m_szNetNodeName; }
		char				*	GetServerType() { return m_szRpcType; }
		Net::NetThread 		*	GetNetThread() { return m_pNetThread; }
		IRpcListener		*	GetRpcListener() { return m_pRpcListener; }
		void					RegisterRpc(void);

	private:
		void					TakeOverSync(RPCMsgCall * pMsg);
		void					HandlerMySelfNode(Json::Value & conf);

	protected:
		UINT16					m_usServerPort;
		char					m_szServerName[MAX_NAME_LENGTH];
		char					m_szNetNodeName[MAX_NAME_LENGTH];
		char					m_szRpcType[MAX_NAME_LENGTH];
		RpcManager			*	m_pRpcManager;
		Net::NetThread		*	m_pNetThread;
		IRpcListener		*	m_pRpcListener;
	};

}


#endif