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
		virtual CErrno OnConnected(Msg::RpcInterface * pRpcInterface , INT32 nSessionID , const std::string & strNetNodeName , bool bReconnect = false){ return CErrno::Success();} 
		virtual CErrno OnDisconnected(RpcInterface * pRpcInterface, INT32 nSessionID, INT32 nPeerSessionID){ return CErrno::Success();}
	};

}


#endif