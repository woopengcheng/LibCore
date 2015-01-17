#ifndef __msg_msg_proxy_h__
#define __msg_msg_proxy_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/GenMsgHelper.h"
#include "MsgLib/inc/ObjectMsgCall.h"
#include "MsgLib/inc/Object.h"
#include "MsgLib/inc/MsgHelper.h"
#include "MsgNameDefine.h"
#include "MsgInstance.h"

namespace Client
{    
	static BOOL local_call_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , std::vector<Msg::Object> vecTargets ,Msg::Object objSrc , UINT16 usPriority = 0)
	{ 
		GEN_MSG_CALL(Client::g_szLocal_Test , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority); 
	} 

  	static BOOL local_call_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , Msg::Object objTarget , Msg::Object objSrc , UINT16 usPriority = 0)
  	{ 
  		std::vector<Msg::Object> vecTargets;
  		vecTargets.push_back(objTarget);
  
  		return local_call_Test(p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority);
  	} 
    
  	static BOOL local_call_WorldTest(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , LibCore::Chunk p7 , std::vector<Msg::Object> vecTargets , Msg::Object objSrc , UINT16 usPriority = 0)
	{
		GEN_MSG_CALL(Client::g_szLocal_TestObject , p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority);  
  	}
   

}
#endif