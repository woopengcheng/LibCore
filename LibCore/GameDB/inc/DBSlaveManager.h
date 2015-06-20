#ifndef __gamedb_db_slave_manager_h__
#define __gamedb_db_slave_manager_h__
#include "MsgLib/inc/RpcClientManager.h"

namespace Net
{
	class INetReactor;
}

namespace Msg
{
	class RpcInterface;
	class RPCMsgCall;
}

namespace GameDB
{
	class DLL_EXPORT DBSlaveManager : public Msg::RpcClientManager
	{
	public:
		DBSlaveManager(Msg::RpcInterface * pRpcInterface ,Net::INetReactor * pNetReactor) 
			: RpcClientManager(pRpcInterface , pNetReactor)
		{}
		virtual ~DBSlaveManager(void){}   

	public: 
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0 , void * context = NULL);

	protected:
	private:
	};


}


#endif