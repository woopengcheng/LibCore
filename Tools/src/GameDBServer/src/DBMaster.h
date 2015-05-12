#ifndef __server_db_master_h__
#define __server_db_master_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBMasterInterface.h"
#include "ThreadPoolLib/inc/ThreadTask.h"
#include "json/json.h"


#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"


namespace Server
{  
	class  DBMaster : public GameDB::DBMasterInterface  , ThreadPool::ThreadSustainTask
	{ 
	public:
		DBMaster(void) ;
		virtual ~DBMaster(void){} 

	public:
		static DBMaster & GetInstance()
		{
			static DBMaster m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public: 
		virtual INT32  Init(Json::Value & conf); 
		virtual void   OnRegisterRpcs(void); 
		virtual INT32  Update(void);

	private: 
		INT32   InitThread(Json::Value & conf);
	};  
	 


}


#endif