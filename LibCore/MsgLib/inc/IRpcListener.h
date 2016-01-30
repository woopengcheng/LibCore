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
		virtual CErrno OnConnected(Msg::RpcInterface * pRpcInterface , INT32 nSessionID , const std::string & strNetNodeName , bool bReconnect = false){ return CErrno::Success();} 
		virtual CErrno OnDisconnected(RpcInterface * pRpcInterface, INT32 nSessionID, INT32 nPeerSessionID){ return CErrno::Success();}
	};

}


#endif