#ifndef __net_net_thread_h__
#define __net_net_thread_h__  
#include "NetLib/inc/NetCommon.h"
#include "NetLib/inc/NetHandlerListener.h"
#include "CUtil/inc/Chunk.h"
#include "ThreadPool/inc/ThreadTask.h"
#include "json/json.h"

namespace Net
{
	class IRpcListener;

	class DLL_EXPORT  NetThread : public ThreadPool::ThreadNormalTask
	{
	public:
		typedef tbb::concurrent_queue<INT32> CollectAcceptSessionT;

	public:
		NetThread(void);
		virtual ~NetThread(void);
		static NetThread & GetInstance();

	public:
		virtual CErrno		Init(Json::Value & conf);
		virtual CErrno		Cleanup(void);
		virtual CErrno		Update(void);
		virtual CErrno		StartupServer(const std::string & strNetNodeName, const std::string & strType, const std::string & strAddress, const std::string & strPort);
		virtual CErrno		StartupClient(const Json::Value & clients);

	public:
		char			*	GetServerName() { return m_szServerName; }
		char			*	GetNetNodeName(){ return m_szNetNodeName; }
		char			*	GetServerType() { return m_szRpcType; }
		UINT16				GetServerPort() { return m_usServerPort; }
		INetReactor		*	GetNetReactor() { return m_pNetReactor; }
		INetHandlerPtr		CreateClientHandler(const char * pName, const char * pAddress, UINT16 usPort , Net::NetSocket socket = 0, void * context = NULL);
		INT32				SendMsg(INT32 nSessionID, const char * pBuffer, UINT32 unLength);
		void				AcceptSession(INT32 nSessionID);
		CErrno				FetchSession(CollectAcceptSessionT & queSessions);

	private:
		CErrno				FetchMsgs(INT32 nSessionID, CollectMsgChunksT & queMsgs);
		CErrno				DeliverMsg();

	protected:
		char				m_szServerName[MAX_NAME_LENGTH];
		char				m_szNetNodeName[MAX_NAME_LENGTH];
		char				m_szRpcType[MAX_NAME_LENGTH];
		UINT16				m_usServerPort;
		INetReactor		*	m_pNetReactor;         //5 没有访问机会.不会加锁
		CollectAcceptSessionT m_queAceeptSessions;
	};

}


#endif