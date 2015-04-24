#include "GameDB/inc/DBServer.h"


namespace  DB
{
	class DBServer : public GameDB::DBServer
	{
	public:
		DBServer( Json::Value & conf ):GameDB::DBServer(conf){}
		virtual ~DBServer(void){}
	protected:
	private:
	};
}