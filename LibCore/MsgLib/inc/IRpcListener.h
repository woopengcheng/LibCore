#ifndef __msg_rpc_listener_h__
#define __msg_rpc_listener_h__ 
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
	
	class RpcInterface; 
	
	/************************************************************************/
	/* 用于监听RPC是否连接成功和关闭的接口。重写即可
	/* 2015年4月22日12:05:00
	/*
	/************************************************************************/
	class DLL_EXPORT  IRpcListener
	{
	public:
		IRpcListener() 
		{

		}
	public:
		virtual INT32 OnConnected(RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession){ return ERR_SUCCESS;} 
		virtual INT32 OnDisconnected(RpcInterface * pRpcInterface , Net::ISession * pServerSession , Net::ISession * pClientSession){ return ERR_SUCCESS;}
	};

}


#endif