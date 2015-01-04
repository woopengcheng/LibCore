#ifndef __msg_msg_common_h__
#define __msg_msg_common_h__
#include "Common.h"
#include "tbb/concurrent_unordered_map.h"
#include "tbb/concurrent_hash_map.h"
#include "tbb/concurrent_queue.h"
#include "tbb/concurrent_priority_queue.h"
#include "vector"
#include "Object.h"

#define MSG_ID  UINT64

namespace Msg
{ 
#define tbb_unordered_map     tbb::concurrent_unordered_map 
#define tbb_hash_map          tbb::concurrent_hash_map 
#define tbb_queue             tbb::concurrent_queue 
#define tbb_priority_queue    tbb::concurrent_priority_queue

#define DEFAULT_RPC_CALLABLE_ID          Object(0)    //5 默认RPC的callable ID
#define DEFAULT_RPC_MSG_ID               1    //5 默认的RPC的消息ID
#define DEFAULT_RPC_PING_ID              2    //5 默认的RPC的消息ID
#define DEFAULT_RPC_PING_TIMEOUT         2

#define DEFAULT_MSG_THREAD_ID            3
#define DEFAULT_RPC_MSG_THREAD_ID        5
#define DEFAULT_MSG_HANDLE_THREAD_ID     4

#define MAX_MSG_METHOD_NAME_LENGTH       60
#define MSG_MAX_PARAMETER_NUMBER         10 

#define MAX_MSG_TIME_OUT                 15

#define RPCServerProxy "_X" 
#define RPCClientProxy "_Y" 
#define RPCClient "_C"
#define RPCServer "_S"
#define RPCTimeout "_T" 

#define RPC_NAMEDEFINE(RPC_Name , MIDDLE , SUFFIX) static const char * g_sz##RPC_Name##MIDDLE = #RPC_Name#SUFFIX;  

#define RPC_DEFINE(RPC_Name ) static const char * g_sz##RPC_Name##_RpcCall = #RPC_Name; \
	RPC_NAMEDEFINE(RPC_Name , _RpcServer , _S)\
	RPC_NAMEDEFINE(RPC_Name , _RpcClient , _C)\
	RPC_NAMEDEFINE(RPC_Name , _RpcServerProxy , _X)\
	RPC_NAMEDEFINE(RPC_Name , _RpcClientProxy , _Y)\
	RPC_NAMEDEFINE(RPC_Name , _RpcTimeout , _T)

	enum ERPCServerNames
	{
		RPC_ConnSrv = 0 ,

		MAX_RPC_SERVERS ,
	};

	const char g_szRpcTest1Name[MAX_RPC_SERVERS][25] =
		{ 
			"connsrv"  // RPC_ConnSrv
		};
	const char g_szRpcTest2Name[] = "server2";
	 
}
#endif