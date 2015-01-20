#include "MsgLib/inc/ObjectMsgCall.h"
#include "Marshal/CStream.h"

namespace Msg
{

	UINT32 ObjectMsgCall::RefreshSize()
	{  
		m_unMsgLength =  m_unTargetsCount * sizeof(Object) + sizeof(m_ullMsgID) + sizeof(m_unTargetsCount)+ sizeof(m_unMsgLength) 
			+ sizeof(m_szMsgMethod) + m_objParams.GetSize() + sizeof(m_usPriority) + sizeof(m_objSource);
		return m_unMsgLength;
	}  

// 	void ObjectMsgCall::RefreshTargets()
// 	{  
// 		m_aTargets = NULL; 
// 		const char * pThis = (const char * )this;
// 		m_aTargets = new ((void*)(pThis + sizeof(ObjectMsgCall)))Object;  //5 这里是用多申请的内存作为这里的指针进行初始化.
// 
// 	}
//
// 	UINT32 ObjectMsgCall::Serialization( char * pMsg )
// 	{   
// 		UINT32 unSize = 0;
// 
// 		memcpy(pMsg + unSize , &m_unTargetsCount , sizeof(m_unTargetsCount));
// 		unSize += sizeof(m_unTargetsCount);
// 		memcpy(pMsg + unSize , m_aTargets , m_unTargetsCount * sizeof(Object));
// 		unSize += m_unTargetsCount * sizeof(Object);
// 		memcpy(pMsg + unSize , &m_objSource , sizeof(m_objSource));
// 		unSize += sizeof(m_objSource);
// 		memcpy(pMsg + unSize , &m_usPriority , sizeof(m_usPriority));
// 		unSize += sizeof(m_usPriority);
// 		memcpy(pMsg + unSize , m_szMsgMethod , sizeof(m_szMsgMethod));
// 		unSize += sizeof(m_szMsgMethod);
// 		memcpy(pMsg + unSize , &m_unMsgLength , sizeof(m_unMsgLength));
// 		unSize += sizeof(m_unMsgLength);
// 		memcpy(pMsg + unSize, &m_ullMsgID , sizeof(m_ullMsgID));
// 		unSize += sizeof(m_ullMsgID);
// 
// 		unSize += m_objParams.Serialization(pMsg + unSize); 
// 
// 		return unSize;
// 	} 
// 
// 	UINT32 ObjectMsgCall::UnSerialization(const char * pMsg )
// 	{
// 		UINT32 unSize = 0;      
// 
// 		m_unTargetsCount = *(UINT32*)(pMsg);     //5 第一位必须是他.否则有问题.
// 		unSize += sizeof(m_unTargetsCount); 
// 		memcpy(m_aTargets , pMsg + unSize , m_unTargetsCount * sizeof(Object));
// 		unSize += m_unTargetsCount * sizeof(Object);
// 		m_objSource = *(Object*)(pMsg + unSize);
// 		unSize += sizeof(m_objSource);
// 		m_usPriority = *(UINT16*)(pMsg + unSize);
// 		unSize += sizeof(m_usPriority);
// 		memcpy(m_szMsgMethod , pMsg + unSize , sizeof(m_szMsgMethod));
// 		unSize += sizeof(m_szMsgMethod);
// 		m_unMsgLength = *(UINT32*)(pMsg + unSize);
// 		unSize += sizeof(m_unMsgLength);
// 		m_ullMsgID = *(UINT64*)((pMsg + unSize));
// 		unSize += sizeof(m_ullMsgID);
// 
// 		unSize += m_objParams.UnSerialization(pMsg + unSize);   
// 		return unSize;
// 	}

	UINT32 ObjectMsgCall::Copy(ObjectMsgCall *& pMsg)
	{  
		pMsg = new(sizeof(Object)*m_unTargetsCount)ObjectMsgCall;

		pMsg->m_ullMsgID       = m_ullMsgID;
		pMsg->m_unMsgLength    = m_unMsgLength; 
		pMsg->m_objSource      = m_objSource;
		pMsg->m_usPriority     = m_usPriority;
		m_objParams.Copy(pMsg->m_objParams);  
		memcpy(pMsg->m_szMsgMethod , m_szMsgMethod , MAX_MSG_METHOD_NAME_LENGTH); 

		pMsg->SetTargetsCount(m_unTargetsCount); 
		for (UINT32 i = 0;i < m_unTargetsCount;++i)
		{
			pMsg->m_aTargets[i] = m_aTargets[i];
		} 

		return ERR_SUCCESS;
	} 

	LibCore::CStream & ObjectMsgCall::marshal( LibCore::CStream & cs )
	{ 
		cs << m_unTargetsCount;
		cs.Pushback(m_aTargets , m_unTargetsCount * sizeof(Object));
		cs << m_objSource << m_usPriority << m_szMsgMethod << m_unMsgLength << m_ullMsgID << m_objParams; 

		return cs;
	}

	LibCore::CStream & ObjectMsgCall::unMarshal( LibCore::CStream & cs )
	{
		cs >> m_unTargetsCount;

		void * pBuf = NULL;
		cs.Pop(pBuf , m_unTargetsCount);
		memcpy(m_aTargets , pBuf , m_unTargetsCount * sizeof(Object));
		 
		cs >> m_objSource >> m_usPriority >> m_szMsgMethod >> m_unMsgLength >> m_ullMsgID >> m_objParams; 

		return cs;
	}

	UINT32 ObjectMsgCall::GetPacketSize( void )
	{
		return RefreshSize();
	}

}