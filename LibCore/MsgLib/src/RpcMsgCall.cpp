#include "MsgLib/inc/RPCMsgCall.h"
#include "Marshal/inc/CStream.h"

namespace Msg
{
	
// 	UINT32 RPCMsgCall::UnSerialization(const char * pMsg )
// 	{  
// //		RefreshTargets();
// 
// 		UINT32 unSize = ObjectMsgCall::UnSerialization(pMsg);
// 		m_ullTimeout = *(UINT32*)(pMsg + unSize);  
// 		unSize += sizeof(m_ullTimeout);
// 		m_bClientRequest = *(BOOL*)(pMsg + unSize);   
// 		unSize += sizeof(m_bClientRequest); 
// 		memcpy(m_szRemoteName , (char*)(pMsg + unSize) , sizeof(m_szRemoteName) );   
// 		unSize += sizeof(m_szRemoteName); 
// 
// 		RefreshSize();
// 		return unSize;
// 	}
// 
// 
// 	UINT32 RPCMsgCall::Serialization( char * pMsg )
// 	{  
// 		UINT32 unSize = ObjectMsgCall::Serialization(pMsg);
// 		memcpy(pMsg + unSize , &m_ullTimeout , sizeof(m_ullTimeout));
// 		unSize += sizeof(m_ullTimeout);
// 		memcpy(pMsg + unSize, &m_bClientRequest , sizeof(m_bClientRequest));
// 		unSize += sizeof(m_bClientRequest); 
// 		memcpy(pMsg + unSize, m_szRemoteName , sizeof(m_szRemoteName));
// 		unSize += sizeof(m_szRemoteName);
// 
// 		return unSize;
// 	}
// 

	void RPCMsgCall::RefreshTargets()
	{  
		m_aTargets = (Object *)((const char * )this + sizeof(RPCMsgCall));  //5 �������ö�������ڴ���Ϊ�����ָ����г�ʼ��.
	}

	UINT32 RPCMsgCall::RefreshSize()
	{ 
		UINT32 unMsgLength = ObjectMsgCall::RefreshSize() + sizeof(m_ullTimeout) + sizeof(m_bClientRequest) + sizeof(m_szRemoteName); 
		return unMsgLength;
	}
	
	CErrno RPCMsgCall::Copy( RPCMsgCall *& pMsg )
	{
		pMsg = new(sizeof(Object) * GetTargetsCount())RPCMsgCall;  

		pMsg->m_objProxySrcID  = m_objProxySrcID;
		pMsg->m_ullTimeout     = m_ullTimeout;
		pMsg->m_bClientRequest = m_bClientRequest;   
		pMsg->m_ullMsgID       = m_ullMsgID; 
		pMsg->m_objSource      = m_objSource;
		pMsg->m_usPriority     = m_usPriority;
		memcpy(pMsg->m_szSessionName , m_szSessionName , sizeof(m_szSessionName)); 
		memcpy(pMsg->m_szMsgMethod , m_szMsgMethod , sizeof(m_szMsgMethod)); 
		memcpy(pMsg->m_szRemoteName , m_szRemoteName , sizeof(m_szRemoteName)); 
		m_objParams.Copy(pMsg->m_objParams);  

		UINT32 unTargetsCount = GetTargetsCount();
		pMsg->SetTargetsCount(unTargetsCount);    //5 �������������ˢ���ڴ�.
		for (UINT32 i = 0;i < unTargetsCount;++i)
		{
			pMsg->m_aTargets[i] = m_aTargets[i];
		}  
		return CErrno::Success(); 
	}

	CErrno RPCMsgCall::CopyExcludeParams(RPCMsgCall *& pMsg)
	{
		pMsg = new(sizeof(Object) * GetTargetsCount())RPCMsgCall;  

		pMsg->m_objProxySrcID  = m_objProxySrcID;
		pMsg->m_ullTimeout     = m_ullTimeout;
		pMsg->m_bClientRequest = m_bClientRequest;   
		pMsg->m_ullMsgID       = m_ullMsgID; 
		pMsg->m_objSource      = m_objSource;
		pMsg->m_usPriority     = m_usPriority;
		memcpy(pMsg->m_szSessionName , m_szSessionName , sizeof(m_szSessionName)); 
		memcpy(pMsg->m_szMsgMethod , m_szMsgMethod , sizeof(m_szMsgMethod)); 
		memcpy(pMsg->m_szRemoteName , m_szRemoteName , sizeof(m_szRemoteName));  

		UINT32 unTargetsCount = GetTargetsCount();
		pMsg->SetTargetsCount(unTargetsCount);    //5 �������������ˢ���ڴ�.
		for (UINT32 i = 0;i < unTargetsCount;++i)
		{
			pMsg->m_aTargets[i] = m_aTargets[i];
		}  
		return CErrno::Success(); 

	}

