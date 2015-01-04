#ifndef __msg_msg_proxy_h__
#define __msg_msg_proxy_h__ 
#include "MsgCommon.h"
#include "GenMsgHelper.h"
#include "ObjectMsgCall.h"
#include "Object.h"
#include "MsgNameDefine.h"

namespace Msg
{    
	static BOOL local_call_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Chunk p7 , std::vector<Msg::Object> vecTargets ,Msg::Object objSrc , UINT16 usPriority = 0)
	{
		if (vecTargets.size() == 0)
		{
			return FALSE;
		}
		else
		{ 
			ObjectMsgCall * pMsg = new(sizeof(Object)*vecTargets.size())ObjectMsgCall;  

			GenMsgHelper::GenMsgCall(*pMsg , Msg::g_szLocal_Test , vecTargets , objSrc , usPriority);
			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);

			InnerMsg::GetInstance().SendMsg(pMsg);
		}

		return TRUE;
	} 

  	static BOOL local_call_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Chunk p7 , Msg::Object objTarget , Msg::Object objSrc , UINT16 usPriority = 0)
  	{ 
  		std::vector<Msg::Object> vecTargets;
  		vecTargets.push_back(objTarget);
  
  		return local_call_Test(p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority);
  	} 
  
  #define DECLARE_MSG_WORLD_OBJECT public:\
  	Msg::ObjectMsgCall * local_run_Object_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<MSG_ID> vecTargets , MSG_ID objSrc);\
  
  	
  	static BOOL local_call_WorldTest(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Chunk p7 , std::vector<Object> vecTargets , Object objSrc , UINT16 usPriority = 0)
  	{
  		if (vecTargets.size() == 0)
  		{
  			return FALSE;
  		}
  		else
  		{ 
  			ObjectMsgCall * pMsg = new(sizeof(Object)*vecTargets.size())ObjectMsgCall;  
  
  			GenMsgHelper::GenMsgCall(*pMsg , Msg::g_szLocal_TestObject , vecTargets , objSrc , usPriority);
  			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);
  
  			InnerMsg::GetInstance().SendMsg(pMsg);
  		}
  
  		return TRUE;
  	}
  
  	
  	static Msg::ObjectMsgCall *  local_run_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<Object> vecTargets , Object objSrc)
  	{
  		printf("Local_run_test."); 

		return NULL;
  	} 

}
#endif