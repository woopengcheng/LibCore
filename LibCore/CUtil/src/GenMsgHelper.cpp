#include "CUtil/inc/GenMsgHelper.h"
#include "CUtil/inc/Parameters.h"

namespace CUtil
{
	UINT32 GenMsgHelper::GenMsgParams(CUtil::Parameters & objParams)
	{
		objParams.m_unParamCount = 0; 
		return 0;
	}

	BOOL GenMsgHelper::CheckParams(CUtil::Parameters & objParams)
	{
		bool bResult = true;
		if(objParams.m_unParamCount != 0)
		{
			bResult = false;
		}    

		return bResult;
	}
}