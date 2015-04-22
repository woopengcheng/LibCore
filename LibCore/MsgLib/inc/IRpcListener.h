#ifndef __msg_rpc_listener_h__
#define __msg_rpc_listener_h__ 
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
	
	class RpcInterface; 
	
	/************************************************************************/
	/* ���ڼ���RPC�Ƿ����ӳɹ��͹رյĽӿڡ���д����
	/* 2015��4��22��12:05:00
	/*
	/************************************************************************/
	class DLL_EXPORT  IRpcListener
	{
	public:
		IRpcListener() 
		{

		}
	public:
		virtual INT32 OnListenOn(RpcInterface * pRpcInterface){ return ERR_SUCCESS;} 
		virtual INT32 OnListenOff(RpcInterface * pRpcInterface){ return ERR_SUCCESS;}
	};

}


#endif