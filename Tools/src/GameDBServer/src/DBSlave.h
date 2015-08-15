#ifndef __server_db_slave_h__
#define __server_db_slave_h__   
#include "GameDB/inc/DBSlaveInterface.h"
#include "ThreadPool/inc/ThreadTask.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"
#include "json/json.h"


namespace Server
{  
	class SlaveHandler;

	class  DBSlave : public GameDB::DBSlaveInterface  , ThreadPool::ThreadSustainTask
	{ 
	public:
		typedef std::map<INT32 , SlaveHandler *> CollectionSlavesT;

	public:
		DBSlave(void) ;
		virtual ~DBSlave(void);

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
		virtual void   OnCreateDatabase(const GameDB::SDBSlaveInfo & objInfo);
		GameDB::SDBSlaveInfo * GetDBSlaveInfo(INT32 nID);

	public: 
		void		   StartAuth();
		void		   SetMasterSessionID(Msg::Object nMasterSessionID){ m_objMasterSessionID = nMasterSessionID; }
		Msg::Object    GetMasterSessionID( ){ return m_objMasterSessionID; }

	private: 
		INT32		   InitThread(Json::Value & conf); 

	private:
		INT32				m_nSlaveCount;
		Msg::Object			m_objMasterSessionID;
		CollectionSlavesT	m_mapSalves;
	};  
	 

}


#endif