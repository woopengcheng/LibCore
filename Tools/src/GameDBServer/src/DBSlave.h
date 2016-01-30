#ifndef __server_db_slave_h__
#define __server_db_slave_h__   
#include "ThreadPool/inc/ThreadTask.h"
#include "GameDB/inc/DBSlaveInterface.h"
#include "GameDB/inc/HashTable.h"
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/Database.h"
#include "GameDB/inc/Operate.h"
#include "MsgLib/inc/IRpcListener.h"
#include "json/json.h"


namespace Server
{  
	class SlaveHandler;

	class  DBSlave : public GameDB::DBSlaveInterface  , ThreadPool::ThreadSustainTask
	{ 
	public:
		typedef std::map<std::string , SlaveHandler *> CollectionSlavesT;

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
		virtual CErrno			Init(Json::Value & conf); 
		virtual	CErrno			Cleanup(void);
		virtual void			OnRegisterRpcs(void); 
		virtual CErrno			Update(void);
		virtual void			OnCreateDatabase(const GameDB::SDBSlaveInfo & objInfo);
		SlaveHandler		* 	GetSlaveHandler(const std::string & strDBName);

	public: 
		void					StartAuth();
		void					SetMasterID(Msg::Object nMasterID){ m_objMasterID = nMasterID; }
		Msg::Object				GetMasterID( ){ return m_objMasterID; }
		void					SetSlaveSessionID(const std::string & strDBName , INT32 nSessionID);

	private: 
		CErrno					InitThread(Json::Value & conf); 

	private:
		INT32					m_nSlaveCount;
		Msg::Object				m_objMasterID;
		CollectionSlavesT		m_mapSalves;
	};  
	 

	class SlaveListener : public Msg::IRpcListener
	{
	public:
		SlaveListener(DBSlave * pMaster)
			: m_pDBSlave(pMaster)
		{

		}

	public:
		virtual CErrno OnConnected(Msg::RpcInterface * pRpcInterface, INT32 nSessionID, const std::string & strNetNodeName);
		virtual CErrno OnDisconnected(Msg::RpcInterface * pRpcInterface, INT32 nSessionID, INT32 nPeerSessionID);

	private:
		DBSlave * m_pDBSlave;
	};
}


#endif