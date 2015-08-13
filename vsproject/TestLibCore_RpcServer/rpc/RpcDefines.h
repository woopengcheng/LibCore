#ifndef __msg_Server_rpc_defines_h__
#define __msg_Server_rpc_defines_h__
#include "MsgLib/inc/MsgCommon.h" 
#include "RpcDatas.h" 

namespace Msg
{

#define  RPC_DEFINE_GlobalRpc public:\
	Msg::ObjectMsgCall * TestObject_RpcServer(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID), SINT8 userid1 = 0 , INT16 userid3 = 0 , UINT16 localid4 = 0 , INT32 localid6 = 0 , UINT32 userid7 = 0 , INT64 localid8 = 0 , UINT64 userid9 = 0);\
	Msg::ObjectMsgCall * TestObject1_RpcServer(Net::ISession * pSession , Msg::Object objSrc = Msg::Object(Msg::DEFAULT_RPC_CALLABLE_ID), SINT8 userid1 = 0 , UINT8 localid2 = 0 , INT16 userid3 = 0 , UINT16 localid4 = 0 , double localid10 = 1.0f , float localid11 = 1.0f , std_string localid12 = std::string() , CUtilChunk localid13 = CUtil::Chunk());\
public:\
	static CollectionObjectFuncsT s_setFuncs;\
	static void InitObjectFuncs()\
	{\
		GlobalRpc::s_setFuncs.insert("TestObject");\
		GlobalRpc::s_setFuncs.insert("TestObject1");\
	}\
	virtual BOOL IsHasFunc(const std::string & strFunc)\
	{\
		CollectionObjectFuncsT::iterator iter = GlobalRpc::s_setFuncs.find(strFunc);\
		if (iter != GlobalRpc::s_setFuncs.end())\
		{\
			return TRUE;\
		}\
	return FALSE;\
	}\



}

#endif

