#include "ThreadPoolLib/inc/ThreadPoolInterface.h"
#include "Common/RemoteNodeDefine.h"
#include "DBMaster.h"
#include "MasterHandler.h"
#include "RPCCallFuncs.h"
#include "SlaveRecord.h"

namespace Server
{
	DBMaster::DBMaster(void)
		: ThreadPool::ThreadSustainTask(0 , "DBMaster" )
		, m_nHandlerCount(0)
	{
		m_pRpcListener = new MasterListener(this);
	}

	DBMaster::~DBMaster(void)
	{
		SAFE_DELETE(m_pRpcListener);

		CollectionMasterHandlersT::iterator iter = m_vecMasterHandlers.begin();
		for (;iter != m_vecMasterHandlers.end();++iter)
		{
			SAFE_DELETE(*iter);
		}
		m_vecMasterHandlers.clear();
	}

	INT32 DBMaster::Init(Json::Value & conf)
	{
		Json::Value objThreads = conf.get("thread" , Json::Value());
		InitThread(objThreads); 
		
		return DBMasterInterface::Init(conf);
	}

	INT32 DBMaster::Update(void)
	{  

		return DBMasterInterface::Update();
	}
	 
	INT32 DBMaster::InitThread(Json::Value & conf)
	{
		std::map<UINT32 , UINT32> mapThreads;
		INT32 nCount = conf.size(); 
		for (INT32 i = 0 ;i < nCount; ++ i)
		{     
			Json::Value objThread = conf[i]; 
			UINT32 priority = objThread.get("priority" , 0).asUInt();
			UINT32 count = objThread.get("count" , 1).asUInt(); 

			mapThreads[priority] = count;    
		}

		ThreadPool::ThreadPoolInterface::GetInstance().Init(mapThreads , TRUE);
		ThreadPool::ThreadPoolInterface::GetInstance().Startup();  
		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);  

		return ERR_SUCCESS;
	}

	INT32 DBMaster::CreateMasterHandler(INT32 nSessionID)
	{
		MasterHandler * pMasterHandler = new MasterHandler(++m_nHandlerCount , nSessionID , this);
		m_vecMasterHandlers.push_back(pMasterHandler);
		return m_nHandlerCount;
	}

	SlaveRecord * DBMaster::GetSlaveRecord(const std::string & strDBName)
	{
		CollectionMasterHandlersT::iterator iter = m_vecMasterHandlers.begin();
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

	INT32 DBMaster::Cleanup(void)
	{

		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();
		return DBMasterInterface::Cleanup();
	}

	INT32 MasterListener::OnConnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pClientSession ,const std::string & strNetNodeName)
	{
		if (m_pDBMaster)
		{
			if (strNetNodeName == g_netnodes[NETNODE_DBSLAVE])
			{
				INT32 nMasterHandlerID = m_pDBMaster->CreateMasterHandler(pClientSession->GetSessionID());
				return rpc_SyncMasterHandler(pClientSession->GetSessionID() , Msg::Object(1) , Msg::Object(nMasterHandlerID) , nMasterHandlerID);
			}

			if (strNetNodeName == g_netnodes[NETNODE_DBSERVER])
			{
				INT32 nMasterHandlerID = m_pDBMaster->CreateMasterHandler(pClientSession->GetSessionID());

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
				test1.p13 = LibCore_Chunk("14" , sizeof("14"));
				test1.p5.push_back(1);
				test1.p5.push_back(2);
				TestRpcData2 test2;
				test2.p1 = 11;
				test2.p2 = 12;
				test2.p3 = 4;
				test2.p4 = 5; 
				test2.p6 = 7;
				test2.p7 = 8;
				test2.p8 = 9;
				test2.p9 = 10; 
				return rpc_testParamsAndRpcDatas(pClientSession->GetSessionID() ,1 ,nMasterHandlerID , test1 , test2);
			}
		}

		return 0;
	}

	INT32 MasterListener::OnDisconnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession)
	{

		return 0;
	}

}