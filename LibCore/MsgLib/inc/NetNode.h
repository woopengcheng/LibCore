#ifndef __msg_net_node_h__
#define __msg_net_node_h__
#include "MsgLib/inc/MsgCommon.h"
#include "NetLib/inc/ISession.h"
#include "CUtil/inc/RemoteNodeDefine.h"

namespace Msg
{
	class RpcInterface;

	class DLL_EXPORT NetNode
	{
	public:
		typedef std::map<std::string , RpcInterface *> CollectionMyselfNodesT;
		typedef std::map<std::string , Net::ISession *> CollectionRemoteNodesT;   //5 一个名字对于一个远程发送的session

	public:
		NetNode();
		~NetNode();

	public:
		static NetNode & GetInstance();

	public:
		void		InsertMyselfNodes(const std::string & strName , RpcInterface * pInterface);
		void		InsertRemoteNodes(const std::string & strName , Net::ISession * pSession);
		BOOL		IsInMyselfNodes(const std::string & strName);
		RpcInterface  * GetMyselfNode(const std::string & strName);
		Net::ISession *	GetRemoteNode(const std::string & strName);

	private:
		CollectionMyselfNodesT		m_mapMyselfNodes;
		CollectionRemoteNodesT		m_mapRemoteNodes;
	};
}

#endif
