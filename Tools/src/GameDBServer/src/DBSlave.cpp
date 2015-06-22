#include "DBSlave.h" 
#include "ThreadPoolLib/inc/ThreadPoolInterface.h"
#include "RPCCallFuncs.h"
#include "TimerLib/inc/TimerHelp.h"

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
			UINT32 priority = objThread.get("priority" , 0).asUInt();
			UINT32 count = objThread.get("count" , 1).asUInt(); 

			mapThreads[priority] = count;    
		}

		ThreadPool::ThreadPoolInterface::GetInstance().Init(mapThreads , TRUE);
		ThreadPool::ThreadPoolInterface::GetInstance().Startup();  
		ThreadPool::ThreadPoolInterface::GetInstance().AddTask(this);  

		return ERR_SUCCESS;
	}

	void DBSlave::RequestSyncData(std::string		strDBName , std::string		strDBDir)
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Server::local_call_SlaveRequestSync("tcp://127.0.0.1:9001", strDBDir , strDBName , targets , Msg::Object(1) , 1);
	}

	void DBSlave::StartAuth(std::string		strName , std::string		strPwd)
	{ 
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Server::local_call_SlaveStartAuth("tcp://127.0.0.1:9001", strName , strPwd , targets , Msg::Object(1) , 1);
	}

	void DBSlave::SelectDB(	std::string		strDBName )
	{
		std::vector<Msg::Object> targets;
		targets.push_back(Msg::Object(1));   
		Server::local_call_SlaveSelectDB("tcp://127.0.0.1:9001", strDBName , targets , Msg::Object(1) , 1);

	}


}