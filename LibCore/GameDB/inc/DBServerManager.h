#ifndef __gamedb_db_server_manager_h__
#define __gamedb_db_server_manager_h__
#include "MsgLib/inc/RpcServerManager.h"

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
	class DLL_EXPORT DBServerManager : public Msg::RpcServerManager
	{
	public:
		DBServerManager(Msg::RpcInterface * pRpcInterface ,Net::INetReactor * pNetReactor) 
			: RpcServerManager(pRpcInterface , pNetReactor)
		{}
		virtual ~DBServerManager(void){}   

	public: 
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0 , void * context = NULL);

	protected:
	private:
	};


}


#endif