#pragma once   //5 resolve the 使用VS2010在项目中编写C++头文现出"PCH 警告:标头停止点不能位于宏或#if块中"异常的解
#ifndef __msg_msg_name_define_h__
#define __msg_msg_name_define_h__
#include "MsgCommon.h"

#ifdef WIN32
#pragma warning(disable : 4003)
#endif

#define RPC_NAMEDEFINE(RPC_Name , SUFFIX)  const char * g_sz##RPC_Name##SUFFIX = #RPC_Name#SUFFIX;  
 
#define RPC_DEFINE(RPC_Name) RPC_NAMEDEFINE(RPC_Name)\
	RPC_NAMEDEFINE(RPC_Name , _RPCServer)\
	RPC_NAMEDEFINE(RPC_Name , _RPCClient)\
	RPC_NAMEDEFINE(RPC_Name , _RPCProxy)\
	RPC_NAMEDEFINE(RPC_Name , _RPCTimeout)


namespace Msg
{ 
	static const char * sz_local_call_Test = "local_call_test";
	static const char * sz_local_call_WorldTest = "local_call_WorldTest";
	 
// 	RPC_DEFINE(TestObject);
//	const char * g_szTestObject = "TestObject";
	static const char * g_szTestObject_RpcCall = "TestObject";
	static const char * g_szTestObject_RpcServer = "TestObject_S";
	static const char * g_szTestObject_RpcClient = "TestObject_C";
	static const char * g_szTestObject_RpcServerProxy = "TestObject_X";
	static const char * g_szTestObject_RpcClientProxy = "TestObject_Y";
	static const char * g_szTestObject_RpcTimeout = "TestObject_T";
}

#endif
