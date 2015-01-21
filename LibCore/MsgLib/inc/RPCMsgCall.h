#ifndef __msg_rpc_msg_call_h__
#define __msg_rpc_msg_call_h__ 
#include "MsgLib/inc/MsgCommon.h"  
#include "MsgLib/inc/ObjectMsgCall.h"   

namespace Msg
{
	enum ERPC_MSGCALL_TYPE
	{
		RPCTYPE_ERROR = 0 ,
		RPCTYPE_CLIENT  , 
		RPCTYPE_SERVER_PROXY  ,
		RPCTYPE_CLIENT_PROXY  ,
		RPCTYPE_SERVER  , 
		RPCTYPE_TIMEOUT , 
	};

	
	class DLL_EXPORT  RPCMsgCall : public ObjectMsgCall
	{ 
	public:
		RPCMsgCall()   
			: m_bClientRequest(FALSE)
			, m_ullTimeout(MAX_MSG_TIME_OUT)  
			, m_objProxySrcID(DEFAULT_RPC_CALLABLE_ID)
			, m_nRpcMsgCallType(RPCTYPE_ERROR)
		{  
			memset(m_szSessionName , 0 , sizeof(m_szSessionName));
			memset(m_szRemoteName , 0 , sizeof(m_szRemoteName));
		}
		~RPCMsgCall()
		{ 
		}

	public: 
		static void * operator new(size_t size , size_t unExtra)
		{
			return malloc(size + unExtra); 
		}

		void operator delete(void * p , size_t unExtra)
		{
			free(p); 
		} 

	public:   
		virtual UINT32 RefreshSize(); 
		virtual void   RefreshTargets();
// 		virtual UINT32 Serialization(char * pMsg);
// 		virtual UINT32 UnSerialization(const char * pMsg);
		virtual UINT32 GetPacketSize( void );

	public:
		//************************************
		// Method:    Copy
		// FullName:  RpcMsgCall::Copy
		// Access:    virtual public 
		// Returns:   UINT32
		// Qualifier: ����ǰ���󿽱���pMsgʹ��
		// Parameter: RpcMsgCall * pMsg
		//************************************
		UINT32 Copy(RPCMsgCall *& pMsg);

	public:
		void   SetSessionName(const char * pName){ memcpy(m_szSessionName , pName , strlen(pName) + 1); }
		char * GetSessionName(){ return m_szSessionName; }
		void   SetProxySrcID(Object objProxySrcID){ m_objProxySrcID = objProxySrcID; }
		Object GetProxySrcID(){ return m_objProxySrcID; }
		INT32  GetRpcMsgCallType() const { return m_nRpcMsgCallType; }
		void   SetRpcMsgCallType(INT32 val) { m_nRpcMsgCallType = val; }

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	public:    
		BOOL           m_bClientRequest;
		UINT64         m_ullTimeout;   
		char           m_szRemoteName[MAX_NAME_LENGTH];

		//5 ����Ĳ����ǲ��������紫���.
	protected:
		char           m_szSessionName[MAX_NAME_LENGTH];
		Object         m_objProxySrcID;
		INT32          m_nRpcMsgCallType;
		
	};  

}
#endif