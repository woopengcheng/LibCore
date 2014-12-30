#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "RpcInterface.h"
 

namespace Proxy
{  
	class  RpcInstance : public Msg::RpcInterface
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