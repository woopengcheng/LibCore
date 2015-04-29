#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "MsgLib/inc/RpcInterface.h"
#include "GameDB/inc/DBClientInterface.h"
 

namespace Client
{  
	class  RpcInstance : public GameDB::DBClientInterface
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