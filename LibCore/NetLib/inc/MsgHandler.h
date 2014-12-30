#ifndef __net_msg_handler_h__
#define __net_msg_handler_h__
#include "NetCommon.h"  
#include "ThreadLock.h"
#include "ThreadTask.h"
#include "MsgProcess.h"

namespace Net
{   
	class MsgWrapper;
	class NetBase;
	
	class MsgHandlerImp  : public ThreadPool::ThreadNormalTask
	{
	public:
		typedef tbb::concurrent_queue<MsgWrapper *> QueueMsgWrappersT;

	public:
		MsgHandlerImp()
			: ThreadNormalTask(DEFAULT_THREAD_PRIORITY , "MsgHandlerImp")
			, m_bAutoManagerMemory(FALSE)
			, m_unClientIndex(0)  
			, m_pNet(NULL)
			, m_pMsgProcess(NULL)
		{}
		~MsgHandlerImp(){}
		 
	public:
		virtual INT32   Init(MsgProcess * pMsgProcess , BOOL bAutoManagerMemeory = FALSE);
		virtual INT32   Cleanup();
		virtual INT32   ConnectServer(char * pAddress , UINT16 usPort); 
		virtual INT32   IsConnected();

	public:
		virtual INT32   Update();
		virtual INT32   InflowRecvBuffer(void);
		virtual INT32   PorcessMsg();
		virtual INT32   OutflowSendBuffer(); 
		virtual INT32   SendMsg( UINT32 unMsgID, const char* pBuffer, UINT32 unLength);
	
	public:
		BOOL        GetAutoManagerMemory(){ return m_bAutoManagerMemory;}
		void        SetAutoManagerMemory(BOOL bAutoManagerMemory){ m_bAutoManagerMemory = bAutoManagerMemory;}
		UINT32      GetClientIndex(){ return m_unClientIndex; }
		void        SetClientIndex(UINT32 unClientIndex){ m_unClientIndex = unClientIndex;}
		NetBase *   GetNet(){ return m_pNet; }
		void        SetNet(NetBase * pNet){ m_pNet = pNet; }
		MsgProcess *GetMsgProcess(){ return m_pMsgProcess; }
		void        SetMsgProcess(MsgProcess * pMsgProcess){ m_pMsgProcess = pMsgProcess; }

	private:
		INT32       FetchMsgFromRecvBuffer(MsgWrapper*& pMsg); 

	private:
		BOOL         m_bAutoManagerMemory;
		UINT32       m_unClientIndex;
		NetBase    * m_pNet;
		MsgProcess * m_pMsgProcess;

	private:
		QueueMsgWrappersT m_queueRecvMsgs;
		QueueMsgWrappersT m_queueSendMsgs;
	};

	class MsgHandler 
	{
	public:
 		typedef tbb_hash_map<UINT32 /*ClentIndex*/, MsgHandlerImp *> MapMsgHandlerImpT;
 
	public:
		MsgHandler();
		virtual ~MsgHandler();

	public:
		virtual BOOL             Init();
		virtual BOOL             Cleanup();  
		virtual UINT32           AddClient(MsgProcess * pMsgProcess , char* pAddress, UINT16 usPort , BOOL bAutoManagerMemeory = FALSE );
		virtual INT32            SendMsg( UINT32 unClientIndex , UINT32 unMsgID, const char* pBuffer, UINT32 unLength);
		virtual BOOL             IsConnected(UINT32 unClientIndex);

	private:
		INT32              GetClientIndex(UINT32 unTimes = 0);
		MsgHandlerImp *    GetMsgHandlerImp(UINT32 unClientIndex);

	private: 
		ThreadPool::ThreadSpinRWMutex  m_objThreadLock;
		UINT32              m_unClientCount; 

		MapMsgHandlerImpT   m_mapMsgHandlerImp;
	};

}; 

#endif