#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBServerInterface.h"
#include "ThreadPool/inc/ThreadTask.h"
#include "json/json.h"


#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"

namespace Server
{  
	class  DBServer : public GameDB::DBServerInterface , ThreadPool::ThreadSustainTask
	{ 
	public:
		DBServer(void) 
			: ThreadPool::ThreadSustainTask(1 , "DBServer" )
		{ 
		}
		virtual ~DBServer(void){} 

	public:
		static DBServer & GetInstance()
		{
			static DBServer m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public:  
		virtual void   OnRegisterRpcs(void); 
		virtual CErrno  Update(void); 
	};  
	 

}


#endif