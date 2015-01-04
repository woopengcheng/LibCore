#ifndef __msg_rpc_h__
#define __msg_rpc_h__ 
#include "MsgCommon.h" 
#include "TimeCount.h" 
#include "ICallableObject.h"
#include "RPCMsgCall.h"
#include "GenMsgHelper.h"

#define RPCReturnNULL return NULL;
#define RPCReturn(p1) return Return(p1);
#define RPC_MSG_SEND_TYPE_DELIVER "Deliver"
#define RPC_MSG_SEND_TYPE_RETURN  "Return"

#define	CheckParams_0(PARAM) GenMsgHelper::CheckParams(*PARAM) 
#define	CheckParams_1(PARAM , p1) GenMsgHelper::CheckParams(*PARAM , p1 ) 
#define	CheckParams_2(PARAM , p1 , p2) GenMsgHelper::CheckParams(*PARAM , p1 , p2 ) 
#define	CheckParams_3(PARAM , p1 , p2 , p3) GenMsgHelper::CheckParams(*PARAM , p1 , p2 , p3 ) 
#define	CheckParams_4(PARAM , p1 , p2 , p3, p4) GenMsgHelper::CheckParams(*PARAM , p1 , p2 , p3, p4 ) 
#define	CheckParams_5(PARAM , p1 , p2 , p3, p4 , p5) GenMsgHelper::CheckParams(*PARAM , p1 , p2 , p3, p4 , p5 ) 
#define	CheckParams_6(PARAM , p1 , p2 , p3, p4 , p5 , p6) GenMsgHelper::CheckParams(*PARAM , p1 , p2 , p3, p4 , p5 , p6 ) 
#define	CheckParams_7(PARAM , p1 , p2 , p3, p4 , p5 , p6 , p7) GenMsgHelper::CheckParams(*PARAM , p1 , p2 , p3, p4 , p5 , p6 , p7 )  
#define	CheckParams_8(PARAM , p1 , p2 , p3, p4 , p5 , p6 , p7 , p8) GenMsgHelper::CheckParams(*PARAM , p1 , p2 , p3, p4 , p5 , p6 , p7 , p8) 

#define RPC_GEN_MSG	if (m_pRpcMsgCall->GetRpcMsgCallType() == RPCTYPE_TIMEOUT ||\
		m_pRpcMsgCall->GetRpcMsgCallType() == RPCTYPE_ERROR ||\
		m_pRpcMsgCall->GetRpcMsgCallType() == RPCTYPE_CLIENT)\
		{\
		return NULL;\
		}\
		\
		RPCMsgCall * pMsg = NULL; \
		m_pRpcMsgCall->Copy(pMsg);

#define RPC_GEN_RETURN_MSG RPC_GEN_MSG pMsg->m_bClientRequest = TRUE;
#define RPC_GEN_PROXY_MSG RPC_GEN_MSG pMsg->m_bClientRequest = FALSE;

#define GET_PARAMETER Parameters * pParameter = NULL;\
	if (bDeliver)\
		{\
		pParameter = GetDeliverParams(pFunName);\
		}\
		else\
		{\
		pParameter = GetReturnParams(pFunName);\
		} \
		Assert_Re0(pParameter) 

namespace Timer
{
	class TimeCount;
}

namespace Msg
{
	
	class RpcManager;  
	class RPCMsgCall;

	
	class DLL_EXPORT  Rpc : public IMsgCallableObject
	{
	public:
		Rpc(RpcManager * pRpcManager , UINT64 unTimeout = 0 , Object nID = DEFAULT_RPC_CALLABLE_ID , RPCMsgCall *  pMsg = NULL)
			: IMsgCallableObject(nID)  
			, m_pRpcMsgCall(pMsg)
			, m_pRpcManager(pRpcManager) 
		{ 
			m_objTimeout.Start(unTimeout * 1000); 
		} 
		~Rpc( void ){}

	public:
		typedef std::vector<ObjectMsgCall*> VecObjectMsgCallT;
		typedef std_unordered_map<std::string , Parameters> MapCollectParametersT;

