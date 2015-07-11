#include "ThreadPoolLib/inc/ThreadPoolInterface.h"
#include "DBMaster.h"
#include "MasterHandler.h"
#include "RPCCallFuncs.h"

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

	INT32 DBMaster::CreateMasterHandler()
	{
		new MasterHandler(++m_nHandlerCount , this);

		return m_nHandlerCount;
	}

	Server::MasterHandler * DBMaster::GetMasterHandler(const std::string & strDBName)
	{
		CollectionMasterHandlersT::iterator iter = m_vecMasterHandlers.begin();
		for (;iter != m_vecMasterHandlers.end();++iter)
		{
			MasterHandler * pMasterHandler = *iter;
			if (pMasterHandler && pMasterHandler->GetDBName() == strDBName)
			{
				return pMasterHandler;
			}
		}

		return NULL;
	}

	INT32 MasterListener::OnConnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession)
	{
		if (m_pDBMaster)
		{
			INT32 nMasterHandlerID = m_pDBMaster->CreateMasterHandler();
			return rpc_SyncMasterHandler("tcp://127.0.0.1:9002" , 1 , nMasterHandlerID , nMasterHandlerID);
		}

		return 0;
	}

	INT32 MasterListener::OnDisconnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession)
	{

		return 0;
	}

}