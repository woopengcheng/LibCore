#include "Parameter.h"

namespace Msg
{ 
	UINT32 Parameter::Serialization( char * pMsg )
	{
		UINT32 unSize = sizeof(m_unParamType);

		memcpy(pMsg , &m_unParamType , unSize);
		memcpy(pMsg + unSize , &m_unParamSize , sizeof(m_unParamSize));
		unSize += sizeof(m_unParamSize);

		switch(m_unParamType)
		{
		case PARAMETER_TYPE_INT32: 
		case PARAMETER_TYPE_INT64: 
		case PARAMETER_TYPE_DOUBLE:
			{ 
				memcpy(pMsg + unSize, &value_INT64 , sizeof(value_INT64));
			}break;
		case PARAMETER_TYPE_CHUNK:
		case PARAMETER_TYPE_STRING:
			{
				memcpy(pMsg + unSize, value_BUF , m_unParamSize);  
			}break; 
		default:
			break;
		}
		unSize += m_unParamSize;

		return unSize;
	}

	UINT32 Parameter::UnSerialization(const char * pMsg )
	{
		UINT32 unSize = 0;

		m_unParamType = *(UINT32*)pMsg;
		unSize += sizeof(m_unParamType);
		m_unParamSize = *(UINT32*)(pMsg + unSize);
		unSize += sizeof(m_unParamSize);

		switch(m_unParamType)
		{
		case PARAMETER_TYPE_INT32: 
		case PARAMETER_TYPE_INT64: 
		case PARAMETER_TYPE_DOUBLE:
			{  
				value_INT64 = *(INT64*)(pMsg + unSize); 
			}break;
		case PARAMETER_TYPE_CHUNK:
		case PARAMETER_TYPE_STRING:
			{
				value_BUF = new char[m_unParamSize]; 
				memcpy(value_BUF , pMsg + unSize , m_unParamSize); 
			}break; 
		default:
			break;
		}
		unSize += m_unParamSize;

		return unSize;
	}

	void Parameter::Clear( void )
	{
		if (m_unParamSize > 0 && 
			(m_unParamType == PARAMETER_TYPE_STRING ||
			m_unParamType == PARAMETER_TYPE_CHUNK))
		{
			SAFE_DELETE_ARRAY(value_BUF);
		}
		m_unParamSize = 0;
		m_unParamType = PARAMETER_TYPE_ERROR;
	}

	UINT32 Parameter::Copy( Parameter & objParameter )
	{ 
		if (m_unParamSize > 0 && 
			(m_unParamType == PARAMETER_TYPE_STRING ||
			m_unParamType == PARAMETER_TYPE_CHUNK))
		{
			SAFE_DELETE_ARRAY(value_BUF);
			m_unParamSize = 0;
		}

		switch(m_unParamType)
		{
		case PARAMETER_TYPE_INT32:
			{
				objParameter.value_INT32 = value_INT32;
			}break;
		case PARAMETER_TYPE_INT64:
			{
				objParameter.value_INT64 = value_INT64;
			}break;
		case PARAMETER_TYPE_DOUBLE:
			{
				objParameter.value_DOUBLE = value_DOUBLE;
			}break;
		case PARAMETER_TYPE_CHUNK:
		case PARAMETER_TYPE_STRING:
			{
				objParameter.value_BUF = new char[m_unParamSize];
				memcpy(objParameter.value_BUF , value_BUF , m_unParamSize);
			}break; 
		default:
			break;
		} 

		objParameter.m_unParamSize = m_unParamSize;
		objParameter.m_unParamType = m_unParamType; 

		return 1;
	}

}