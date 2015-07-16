#ifndef __server_db_master_h__
#define __server_db_master_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/IRpcListener.h"
#include "GameDB/inc/DBMasterInterface.h"
#include "ThreadPoolLib/inc/ThreadTask.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"
#include "json/json.h"

namespace Server
{  
	class MasterHandler;
	class SlaveRecord;

	class  DBMaster : public GameDB::DBMasterInterface  , ThreadPool::ThreadSustainTask
	{ 
	public:
		typedef std::vector<MasterHandler *> CollectionMasterHandlersT;
	public:
		DBMaster(void) ;
		virtual ~DBMaster(void);

	public:
		static DBMaster & GetInstance()
		{
			static DBMaster m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public: 
		virtual INT32  Init(Json::Value & conf); 
		virtual INT32  Cleanup(void);
		virtual void   OnRegisterRpcs(void); 
		virtual INT32  Update(void);

	public:
		INT32			CreateMasterHandler(); 
		SlaveRecord *	GetSlaveRecord(const std::string & strDBName);

	private: 
		INT32   InitThread(Json::Value & conf);
	private:
		INT32 m_nHandlerCount;
		CollectionMasterHandlersT m_vecMasterHandlers; 

	};  
	 

	class MasterListener : public Msg::IRpcListener
	{
	public:
		MasterListener(DBMaster * pMaster)
			: m_pDBMaster(pMaster)
		{

		}

	public:
		virtual INT32 OnConnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession);
		virtual INT32 OnDisconnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession);

	private:
		DBMaster * m_pDBMaster;
	};


}


#endif