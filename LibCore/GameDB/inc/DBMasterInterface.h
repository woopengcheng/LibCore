#ifndef __gamedb_db_master_interface_h__
#define __gamedb_db_master_interface_h__   
#include "GameDB/inc/DBCommon.h" 
#include "MsgLib/inc/RpcInterface.h" 
#include "json/json.h"
#include "GameDB/inc/Environment.h"

namespace GameDB
{     
	class DLL_EXPORT DBMasterInterface : public Msg::RpcInterface
	{   
	public:
		DBMasterInterface( );
		virtual ~DBMasterInterface(void);

	public: 
		virtual INT32  Init(Json::Value & conf); 
		virtual INT32  Cleanup(void);
		virtual INT32  Update(void);   

	private: 
		INT32    InitNet(const Json::Value & conf); 
	};

	DECLARE_BOOST_POINTERS(DBMasterInterface); 
}

#endif
