#ifndef __server_rpc_defines_h__
#define __server_rpc_defines_h__
#include "MsgCommon.h"  

namespace Server
{  
#define  RPC_DEFINE_TestObject public:\
	Msg::ObjectMsgCall * TestObject_RpcServer(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc);
   
}


#endif