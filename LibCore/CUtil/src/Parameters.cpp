#include "CUtil/inc/Parameters.h"
#include "Marshal/inc/CStream.h"

namespace CUtil
{ 
	UINT32 Parameters::GetSize()
	{
		UINT32 unResult = 0;
		for (UINT32 i = 0;i < m_unParamCount;++i)
		{
			unResult += m_aParameter[i].GetSize();
			unResult += sizeof(m_aParameter[i].GetType());
			unResult += sizeof(m_aParameter[i].GetSize());
		}

		unResult += sizeof(m_unParamCount);

		return unResult;
	}

	UINT32 Parameters::Copy( Parameters & pParam )
	{
		pParam.m_unParamCount = m_unParamCount;

		for (UINT32 i = 0;i < m_unParamCount;++i)
		{
			m_aParameter[i].Copy(pParam.m_aParameter[i]); 
		} 

		return ERR_SUCCESS;
	}
// 
// 	UINT32 Parameters::Serialization( char * pMsg )
// 	{
// 		UINT32 unSize = 0;
// 
// 		memcpy(pMsg , &m_unParamCount , sizeof(m_unParamCount));
// 		unSize += sizeof(m_unParamCount);
// 		
// 		for (UINT32 i = 0;i < m_unParamCount;++i)
// 		{  
// 			unSize += m_aParameter[i].Serialization(pMsg + unSize);
// 		}  
// 
// 		return unSize;
// 	}
// 
// 	UINT32 Parameters::UnSerialization(const char * pMsg )
// 	{    
// 		m_unParamCount = *(UINT32*)(pMsg);
// 		UINT32 unSize = sizeof(m_unParamCount); 
// 
// 		for (UINT32 i = 0;i < m_unParamCount;++i)
// 		{ 
// 			unSize += m_aParameter[i].UnSerialization(pMsg + unSize); 
// 		}  
// 
// 		return unSize;
// 	}
// 
// 	void Parameters::Clear( void )
// 	{
// 		for(int i = 0;i < MSG_MAX_PARAMETER_NUMBER;++i)
// 		{
// 			m_aParameter[i].Clear();
// 		}
// 		m_unParamCount = 0;
// 		 
// 	}

	CUtil::CStream & Parameters::marshal( CUtil::CStream & cs )
	{  
		MsgAssert_Re(m_unParamCount <= MSG_MAX_PARAMETER_NUMBER , cs , "超出参数表最大个数.");
		cs << m_unParamCount; 
		 
		for (UINT32 i = 0;i < m_unParamCount;++i)
		{
			cs << m_aParameter[i];
		} 

		return cs; 

	}

	CUtil::CStream & Parameters::unMarshal( CUtil::CStream & cs )
	{  
		cs >> m_unParamCount; 

		MsgAssert_Re(m_unParamCount <= MSG_MAX_PARAMETER_NUMBER , cs , "超出参数表最大个数.");

		for (UINT32 i = 0;i < m_unParamCount;++i)
		{
			cs >> m_aParameter[i];
		} 

		return cs; 
	}

	void Parameters::Clear( void )
	{ 
		for (UINT32 i = 0;i < m_unParamCount;++i)
		{
			m_aParameter[i].Clear();
		} 
	}

}