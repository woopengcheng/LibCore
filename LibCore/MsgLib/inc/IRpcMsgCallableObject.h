#ifndef __msg_i_rpc_msg_callable_object_h__
#define __msg_i_rpc_msg_callable_object_h__ 
#include "MsgCommon.h"  
#include "RpcInterface.h"
#include "ICallableObject.h"
#include "RpcBase.h"

namespace Msg
{



	class DLL_EXPORT  IRpcMsgCallableObject : public Rpc
	{
	public: 
		IRpcMsgCallableObject(Object id , RpcManager * pRpcManager)
			: Rpc(pRpcManager , MAX_MSG_TIME_OUT , id)  
		{ 
			Assert(pRpcManager);

			pRpcManager->AddCallableObject(this);  
		}   
	};

}


#endif