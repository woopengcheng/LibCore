#include "GameDB/inc/DBServer.h"


namespace  DB
{
	class DB : public GameDB::DBServer
	{
	public:
		DB( Json::Value & conf ):GameDB::DBServer(conf){}
		virtual ~DB(void){}
	protected:
	private:
	};
}