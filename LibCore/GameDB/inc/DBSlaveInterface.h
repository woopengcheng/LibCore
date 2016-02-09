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
		DBSlaveInterface( );
		virtual ~DBSlaveInterface(void);

	public: 
		virtual CErrno  Init(Json::Value & conf) override;
		virtual CErrno  Cleanup(void) override;
		virtual CErrno  Update(void) override;
		virtual void	OnCreateDatabase(const SDBSlaveInfo & objInfo){} 

	private: 
		CErrno			InitDB(const Json::Value & conf);
	};
}

#endif
