#ifndef __server_db_master_h__
#define __server_db_master_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "MsgLib/inc/IRpcListener.h"
#include "GameDB/inc/DBMasterInterface.h"
#include "ThreadPool/inc/ThreadTask.h"
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
		virtual CErrno  Init(Json::Value & conf); 
		virtual CErrno  Cleanup(void);
		virtual void   OnRegisterRpcs(void); 
		virtual CErrno  Update(void);

	public:
		INT32			CreateMasterHandler(INT32 nSessionID); 
		SlaveRecord *	GetSlaveRecord(const std::string & strDBName);

	private: 
		CErrno   InitThread(Json::Value & conf);
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
		virtual CErrno OnConnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pClientSession , const std::string & strNetNodeName);
		virtual CErrno OnDisconnected(Msg::RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession);

	private:
		DBMaster * m_pDBMaster;
	};


}


#endif