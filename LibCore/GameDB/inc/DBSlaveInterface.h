#ifndef __gamedb_db_slave_interface_h__
#define __gamedb_db_slave_interface_h__   
#include "GameDB/inc/DBCommon.h" 
#include "MsgLib/inc/RpcInterface.h" 
#include "GameDB/inc/Environment.h"
#include "GameDB/inc/SlaveSession.h"
#include "json/json.h"

namespace GameDB
{   
	class DLL_EXPORT DBSlaveInterface : public Msg::RpcInterface
	{   
	public:  
		typedef std::map<std::string , SDBSlaveInfo> CollectionDatabasesT;

	public:
		DBSlaveInterface( );
		virtual ~DBSlaveInterface(void);

	public: 
		virtual INT32  Init(Json::Value & conf); 
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void);  
		
	public:
		SDBSlaveInfo  * GetDBSlaveInfo(std::string strRemoteName);

	private: 
		INT32    InitDB(const Json::Value & conf);
		INT32    InitNet(const Json::Value & conf);

	protected: 
		CollectionDatabasesT m_mapDatabases;
	};

	DECLARE_BOOST_POINTERS(DBSlaveInterface); 
}

#endif
