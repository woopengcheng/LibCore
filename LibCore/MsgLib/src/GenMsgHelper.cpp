#include "MsgLib/inc/GenMsgHelper.h"
#include "MsgLib/inc/RPCMsgCall.h"

namespace Msg
{ 
	BOOL GenMsgHelper::GenMsgCall( ObjectMsgCall & objMsgCall , const char * pMsgCallName , std::vector<Object> & vtTargets , Object objSrc  , UINT16 usPriority )
	{
		objMsgCall.m_objSource = objSrc;
		objMsgCall.m_usPriority = usPriority;

		if (vtTargets.size() == 0)
		{
			return FALSE;
		} 

		objMsgCall.SetTargetsCount((UINT32)vtTargets.size());
		std::vector<Object>::iterator iter = vtTargets.begin();
		for (UINT32 i = 0 ;iter != vtTargets.end();++iter , ++i)
		{
			objMsgCall.m_aTargets[i] = *iter; 
		}

		memcpy(objMsgCall.m_szMsgMethod , pMsgCallName , MAX_MSG_METHOD_NAME_LENGTH); 

		return TRUE;
	} 


	BOOL GenMsgHelper::GenMsgCall( ObjectMsgCall & objMsgCall, const char * pMsgCallName , UINT16 usPriority)
	{
		objMsgCall.m_usPriority = usPriority;

		memcpy(objMsgCall.m_szMsgMethod , pMsgCallName , MAX_MSG_METHOD_NAME_LENGTH); 

		return TRUE;
	} 


	BOOL GenMsgHelper::GenMsgCall( RPCMsgCall & objMsgCall , BOOL bRecvRequest/* = FALSE*/ , UINT64 ullTimeout/* = 10*/ , UINT64 ullMsgID/* = -1*/ , const char * pRemoteName/* = ""*/ , EMSG_SYNC_TYPE objSyncType /*= SYNC_TYPE_NONSYNC*/)
	{
		objMsgCall.SetSyncType(objSyncType);
		objMsgCall.m_bClientRequest = bRecvRequest;
		objMsgCall.m_ullTimeout = ullTimeout; 

		if (ullMsgID == 0)
		{
			objMsgCall.m_ullMsgID = (UINT64)((LibCore::GenerateUUIDByTime())); 
		} 
		else
		{
			objMsgCall.m_ullMsgID = ullMsgID;
		}

		memcpy(objMsgCall.m_szRemoteName , pRemoteName , strlen(pRemoteName) + 1);
		return TRUE;
	} 
}