	CErrno RPCMsgCall::CopyExcludeParamsAndTargets(RPCMsgCall *& pMsg ,const std::vector<Msg::Object> & vecTargets , Msg::Object objSrc)
	{
		pMsg = new(sizeof(Object) * vecTargets.size())RPCMsgCall;  

		pMsg->m_objProxySrcID  = m_objProxySrcID;
		pMsg->m_ullTimeout     = m_ullTimeout;
		pMsg->m_bClientRequest = m_bClientRequest;   
		pMsg->m_ullMsgID       = m_ullMsgID; 
		pMsg->m_objSource      = objSrc;
		pMsg->m_usPriority     = m_usPriority;
		memcpy(pMsg->m_szSessionName , m_szSessionName , sizeof(m_szSessionName)); 
		memcpy(pMsg->m_szMsgMethod , m_szMsgMethod , sizeof(m_szMsgMethod)); 
		memcpy(pMsg->m_szRemoteName , m_szRemoteName , sizeof(m_szRemoteName));  

		UINT32 unTargetsCount = GetTargetsCount();
		pMsg->SetTargetsCount((UINT32)vecTargets.size());    //5 �������������ˢ���ڴ�.
		for (UINT32 i = 0;i < vecTargets.size();++i)
		{
			pMsg->m_aTargets[i] = vecTargets[i];
		}  
		return CErrno::Success(); 
	}

	CErrno RPCMsgCall::CopyExcludeNetDatas(RPCMsgCall *& pMsg)
	{
		pMsg->m_objProxySrcID  = m_objProxySrcID;
		pMsg->m_objSyncType    = m_objSyncType;
		pMsg->m_nReturnType  = m_nReturnType;
		pMsg->m_objSyncResult  = m_objSyncResult;
		pMsg->m_nRpcMsgCallType  = m_nRpcMsgCallType;
		memcpy(pMsg->m_szSessionName , m_szSessionName , sizeof(m_szSessionName));    

		return CErrno::Success(); 

	}

	CUtil::CStream & RPCMsgCall::marshal( CUtil::CStream & cs )
	{  
		ObjectMsgCall::marshal(cs);
		cs << m_ullTimeout << m_bClientRequest;
		cs.Pushback(m_szRemoteName , sizeof(m_szRemoteName));
		 
		return cs;
	}

	CUtil::CStream & RPCMsgCall::unMarshal( CUtil::CStream & cs )
	{ 
		ObjectMsgCall::unMarshal(cs);

		cs >> m_ullTimeout >> m_bClientRequest;
		void * pBuf = NULL;
		cs.Pop(pBuf , sizeof(m_szRemoteName)); 
		memcpy(m_szRemoteName , pBuf , sizeof(m_szRemoteName));
		 
		return cs;
	}

	UINT32 RPCMsgCall::GetPacketSize( void ) 
	{
		return ObjectMsgCall::RefreshSize() + RefreshSize();
	}

	void RPCMsgCall::AddDelayTarget(Msg::Object obj)
	{
		CollectionTargetsT::iterator iter = m_setDelayTargets.find(obj);
		if (iter == m_setDelayTargets.end())
		{
			m_setDelayTargets.insert(obj);
		}
	}

	void RPCMsgCall::ReplaceDelayTarget()
	{
		CollectionTargetsT::iterator iter = m_setDelayTargets.begin();
		for (UINT32 i = 0;iter == m_setDelayTargets.end() && i < m_unTargetsCount;++iter , ++i)
		{
			m_aTargets[i] = *iter;
		}
		m_unTargetsCount = (UINT32)m_setDelayTargets.size();
		m_setDelayTargets.clear();
	}



}