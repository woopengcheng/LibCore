#include "ThreadPool/inc/ThreadPoolInterface.h"
#include "Timer/inc/TimerHelp.h"
#include "DBSlave.h" 
#include "SlaveHandler.h"

namespace Server
{
	DBSlave::DBSlave(void)
		: ThreadPool::ThreadSustainTask(0 , "DBSlave" )
		, m_objMasterSessionID(0)
		, m_nSlaveCount(0)
	{

	}

	INT32 DBSlave::Init(Json::Value & conf)
	{
		Json::Value objThreads = conf.get("thread" , Json::Value());
		InitThread(objThreads);  

		return DBSlaveInterface::Init(conf);
	}

	INT32 DBSlave::Update(void)
	{  
		return DBSlaveInterface::Update();
	}

	INT32 DBSlave::InitThread(Json::Value & conf)
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

	INT32 DBSlave::Cleanup(void)
	{
		ThreadPool::ThreadPoolInterface::GetInstance().Cleanup();
		return DBSlaveInterface::Cleanup();
	}

	void DBSlave::OnCreateDatabase(const GameDB::SDBSlaveInfo & objInfo)
	{
		SlaveHandler * pHandler = new SlaveHandler(++m_nSlaveCount , this);
		if (pHandler)
		{
			pHandler->SetSlaveInfo(objInfo);
			m_mapSalves.insert(std::make_pair(m_nSlaveCount , pHandler));
		}
	}

	GameDB::SDBSlaveInfo * DBSlave::GetDBSlaveInfo(INT32 nID)
	{
		CollectionSlavesT::iterator iter = m_mapSalves.find(nID);
		if (iter != m_mapSalves.end())
		{
			return &iter->second->GetSlaveInfo();
		}

		return NULL;
	}

	void DBSlave::StartAuth()
	{
		CollectionSlavesT::iterator iter = m_mapSalves.begin();
		for (;iter != m_mapSalves.end();++iter)
		{
			SlaveHandler * pHandler = iter->second;
			if (pHandler)
			{
				pHandler->StartAuth();
			}
		}
	}

	DBSlave::~DBSlave(void)
	{
		CollectionSlavesT::iterator iter = m_mapSalves.begin();
		for (;iter != m_mapSalves.end();++iter)
		{
			SAFE_DELETE(iter->second);
		}

		m_mapSalves.clear();
	}


}