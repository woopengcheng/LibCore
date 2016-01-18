#ifndef __msg_rpc_server_manager_h__
#define __msg_rpc_server_manager_h__ 
#include "MsgLib/inc/MsgCommon.h" 
#include "MsgLib/inc/RpcManager.h"
#include "MsgLib/inc/RpcInterface.h"

namespace Msg
{ 
	class DLL_EXPORT  RpcServerManager : public RpcManager
	{ 
	public:
		typedef tbb_queue<RPCMsgCall *>								CollectionMsgsQueT;
		typedef tbb_unordered_map<std::string , CollectionMsgsQueT>	CollectionPostMsgsT;
		typedef std_unordered_map<std::string , CollectionMsgsQueT>	CollectionDelayMsgsT;

	public:
		RpcServerManager(RpcInterface * pRpcInterface) 
			: RpcManager(pRpcInterface)
		{}
		virtual ~RpcServerManager(void);

	public:
		virtual CErrno	Init();
		virtual CErrno	Cleanup(void);
		virtual CErrno	Update(void);
		virtual void	CloseNet(const char * pName);
		virtual void	CloseNet(INT32 nSessionID);

	public:
		virtual CErrno	PostMsg(const char * pRpcServerName , RPCMsgCall * pMsg);
		virtual CErrno	PostDelayMsg(const char * pRpcServerName , RPCMsgCall * pMsg);

	public:  
		virtual CErrno	HandleMsg(Net::ISession * pSession , RPCMsgCall * pMsg);   

	public: 
		CErrno			UpdateCalls(void); 
		CErrno			UpdatePostMsgs(void); 
		CErrno			UpdateDelayMsgs(void); 
		CErrno			HandleServerMsg(Net::ISession * pSession , RPCMsgCall * pMsg);
		CErrno			HandleClientMsg(Net::ISession * pSession , RPCMsgCall * pMsg);

	public:  
		virtual Net::NetHandlerTransitPtr OnCreateNetHandler( const char * pName , const char * pAddress , UINT16 usPort , Net::NetSocket socket = 0 , void * context = NULL);

	protected:
		void			InsertPostMsg(const std::string & strRpcServerName , RPCMsgCall * pMsg);
		void			InsertDelayMsg(const std::string strRpcServerName , RPCMsgCall * pMsg);

	protected:
		CollectionPostMsgsT		m_mapPostMsgs;  //5 ����ͬһ�������µĲ�ͨ�̵߳ĵ���Ϣת��
		CollectionDelayMsgsT	m_mapDelayMsgs;	//5	�����߼������еĿ�����Ҫ�ӳٴ������Ϣ��.ʵ��ͬPostMsg.Ϊ������,���ﵥ��дһ��.
	};  
	 
}


#endif