	public:
		virtual BOOL  OnTimeout( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall );
		virtual BOOL  OnServer( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall ); 
		virtual BOOL  OnProxy( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall ); 
		virtual BOOL  OnClient( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall );  

	public:
		BOOL  IsTimeout();
		void  SetTimeout(UINT64 unTimeout); 
		INT32 ProxySendBack();  
		
	public: 
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName)
		{
			GET_PARAMETER;
			return CheckParams_0(pParameter);
		}

		template<typename P1> 
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 )
		{ 
			GET_PARAMETER;
			return CheckParams_1(pParameter , p1); 
		}

		template<typename P1 , typename P2 >
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2)
		{ 
			GET_PARAMETER;
			return CheckParams_2(pParameter , p1 , p2 );	
		}

		template<typename P1 , typename P2 , typename P3>	
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2 , P3 &p3 ) 
		{ 
			GET_PARAMETER;
			return CheckParams_3(pParameter , p1 , p2 , p3); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 > 
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 )
		{ 
			GET_PARAMETER;
			return CheckParams_4(pParameter , p1 , p2 , p3, p4 );	
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 >
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 ) 
		{ 
			GET_PARAMETER;
			return CheckParams_5(pParameter , p1 , p2 , p3, p4 , p5 );
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6> 
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 )
		{
			GET_PARAMETER;
			return CheckParams_6(pParameter , p1 , p2 , p3, p4 , p5 , p6);
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>	
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7) 
		{ 
			GET_PARAMETER;
			return CheckParams_7(pParameter , p1 , p2 , p3, p4 , p5 , p6 , p7);
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		BOOL CheckRpcParams(BOOL bDeliver , const char * pFunName , P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 & p8)
		{ 
			GET_PARAMETER;
			return CheckParams_8(pParameter , p1 , p2 , p3, p4 , p5 , p6 , p7 , p8); 
		}
		 
	public:   
		INT32 ProxySendMsg(const char * pName) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		} 

		template<typename P1 >
		INT32 ProxySendMsg(const char * pName, P1 &p1) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 >
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG; 

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 ); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7) 
		{
//			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7 , p8) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8); 
			 
			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

	public:  
		 
		RPCMsgCall * Return()
		{ 
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(FALSE , m_pRpcMsgCall->m_szMsgMethod) && "RPC返回参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams);

			return pMsg;
		}

		template<class P1>
		RPCMsgCall * Return(P1 p1)
		{ 
//			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(FALSE , m_pRpcMsgCall->m_szMsgMethod , p1) && "RPC返回参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1);

			return pMsg;
		} 

		template<typename P1 , typename P2 >
		RPCMsgCall * Return(P1 &p1 , P2 &p2) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(FALSE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2) && "RPC返回参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2);

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 );

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 );

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5);

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5 , p6); 

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5 , p6 , p7);

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8) 
		{ 
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7 , p8) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5 , p6 , p7 , p8);

			return pMsg;	
		}
	public:
//#include "rpc.hrpc"

	public: 
		void         InsertDeliverParams(std::string strFunName , Parameters & objParam);
		void         InsertReturnParams(std::string strFunName , Parameters & objParam);
		RPCMsgCall * GetRpcMsgCall() { return  m_pRpcMsgCall; } 
		void		 SetRpcMsgCall(RPCMsgCall * pMsg){ Assert(pMsg); m_pRpcMsgCall = pMsg; }  

	private: 
		BOOL         CallObjectFunc( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall); 
		Parameters * GetDeliverParams(std::string strFunName);
		Parameters * GetReturnParams(std::string strFunName);

	private: 
		RPCMsgCall			 *  m_pRpcMsgCall;
		RpcManager			 *  m_pRpcManager;
		Timer::TimeCount        m_objTimeout;
		MapCollectParametersT   m_mapReturnParams;
		MapCollectParametersT   m_mapDeliverParams;
	}; 
	 
}


#endif