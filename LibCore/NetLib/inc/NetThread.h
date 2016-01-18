#ifndef __net_net_thread_h__
#define __net_net_thread_h__  
#include "NetLib/inc/NetCommon.h"
#include "NetLib/inc/Ping.h"
#include "NetLib/inc/NetHandlerListener.h"
#include "ThreadPool/inc/ThreadTask.h"
#include "CUtil/inc/Chunk.h"
#include "CUtil/inc/CUtil.h"
#include "json/json.h"

namespace Net
{
	typedef std::pair<std::string, INT32>					PeerKey;
	struct PeerKeyHashFunc
	{
		size_t operator()(const PeerKey & key) const
		{
			return CUtil::BKDRHash(key.first.c_str()) + key.second;
		}
	};
	struct PeerKeyCmpFunc //比较函数 ==  
	{
		bool operator()(const PeerKey & key1, const PeerKey & key2) const
		{
			if (key1.first == key2.first && key2.second == key1.second)
			{
				return true;
			}
			return false;
		}
	};

	class DLL_EXPORT  NetThread : public ThreadPool::ThreadSustainTask
	{
	public:
		typedef tbb::concurrent_queue<SPeerInfo>				QueAcceptSessionT;
		typedef tbb::concurrent_queue<PeerKey>					QueCreateClientsT;
		typedef std::unordered_map<PeerKey, SPeerInfo , PeerKeyHashFunc , PeerKeyCmpFunc>			MapPeerSessionT;

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
		char			*	GetServerAddress() { return m_szAddress; }
		char			*	GetNetNodeName(){ return m_szNetNodeName; }
		char			*	GetServerType() { return m_szRpcType; }
		UINT16				GetServerPort() { return m_usServerPort; }
		INetReactor		*	GetNetReactor() { return m_pNetReactor; }

	public:
		CErrno				UpdatePing(void);
		INetHandlerPtr		CreateClientHandler(const char * pName, const char * pAddress, UINT16 usPort , Net::NetSocket socket = 0, void * context = NULL);
		INT32				SendMsg(INT32 nSessionID, const char * pBuffer, UINT32 unLength);
		void				AcceptSession(ISession * pSession);
		CErrno				FetchSession(std::vector<SPeerInfo> & vecSessions);
		CErrno				FetchMsgs(INT32 nSessionID , CollectMsgChunksVec & queMsgs);
		CErrno				AddPeerSession(PeerKey objKey, SPeerInfo & objPeerInfo);
		CErrno				InsertClientsQueue(const char * pAddress, UINT16 usPort);

	private:
		CErrno				DeliverMsg();
		CErrno				FetchClientsQueue();

	protected:
		char				m_szAddress[MAX_ADDRESS_LENGTH];
		char				m_szNetNodeName[MAX_NAME_LENGTH];
		char				m_szRpcType[MAX_NAME_LENGTH];
		UINT16				m_usServerPort;
		INetReactor		*	m_pNetReactor;         //5 没有访问机会.不会加锁
		MapPeerSessionT		m_mapPeerSessions;
		QueCreateClientsT	m_queCreateClients;
		QueAcceptSessionT	m_queAceeptSessions;
	};

}


#endif