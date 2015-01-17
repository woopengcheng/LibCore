#include "MsgLib/inc/Parameter.h"
#include "Marshal/CStream.h"

namespace Msg
{ 
	UINT32 Parameter::Serialization( char * pMsg )
	{
		UINT32 unSize = sizeof(m_objParamType);

		memcpy(pMsg , &m_objParamType , unSize);
		memcpy(pMsg + unSize , &m_unParamSize , sizeof(m_unParamSize));
		unSize += sizeof(m_unParamSize);

		switch(m_objParamType)
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

		m_objParamType = *(UINT32*)pMsg;
		unSize += sizeof(m_objParamType);
		m_unParamSize = *(UINT32*)(pMsg + unSize);
		unSize += sizeof(m_unParamSize);

		switch(m_objParamType)
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
			(m_objParamType == PARAMETER_TYPE_STRING ||
			m_objParamType == PARAMETER_TYPE_CHUNK))
		{
			SAFE_DELETE_ARRAY(value_BUF);
		}
		m_unParamSize = 0;
		m_objParamType = PARAMETER_TYPE_ERROR;
	}

	UINT32 Parameter::Copy( Parameter & objParameter )
	{ 
		if (m_unParamSize > 0 && 
			(m_objParamType == PARAMETER_TYPE_STRING ||
			m_objParamType == PARAMETER_TYPE_CHUNK))
		{
			SAFE_DELETE_ARRAY(value_BUF);
			m_unParamSize = 0;
		}

		switch(m_objParamType)
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
		objParameter.m_objParamType = m_objParamType; 

		return ERR_SUCCESS;
	}

	LibCore::CStream & Parameter::marshal( LibCore::CStream & cs )
	{  
		MsgAssert_Re(!(m_objParamType > PARAMETER_TYPE_ERROR || m_objParamType < PARAMETER_TYPE_COUNT) , cs , "ParamType error.");
		cs << (INT32)m_objParamType << m_unParamSize; 
		cs.Pushback((void *)value_BUF , m_unParamSize);
		 
		return cs; 

	}

	LibCore::CStream & Parameter::unMarshal( LibCore::CStream & cs )
	{  
		MsgAssert_Re (cs.GetCurPos() + sizeof(INT32) + sizeof(m_unParamSize) <= cs.GetDataLen() , cs , "CStream pop error.");

		cs >> m_objParamType;
		cs >> m_unParamSize;

		MsgAssert_Re (cs.GetCurPos() + m_unParamSize <= cs.GetDataLen() , cs , "CStream pop error.");

		void * pBuf = NULL;
		cs.Pop(pBuf , m_unParamSize); 
		value_BUF = (char *)pBuf;

		return cs; 
	}

}