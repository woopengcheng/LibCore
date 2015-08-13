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

	enum EMSG_SYNC_TYPE
	{
		SYNC_TYPE_SYNC = 0,
		SYNC_TYPE_NONSYNC = 1,
	};

	enum EMSG_SYNC_RESULT
	{
		SYNC_RESULT_START_RETURN = -1,
		SYNC_RESULT_SUCCESS = 0,
		SYNC_RESULT_FALSE = 1,
	};

	enum ERPCRETURN_TYPE
	{
		RETURN_TYPE_DONE = 1, 
		RETURN_TYPE_DELAY = 2, //5 �ӳٷ���,�ȴ�ĳЩ�¼�������ʱ���ٵ���.
		RETURN_TYPE_IGNORE = 4	, //5 ���������,ͬ���.
	};

	class DLL_EXPORT  RPCMsgCall : public ObjectMsgCall
	{ 
		typedef std::set<Msg::Object> CollectionTargetsT;

	public:
		RPCMsgCall(/*const Msg::Parameters & objParams*/)   
//			: ObjectMsgCall(objParams)
			: m_bClientRequest(FALSE)
			, m_ullTimeout(MAX_MSG_TIME_OUT)  
			, m_objProxySrcID(DEFAULT_RPC_CALLABLE_ID)
			, m_nRpcMsgCallType(RPCTYPE_ERROR)
			, m_objSyncType(SYNC_TYPE_NONSYNC)
			, m_objSyncResult(SYNC_RESULT_START_RETURN)
			, m_nReturnType(RETURN_TYPE_DONE)  //5 Ĭ�����.
		{  
			memset(m_szSessionName , 0 , sizeof(m_szSessionName));
			memset(m_szRemoteName , 0 , sizeof(m_szRemoteName));
			RefreshTargets();
		}
		~RPCMsgCall()
		{ 
			m_setDelayTargets.clear();
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
		UINT32 CopyExcludeNetDatas(RPCMsgCall *& pMsg);
		UINT32 CopyExcludeParams(RPCMsgCall *& pMsg);
		UINT32 CopyExcludeParamsAndTargets(RPCMsgCall *& pMsg ,const std::vector<Msg::Object> & vecTargets , Msg::Object objSrc);


	public:
		void   SetSessionName(const char * pName){ memcpy(m_szSessionName , pName , strlen(pName) + 1); }
		char * GetSessionName(){ return m_szSessionName; }
		void   SetProxySrcID(Object objProxySrcID){ m_objProxySrcID = objProxySrcID; }
		Object GetProxySrcID(){ return m_objProxySrcID; }
		INT32  GetRpcMsgCallType() const { return m_nRpcMsgCallType; }
		void   SetRpcMsgCallType(INT32 val) { m_nRpcMsgCallType = val; }
		void   SetSyncType(EMSG_SYNC_TYPE val) { m_objSyncType = val; }
		EMSG_SYNC_TYPE GetSyncType( void ){ return m_objSyncType; }
		void   SetSyncResult(EMSG_SYNC_RESULT val) { m_objSyncResult = val; }
		EMSG_SYNC_RESULT GetSyncResult( void ){ return m_objSyncResult; }
		INT32 GetReturnType() const { return m_nReturnType; }
		void AddReturnType(Msg::ERPCRETURN_TYPE val) { m_nReturnType = m_nReturnType | val; }
		void ResetReturnType() { m_nReturnType = RETURN_TYPE_DONE; }
		void AddDelayTarget(Msg::Object obj);
		void ReplaceDelayTarget();

	public: 
		virtual CUtil::CStream & marshal(CUtil::CStream & cs);
		virtual CUtil::CStream & unMarshal(CUtil::CStream & cs);
	public:    
		BOOL           m_bClientRequest;
		UINT64         m_ullTimeout;   
		char           m_szRemoteName[MAX_NAME_LENGTH];

		//5 ����Ĳ����ǲ��������紫���.
	protected:
		char				m_szSessionName[MAX_NAME_LENGTH];
		Object				m_objProxySrcID;
		INT32				m_nRpcMsgCallType;
		INT32				m_nReturnType;
		EMSG_SYNC_TYPE		m_objSyncType;
		EMSG_SYNC_RESULT	m_objSyncResult;
		CollectionTargetsT	m_setDelayTargets;
	};  

}
#endif