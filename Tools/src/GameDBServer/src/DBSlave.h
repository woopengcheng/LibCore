#ifndef __server_db_slave_h__
#define __server_db_slave_h__   
#include "GameDB/inc/DBSlaveInterface.h"
#include "ThreadPoolLib/inc/ThreadTask.h"
#include "json/json.h"


#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"


namespace Server
{  
	class  DBSlave : public GameDB::DBSlaveInterface  , ThreadPool::ThreadSustainTask
	{ 
	public:
		DBSlave(void) ;
		virtual ~DBSlave(void){} 

	public:
		static DBSlave & GetInstance()
		{
			static DBSlave m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public: 
		virtual INT32  Init(Json::Value & conf); 
		virtual	INT32  Cleanup(void);
		virtual void   OnRegisterRpcs(void); 
		virtual INT32  Update(void);

	public:
		void		StartAuth(std::string		strName , std::string		strPwd);
		void		SelectDB(std::string		strDBName );
		void		RequestSyncData(std::string		strDBName , std::string		strDBDir);
		void		SetMasterSessionID(Msg::Object nMasterSessionID){ m_objMasterSessionID = nMasterSessionID; }
		Msg::Object GetMasterSessionID( ){ return m_objMasterSessionID; }

	private: 
		INT32   InitThread(Json::Value & conf); 
	private:
		Msg::Object	m_objMasterSessionID;
	};  
	 

}


#endif