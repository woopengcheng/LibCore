#ifndef __msg_rpc_listener_h__
#define __msg_rpc_listener_h__ 
#include "MsgCommon.h" 

namespace Msg
{
	
	class RpcInterface; 
	
	class DLL_EXPORT  IRpcListener
	{
	public:
		IRpcListener() 
		{

		}
	public:
		virtual INT32 OnListenOn(RpcInterface * pRpcInterface){ return FALSE;} 
		virtual INT32 OnListenOff(RpcInterface * pRpcInterface){ return FALSE;}
	};

}


#endif