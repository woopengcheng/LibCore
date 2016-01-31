#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/NetNode.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "Timer/inc/TimerHelp.h"
#include "NetLib/inc/NetThread.h"

namespace Msg
{ 

	RpcInterface::RpcInterface(void)
		: m_usServerPort(0)
		, m_pRpcManager(NULL)
		, m_pRpcListener(NULL)
	{
		memset(m_szServerName , 0 , sizeof(m_szServerName));
		memset(m_szNetNodeName , 0 , sizeof(m_szNetNodeName));
		memset(m_szRpcType , 0 , sizeof(m_szRpcType));

	} 

	RpcInterface::~RpcInterface(void)
	{
	}

	void RpcInterface::RegisterRpc( void )
	{
		OnRegisterRpcs();
	}
	
	CErrno RpcInterface::Init(Json::Value & conf)
	{   
		HandlerMySelfNode(conf);

		if (!m_pRpcManager)
		{
			m_pRpcManager = new RpcManager(this);
			m_pRpcManager->Init();
		}
		if (!m_pNetThread)
		{
			m_pNetThread = new Net::NetThread;  //5 ��Ϊһ��Task�̻߳��Զ��ͷ�.�Լ�����cleanup.
			m_pNetThread->Init(conf);
		}

		RegisterRpc();

		return CErrno::Success(); 
	}

	void RpcInterface::HandlerMySelfNode(Json::Value & conf)
	{
		Json::Value server = conf.get("server", Json::Value());
		std::string strNodeName = server.get("net_node_name", "").asCString();

		NetNode::GetInstance().InsertMyselfNodes(strNodeName , this);

	}

	CErrno RpcInterface::Cleanup( void )
	{
		if (m_pRpcManager)
		{
			m_pRpcManager->Cleanup();
			SAFE_DELETE(m_pRpcManager);
		}
				
		return CErrno::Success();
	} 
	
	CErrno RpcInterface::Update( void )
	{ 
		if (m_pRpcManager)
		{
			m_pRpcManager->Update();
		}

		Timer::TimerHelper::sleep(1);
		return CErrno::Success();
	}	

	INT32 RpcInterface::SendMsg( INT32 nSessionID , RPCMsgCall * pMsg  , BOOL bAddRpc/* = TRUE*/)
	{   
		if (m_pRpcManager)
		{  
			INT32 nResult = m_pRpcManager->SendMsg(nSessionID , pMsg , bAddRpc);
			if (nResult >= 0)
			{
				TakeOverSync(pMsg);
			}
			return nResult;
		}

		return -1;
	} 
	
	INT32 RpcInterface::SendMsg(const std::string & strNodeName , RPCMsgCall * pMsg , BOOL bAddRpc /*= TRUE*/)
	{
		if (m_pRpcManager)
		{
			INT32 nResult = m_pRpcManager->SendMsg(strNodeName, pMsg, bAddRpc);
			if (nResult >= 0)
			{
				TakeOverSync(pMsg);
			}
			return nResult;
		}

		return -1; 
	}

	void RpcInterface::TakeOverSync(RPCMsgCall * pMsg)
	{
		if (pMsg->GetSyncType() == SYNC_TYPE_SYNC)
		{ 
			while (pMsg->GetSyncResult() == SYNC_RESULT_START_RETURN)
			{
				Update();
			}
			SAFE_DELETE_NEW(pMsg);
		}
	}

}