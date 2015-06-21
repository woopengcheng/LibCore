#ifndef __msg_rpc_h__
#define __msg_rpc_h__ 
#include "MsgLib/inc/MsgCommon.h" 
#include "TimerLib/inc/TimeCount.h" 
#include "MsgLib/inc/ICallableObject.h"
#include "MsgLib/inc/RPCMsgCall.h"
#include "MsgLib/inc/GenMsgHelper.h"
#include "MsgLib/inc/RpcCheckParams.h"
#include "NetLib/inc/ISession.h"

#define RPCReturnNULL return NULL;
#define RPCReturn0() return Return();
#define RPCReturn1(p1) return Return(p1);
#define RPCReturn2(p1 , p2) return Return(p1 , p2);
#define RPCReturn3(p1 , p2 , p3) return Return(p1 , p2 , p3);
#define RPCReturn4(p1 , p2 , p3 , p4) return Return(p1 , p2 , p3 , p4 );
#define RPCReturn5(p1 , p2 , p3 , p4 , p5) return Return(p1 , p2 , p3 , p4 , p5);
#define RPCReturn6(p1 , p2 , p3 , p4 , p5 , p6) return Return(p1 , p2 , p3 , p4 , p5 , p6 );
#define RPCReturn7(p1 , p2 , p3 , p4 , p5 , p6 , p7) return Return(p1 , p2 , p3 , p4 , p5 , p6 , p7);
#define RPCReturn8(p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8) return Return(p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8);


#define RPC_MSG_SEND_TYPE_DELIVER "Deliver"
#define RPC_MSG_SEND_TYPE_RETURN  "Return"

#define RPC_GEN_MSG	if (m_pRpcMsgCall->GetRpcMsgCallType() == RPCTYPE_TIMEOUT ||\
		m_pRpcMsgCall->GetRpcMsgCallType() == RPCTYPE_ERROR ||\
		m_pRpcMsgCall->GetRpcMsgCallType() == RPCTYPE_CLIENT)\
		{\
		return NULL;\
		}\
		\
		RPCMsgCall * pMsg = NULL; \
		m_pRpcMsgCall->CopyExcludeParams(pMsg);

#define RPC_GEN_RETURN_MSG RPC_GEN_MSG pMsg->m_bClientRequest = TRUE;
#define RPC_GEN_PROXY_MSG RPC_GEN_MSG pMsg->m_bClientRequest = FALSE;


namespace Timer
{
	class TimeCount;
}

namespace Msg
{
	
	class RpcManager;  
	class RPCMsgCall;

	
	class DLL_EXPORT  Rpc : public ICallableObject
	{
	public:
		Rpc(RpcManager * pRpcManager , UINT64 unTimeout = 0 , Object nID = DEFAULT_RPC_CALLABLE_ID , RPCMsgCall *  pMsg = NULL , Net::ISession * pSession = NULL)
			: ICallableObject(nID)  
			, m_pRpcMsgCall(pMsg)
			, m_pRpcManager(pRpcManager) 
			, m_pSession(pSession) 
		{ 
			m_objTimeout.Start(unTimeout * 1000); 
		} 
		~Rpc( void ){}

	public:
		typedef std::vector<ObjectMsgCall*> VecObjectMsgCallT;

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
		INT32 ProxySendMsg(const char * pName) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && Msg::g_pRpcCheckParams && Msg::g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		} 

		template<typename P1 >
		INT32 ProxySendMsg(const char * pName, P1 &p1) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 >
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG; 

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 ); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7) 
		{
 			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7); 

			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		INT32 ProxySendMsg(const char * pName, P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8) 
		{
			Assert_ReF1("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7 , p8) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_PROXY_MSG;

			GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 , p5 , p6 , p7 , p8); 
			 
			return  m_pRpcManager->SendMsg(pName , pMsg); 
		}

	public:   
		RPCMsgCall * Return()
		{ 
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(FALSE , m_pRpcMsgCall->m_szMsgMethod) && "RPC返回参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams);

			return pMsg;
		}

		template<class P1>
		RPCMsgCall * Return(P1 p1)
		{ 
 			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(FALSE , m_pRpcMsgCall->m_szMsgMethod , p1) && "RPC返回参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1);

			return pMsg;
		} 

		template<typename P1 , typename P2 >
		RPCMsgCall * Return(P1 &p1 , P2 &p2) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(FALSE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2) && "RPC返回参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2);

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 ) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 );

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 , p4 );

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5);

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5 , p6); 

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7) 
		{
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5 , p6 , p7);

			return pMsg;
		}

		template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
		RPCMsgCall * Return(P1 &p1 , P2 &p2 , P3 &p3 , P4 &p4 , P5 &p5 , P6 &p6 , P7 &p7 , P8 &p8) 
		{ 
			Assert_Re0("msgPacket maybe NULL or Params is not match" && m_pRpcMsgCall && m_pRpcManager && g_pRpcCheckParams && g_pRpcCheckParams->CheckRpcParams(TRUE , m_pRpcMsgCall->m_szMsgMethod , p1 , p2 , p3 , p4 , p5 , p6, p7 , p8) && "RPC发送参数类型或者数量不对.");

			RPC_GEN_RETURN_MSG;

			Msg::GenMsgHelper::GenMsgParams(pMsg->m_objParams , p1 , p2 , p3 ,p4 , p5 , p6 , p7 , p8);

			return pMsg;	
		} 

	public: 
		RPCMsgCall * GetRpcMsgCall() { return  m_pRpcMsgCall; } 
		void		 SetRpcMsgCall(RPCMsgCall * pMsg){ Assert(pMsg); m_pRpcMsgCall = pMsg; }   
		Net::ISession * GetSession() { return  m_pSession; } 
		void		 SetSession(Net::ISession * pSession){ Assert(pSession); m_pSession = pSession; }   

	private: 
		BOOL         CallObjectFunc( RPCMsgCall * pMsg , VecObjectMsgCallT & vecObjectMsgCall); 

	private: 
		RPCMsgCall			 *  m_pRpcMsgCall;
		RpcManager			 *  m_pRpcManager;
		Timer::TimeCount        m_objTimeout;
		Net::ISession        *  m_pSession; 
	}; 
	 
}


#endif