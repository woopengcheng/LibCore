#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/NetNode.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "Timer/inc/TimerHelp.h"

namespace Msg
{ 

	RpcInterface::RpcInterface(void)
		: m_usServerPort(0)
		, m_pRpcManager(NULL)
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
		if (m_pRpcManager)
		{
			m_pRpcManager = new RpcManager(this);
		}

		RegisterRpc();

		return CErrno::Success(); 
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
			if (nResult >= 0 && bAddRpc)
			{
				m_pRpcManager->InsertSendRpc(pMsg); 

				TakeOverSync(pMsg);
			}
			return nResult;
		}

		return -1;
	} 
	
	INT32 RpcInterface::SendMsg(const std::string & strNodeName , RPCMsgCall * pMsg , BOOL bAddRpc /*= TRUE*/)
	{
		if (NetNode::GetInstance().IsInMyselfNodes(strNodeName))
		{
			RpcInterface * pInterface = NetNode::GetInstance().GetMyselfNode(strNodeName);
			if (pInterface != NULL)
			{
				m_pRpcManager->InsertSendRpc(pMsg);
				m_pRpcManager->PostMsg(strNodeName, pMsg);
			}
			return 0;
		}
		else
		{
			return m_pRpcManager->SendMsg(strNodeName, pMsg, bAddRpc);
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