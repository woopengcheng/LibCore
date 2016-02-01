#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/NetNode.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "Coroutine/Coroutine.h"
#include "Timer/inc/TimerHelp.h"
#include "NetLib/inc/NetThread.h"

namespace Msg
{ 

	RpcInterface::RpcInterface(void)
		: m_pRpcManager(NULL)
		, m_pRpcListener(NULL)
		, m_bFirstUpdated(FALSE)
	{
	} 

	RpcInterface::~RpcInterface(void)
	{
	}

	void RpcInterface::RegisterRpc( void )
	{
		OnRegisterRpcs();
	}
	
	BOOL RpcInterface::DeleteRpcCoTask(UINT64 ullMsgID)
	{
		MapRpcCoTasksT::iterator iter = m_mapRpcCoTasks.find(ullMsgID);
		if (iter != m_mapRpcCoTasks.end())
		{
			m_mapRpcCoTasks.erase(iter);

			return TRUE;
		}
		else
		{
			gErrorStream("DeleteRpcCoTask error. no this msgid.ID=" << ullMsgID);
		}

		return FALSE;
	}

	BOOL RpcInterface::AddRpcCoTask(SRpcCoTask * pTask)
	{
		if (pTask && pTask->pMsg)
		{
			MapRpcCoTasksT::iterator iter = m_mapRpcCoTasks.find(pTask->pMsg->m_ullMsgID);
			if (iter == m_mapRpcCoTasks.end())
			{
				m_mapRpcCoTasks.insert(std::make_pair(pTask->pMsg->m_ullMsgID, pTask));

				return TRUE;
			}
		}		
		if (pTask->pMsg)
		{
			gErrorStream("AddRpcCoTask error. no this msgid.ID=" << pTask->pMsg->m_ullMsgID << ":msgMethod=" << pTask->pMsg->m_szMsgMethod);
		}

		return FALSE;

	}

	BOOL RpcInterface::ResumeRpcCoTask(UINT64 ullMsgID)
	{
		MapRpcCoTasksT::iterator iter = m_mapRpcCoTasks.find(ullMsgID);
		if (iter != m_mapRpcCoTasks.end())
		{
			SRpcCoTask * pTask = iter->second;
			if (pTask)
			{
				Coroutine::CoResume(pTask->pCoID);
			}

			return TRUE;
		}
		else
		{
			gErrorStream("ResumeRpcCoTask error. no this msgid.ID=" << ullMsgID);
		}

		return FALSE;

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

		Coroutine::CoCleanup();
		return CErrno::Success();
	} 
	
	CErrno RpcInterface::Update( void )
	{ 
		if (!m_bFirstUpdated)
		{
//			Coroutine::CoInit();
			m_bFirstUpdated = TRUE;
		}

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

	static void fiberProc(void * pArg)
	{
		SRpcCoTask * pTask = (SRpcCoTask *)pArg;
		if(pTask && pTask->pMsg)
		{
			RPCMsgCall * pMsg = pTask->pMsg;
			while (pMsg->GetSyncResult() == SYNC_RESULT_START_RETURN)
			{
				gErrorStream("MsgName=" << pMsg->m_szMsgMethod);
				Coroutine::CoYieldCur();
			}
			
			if (pTask->pInterface)
			{
				pTask->pInterface->DeleteRpcCoTask(pMsg->m_ullMsgID);
			}

			Coroutine::CoRelease(pTask->pCoID);
			SAFE_DELETE(pTask);
			SAFE_DELETE_NEW(pMsg);
		}
	}

	void RpcInterface::TakeOverSync(RPCMsgCall * pMsg)
	{
		if (pMsg->GetSyncType() == SYNC_TYPE_SYNC)
		{ 
			SRpcCoTask * pTask = new SRpcCoTask;
			pTask->pMsg = pMsg;
			pTask->pInterface = this;

			Coroutine::CoCreate(&(pTask->pCoID), fiberProc, pTask);
			AddRpcCoTask(pTask);
// 			while (pMsg->GetSyncResult() == SYNC_RESULT_START_RETURN)
// 			{
// 				Update();
// 			}
//			SAFE_DELETE_NEW(pMsg);
		}
	}

}