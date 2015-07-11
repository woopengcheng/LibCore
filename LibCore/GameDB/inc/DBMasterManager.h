#ifndef __gamedb_db_master_manager_h__
#define __gamedb_db_master_manager_h__
#include "MsgLib/inc/RpcServerManager.h" 

namespace Net
{
	class INetReactor;
}

namespace Msg
{
	class RpcInterface;
	class RPCMsgCall;
	struct SPing;
}

namespace GameDB
{
	class DLL_EXPORT DBMasterManager : public Msg::RpcServerManager
	{
	public:
		DBMasterManager(Msg::RpcInterface * pRpcInterface ,Net::INetReactor * pNetReactor) 
			: RpcServerManager(pRpcInterface , pNetReactor)
		{}
		virtual ~DBMasterManager(void){}   

	public: 
		virtual INT32 HandlePing( Net::ISession * pSession , Msg::SPing * pPing );
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0 , void * context = NULL);

	protected:
	private:
	};


}


#endif