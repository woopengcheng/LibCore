#include "Msglib/inc/NetNode.h"
#include "MsgLib/inc/RpcManager.h"

namespace Msg
{
	NetNode::NetNode()
	{

	}

	NetNode::~NetNode()
	{
		m_mapMyselfNodes.clear();
	}

	NetNode & NetNode::GetInstance()
	{
		static NetNode sInstance;
		return sInstance;
	}

	void NetNode::InsertRemoteNodes(const std::string & strName , Net::ISession * pSession)
	{
		CollectionRemoteNodesT::iterator iter = m_mapRemoteNodes.find(strName);
		if (iter == m_mapRemoteNodes.end())
		{
			m_mapRemoteNodes.insert(std::make_pair(strName , pSession));
		}
	}

	void NetNode::InsertMyselfNodes(const std::string & strName , RpcInterface * pInterface)
	{
		if (!IsInMyselfNodes(strName))
		{
			m_mapMyselfNodes.insert(std::make_pair(strName , pInterface));
		}
	}

	BOOL NetNode::IsInMyselfNodes(const std::string & strName)
	{
		CollectionMyselfNodesT::iterator iter = m_mapMyselfNodes.find(strName);
		if (iter == m_mapMyselfNodes.end())
		{
			return FALSE;
		}

		return TRUE;
	}

	RpcInterface * NetNode::GetMyselfNode(const std::string & strName)
	{
		CollectionMyselfNodesT::iterator iter = m_mapMyselfNodes.find(strName);
		if (iter != m_mapMyselfNodes.end())
		{
			return iter->second;
		}

		return NULL; 
	}

	Net::ISession * NetNode::GetRemoteNode(const std::string & strName)
	{
		CollectionRemoteNodesT::iterator iter = m_mapRemoteNodes.find(strName);
		if (iter != m_mapRemoteNodes.end())
		{
			return iter->second;
		}
	}

}