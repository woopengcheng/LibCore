#include "MsgLib/inc/RPCMsgCall.h"
#include "Marshal/CStream.h"

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
// 
// 	void RPCMsgCall::RefreshTargets()
// 	{
// 		m_aTargets = NULL;
// 		const char * pThis = (const char * )this;
// 		m_aTargets = new ((void*)(pThis + sizeof(RPCMsgCall)))Object;  //5 这里是用多申请的内存作为这里的指针进行初始化.
// 	}

	UINT32 RPCMsgCall::RefreshSize()
	{ 
		m_unMsgLength = ObjectMsgCall::RefreshSize() + sizeof(m_ullTimeout) + sizeof(m_bClientRequest) + sizeof(m_szRemoteName); 
		return m_unMsgLength;
	}
	
	UINT32 RPCMsgCall::Copy( RPCMsgCall *& pMsg )
	{
		pMsg = new(sizeof(Object) * GetTargetsCount())RPCMsgCall;  

		pMsg->m_objProxySrcID  = m_objProxySrcID;
		pMsg->m_ullTimeout     = m_ullTimeout;
		pMsg->m_bClientRequest = m_bClientRequest;   
		pMsg->m_unMsgLength    = m_unMsgLength; 
		pMsg->m_ullMsgID       = m_ullMsgID; 
		pMsg->m_objSource      = m_objSource;
		pMsg->m_usPriority     = m_usPriority;
		memcpy(pMsg->m_szSessionName , m_szSessionName , sizeof(m_szSessionName)); 
		memcpy(pMsg->m_szMsgMethod , m_szMsgMethod , sizeof(m_szMsgMethod)); 
		memcpy(pMsg->m_szRemoteName , m_szRemoteName , sizeof(m_szRemoteName)); 
		m_objParams.Copy(pMsg->m_objParams);  

		UINT32 unTargetsCount = GetTargetsCount();
		pMsg->SetTargetsCount(unTargetsCount);    //5 这个必须放在最后刷新内存.
		for (UINT32 i = 0;i < unTargetsCount;++i)
		{
			pMsg->m_aTargets[i] = m_aTargets[i];
		}  
		return ERR_SUCCESS; 
	}

	LibCore::CStream & RPCMsgCall::marshal( LibCore::CStream & cs )
	{  
		ObjectMsgCall::marshal(cs);
		cs << m_ullTimeout << m_bClientRequest;
		cs.Pushback(m_szRemoteName , sizeof(m_szRemoteName));
		 
		return cs;
	}

	LibCore::CStream & RPCMsgCall::unMarshal( LibCore::CStream & cs )
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

}