#include "ThreadPool/inc/ThreadPoolInterface.h"
#include "GameDB/inc/RemoteNodeDefine.h"
#include "DBMaster.h"
#include "MasterHandler.h"
#include "RPCCallFuncs.h"
#include "SlaveRecord.h"

namespace Server
{
	DBMaster::DBMaster(void)
		: ThreadPool::ThreadSustainTask(101 , "DBMaster" )
		, m_nHandlerCount(0)
		, m_llServerID(-1)
	{
		m_pRpcListener = new MasterListener(this);
	}

	DBMaster::~DBMaster(void)
	{
		SAFE_DELETE(m_pRpcListener);

		VecMasterHandlersT::iterator iter = m_vecMasterHandlers.begin();
		for (;iter != m_vecMasterHandlers.end();++iter)
		{
			SAFE_DELETE(*iter);
		}
		m_vecMasterHandlers.clear();
	}

	CErrno DBMaster::Init(Json::Value & conf)
	{
		Json::Value objThreads = conf.get("thread" , Json::Value());
		InitThread(objThreads); 
		
		return DBMasterInterface::Init(conf);
	}

	CErrno DBMaster::Update(void)
	{  
		static bool bFirst = true;
		if (bFirst)
		{
			VecMasterHandlersT::iterator iter = m_vecMasterHandlers.begin();
			for (; iter != m_vecMasterHandlers.end(); ++iter)
			{
				MasterHandler * pHandler = *iter;
				if (pHandler && m_llServerID > 0)
				{
					TestRpcData test1;
					test1.p1 = 11;
					test1.p2 = 12;
					test1.p3 = 4;
					test1.p4 = 5;
					test1.p6 = 7;
					test1.p7 = 8;
					test1.p8 = 9;
					test1.p9 = 10;
					test1.p10 = 2;
					test1.p11 = 5;
					test1.p12 = 12;
					test1.p13 = CUtilChunk("14", sizeof("14"));
					test1.p5.push_back(1);
					test1.p5.push_back(2);
					TestRpcData2 test2;

					rpc_testParamsAndRpcDatas(pHandler->GetSessionID(), GetServerID(), pHandler->GetObjectID(), test1, test2);

					bFirst = false;
				}
			}
		}
		return DBMasterInterface::Update();
	}
	 
	CErrno DBMaster::InitThread(Json::Value & conf)
	{
		std::map<UINT32 , UINT32> mapThreads;
		INT32 nCount = conf.size(); 
		for (INT32 i = 0 ;i < nCount; ++ i)
		{     
			Json::Value objThread = conf[i]; 
			UINT32 priority = objThread.get("priority" , 0).asUInt();
			SetThreadPriority(priority);
			UINT32 count = objThread.get("count" , 1).asUInt(); 

			mapThreads[priority] = count;    
		}

		ThreadPool::ThreadPoolInterface::GetInstance().Init(mapThreads , TRUE);
		ThreadPool::ThreadPoolInterface::GetInstance().Startup();  
		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);  

		return CErrno::Success();
	}

	INT32 DBMaster::CreateMasterHandler(INT32 nSessionID)
	{
		MasterHandler * pMasterHandler = new MasterHandler(++m_nHandlerCount , nSessionID , this);
		m_vecMasterHandlers.push_back(pMasterHandler);
		return m_nHandlerCount;
	}

	SlaveRecord * DBMaster::GetSlaveRecord(const std::string & strDBName)
	{
		VecMasterHandlersT::iterator iter = m_vecMasterHandlers.begin();
		for (;iter != m_vecMasterHandlers.end();++iter)
		{
			MasterHandler * pMasterHandler = *iter;
			if (pMasterHandler)
			{
				SlaveRecord * pRecord = pMasterHandler->GetSlaveRecord(strDBName); 
				if (pRecord)
				{
					return pRecord;
				}
			}
		}

		return NULL;
	}

	CErrno DBMaster::Cleanup(void)
	{

		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();
		return DBMasterInterface::Cleanup();
	}

	CErrno MasterListener::OnConnected(Msg::RpcInterface * pRpcInterface , INT32 nSessionID, const std::string & strNetNodeName, bool bReconnect/* = false*/)
	{
		if (m_pDBMaster)
		{
			if (strNetNodeName == g_strGameDBNodes[NETNODE_DBMASTER_TO_DBSLAVE])
			{
				INT32 nMasterHandlerID = m_pDBMaster->CreateMasterHandler(nSessionID);
				rpc_SyncMasterHandler(nSessionID, Msg::Object(1) , Msg::Object(nMasterHandlerID) , nMasterHandlerID);
			}

			if (strNetNodeName == g_strGameDBNodes[NETNODE_DBMASTER_TO_DBSERVER])
			{
				INT32 nMasterHandlerID = m_pDBMaster->CreateMasterHandler(nSessionID);
			}
		}

		return CErrno::Success();
	}

	CErrno MasterListener::OnDisconnected(Msg::RpcInterface * pRpcInterface, INT32 nSessionID, INT32 nPeerSessionID)
	{

		return CErrno::Success();
	}

}