#include "Parameters.h"

namespace Msg
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
// 			pParam.m_aParameter[i].SetSize(m_aParameter[i].GetSize());
// 			pParam.m_aParameter[i].SetType(m_aParameter[i].GetType());
// 
// 			switch(m_aParameter[i].GetType())
// 			{
// 			case PARAMETER_TYPE_INT32:
// 				{
// 					pParam.m_aParameter[i].value_INT32 = m_aParameter[i].value_INT32;
// 				}break;
// 			case PARAMETER_TYPE_INT64:
// 				{
// 					pParam.m_aParameter[i].value_INT64 = m_aParameter[i].value_INT64;
// 				}break;
// 			case PARAMETER_TYPE_DOUBLE:
// 				{
// 					pParam.m_aParameter[i].value_DOUBLE = m_aParameter[i].value_DOUBLE;
// 				}break;
// 			case PARAMETER_TYPE_CHUNK:
// 			case PARAMETER_TYPE_STRING:
// 				{
// 					pParam.m_aParameter[i].value_BUF = new char[m_aParameter[i].GetSize()];
// 					memcpy(pParam.m_aParameter[i].value_BUF , m_aParameter[i].value_BUF , m_aParameter[i].GetSize());
// 				}break; 
// 			default:
// 				break;
// 			} 
		} 

		return TRUE;
	}

	UINT32 Parameters::Serialization( char * pMsg )
	{
		UINT32 unSize = 0;

		memcpy(pMsg , &m_unParamCount , sizeof(m_unParamCount));
		unSize += sizeof(m_unParamCount);
		
		for (UINT32 i = 0;i < m_unParamCount;++i)
		{  
			unSize += m_aParameter[i].Serialization(pMsg + unSize);
		}  

		return unSize;
	}

	UINT32 Parameters::UnSerialization(const char * pMsg )
	{    
		m_unParamCount = *(UINT32*)(pMsg);
		UINT32 unSize = sizeof(m_unParamCount); 

		for (UINT32 i = 0;i < m_unParamCount;++i)
		{ 
			unSize += m_aParameter[i].UnSerialization(pMsg + unSize); 
		}  

		return unSize;
	}

	void Parameters::Clear( void )
	{
		for(int i = 0;i < MSG_MAX_PARAMETER_NUMBER;++i)
		{
			m_aParameter[i].Clear();
		}
		m_unParamCount = 0;
		 
	}

}