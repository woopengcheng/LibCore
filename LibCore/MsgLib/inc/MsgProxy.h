// #ifndef __msg_msg_proxy_h__
// #define __msg_msg_proxy_h__ 
// #include "MsgCommon.h"
// #include "GenMsgHelper.h"
// #include "ObjectMsgCall.h"
// 
// namespace Msg
//  {   
//   
//   #define USE_MSG_PROXY
//   #ifdef USE_MSG_PROXY
//   	
//   	static BOOL  rpc_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Chunk p7 , Object objTarget , Object objSrc , UINT16 usPriority = 0)
//   	{ 
//   		vector vecTargets;
//   		vecTargets.push_back(objTarget);
//   
//   		return rpc_Test(p1 , p2 , p3 , p4 , p5 , p6 , p7 , vecTargets , objSrc , usPriority);
//   	}
//   
//   	
//   	static BOOL  rpc_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Chunk p7 , std::vector<Object> vecTargets , Object objSrc , UINT16 usPriority = 0)
//   	{
//   		if (vecTargets.size() == 0)
//   		{
//   			return FALSE;
//   		}
//   		else
//   		{ 
//   			ObjectMsgCall * pMsg = new(sizeof(Object)*vecTargets.size())ObjectMsgCall;  
//   
//   			GenMsgHelper::GenMsgCall(*pMsg , 0 , sz_rpc_Test , vecTargets , objSrc , usPriority);
//   			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);
//   			    
//   			InnerMsg::GetInstance().SendMsg(pMsg);
//   		}
//   
//   		return TRUE;
//   	}
//   #endif 
//   
//   #define DECLARE_MSG_WORLD_OBJECT public:\
//   	void  local_run_Object_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<MSG_ID> vecTargets , MSG_ID objSrc);\
//   
//   	
//   	static BOOL  rpc_WorldTest(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Chunk p7 , std::vector<Object> vecTargets , Object objSrc , UINT16 usPriority = 0)
//   	{
//   		if (vecTargets.size() == 0)
//   		{
//   			return FALSE;
//   		}
//   		else
//   		{ 
//   			ObjectMsgCall * pMsg = new(sizeof(Object)*vecTargets.size())ObjectMsgCall;  
//   
//   			GenMsgHelper::GenMsgCall(*pMsg , 0 , sz_rpc_WorldTest , vecTargets , objSrc , usPriority);
//   			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7);
//   
//   			InnerMsg::GetInstance().SendMsg(pMsg);
//   		}
//   
//   		return TRUE;
//   	}
//   
//   	
//   	static void  local_run_Test(char p1 , INT16 p2, UINT16 p3 , INT32 p4 , UINT32 p5 , const char * p6 , Msg::Chunk p7 , std::vector<Object> vecTargets , Object objSrc)
//   	{
//   		printf("Local_run_test."); 
//   	} 
// 
// }
// #endif