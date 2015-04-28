#include "GameDB/inc/DBServerInterface.h"
#include "json/json.h"

namespace  Server
{
	class DBServer : public GameDB::DBServerInterface
	{
	public:
		DBServer( ):GameDB::DBServerInterface(){}
		virtual ~DBServer(void){}

	public:
		static DBServer & GetInstance()
		{
			static DBServer m_sRpcInterface;
			return m_sRpcInterface;
		} 
	private:
	};
}