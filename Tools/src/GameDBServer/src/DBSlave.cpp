#include "DBSlave.h" 
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"

namespace Server
{
	DBSlave::DBSlave(void)
		: ThreadPool::ThreadSustainTask(0 , "DBSlave" )
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
			UINT32 priority = objThread.get("priority" , "0").asUInt();
			UINT32 count = objThread.get("count" , "1").asUInt(); 

			mapThreads[priority] = count;    
		}

		ThreadPool::ThreadPoolInterface::GetInstance().Init(mapThreads , TRUE);
		ThreadPool::ThreadPoolInterface::GetInstance().Startup();  

		return ERR_SUCCESS;
	}


}