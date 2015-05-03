#ifndef __msg_rpc_instance_h__
#define __msg_rpc_instance_h__  
#include "MsgLib/inc/RpcInterface.h"
 

namespace Client
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
		virtual void OnRegisterRpcs(); 
	};  

	//5 这句话必须定义.给RPC或者消息调用.
#define MSG_INSTANCE (Client::RpcInstance::GetInstance())
}


#endif