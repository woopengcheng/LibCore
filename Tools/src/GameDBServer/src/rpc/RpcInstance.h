#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBServerInterface.h"

namespace Server
{  
	class  RpcInstance : public GameDB::DBServerInterface
	{ 
	public:
		RpcInstance(void)  
		{ 
		}
		virtual ~RpcInstance(void){} 

	public:
		static RpcInstance & GetInstance()
		{
			static RpcInstance m_sRpcInterface;
			return m_sRpcInterface;
		} 

	public: 
		virtual void OnRegisterRpcs(void); 
	};  

}


#endif