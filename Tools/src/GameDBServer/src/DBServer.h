#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBServerInterface.h"

namespace Server
{  
	class  DBServer : public GameDB::DBServerInterface
	{ 
	public:
		DBServer(void)  
		{ 
		}
		virtual ~DBServer(void){} 

	public:
		static DBServer & GetInstance()
		{
			static DBServer m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public: 
		virtual void OnRegisterRpcs(void); 
	};  

}


#endif