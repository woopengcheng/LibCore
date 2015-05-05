#ifndef __gamedb_db_client_manager_h__
#define __gamedb_db_client_manager_h__
#include "MsgLib/inc/RpcClientManager.h"

namespace Net
{
	class INetReactor;
}

namespace Msg
{
	class RpcInterface;
}

namespace GameDB
{
	class DLL_EXPORT DBClientManager : public Msg::RpcClientManager
	{
	public:
		DBClientManager(Msg::RpcInterface * pRpcInterface ,Net::INetReactor * pNetReactor) 
			: RpcClientManager(pRpcInterface , pNetReactor)
		{}
		virtual ~DBClientManager(void){}  
		 
	public: 
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0);

	protected:
	private:
	};


}


#endif