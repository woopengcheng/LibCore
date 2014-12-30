#ifndef __msg_parameter_h__
#define __msg_parameter_h__ 
#include "MsgCommon.h"

namespace Msg
{ 
	//5 ��������.��Ҫ���⼸��.�����Ĳ������Ϳ��Ը��������ȡģ���ػ��ķ�ʽ����ת��.
	enum PARAMETER_TYPE
	{ 
		PARAMETER_TYPE_ERROR  = 0 ,
		PARAMETER_TYPE_INT32  = 1 , 
		PARAMETER_TYPE_INT64  = 2 , 
		PARAMETER_TYPE_DOUBLE = 3 ,
		PARAMETER_TYPE_STRING = 4 ,
		PARAMETER_TYPE_CHUNK  = 5 ,
	};

	struct DLL_EXPORT Parameter
	{
	public:
		Parameter()
			: m_unParamSize(0)
			, m_unParamType(PARAMETER_TYPE_ERROR)
		{
			value_BUF = NULL;
		}

		Parameter(const Parameter & objParameter) 
		{ 
			Parameter * pParameter = const_cast<Parameter *>(&objParameter);   //5 �������������construction.��Ϊ�˽��copy���õ�����.
			pParameter->Copy(*this);
		}

		virtual ~Parameter()
		{
			if ((PARAMETER_TYPE_STRING == m_unParamType ||
				 PARAMETER_TYPE_CHUNK == m_unParamType) &&
				 value_BUF != NULL)
			{
				SAFE_DELETE_ARRAY(value_BUF);
			}
		}

		Parameter & operator = (const Parameter & objParameter)
		{ 
			Parameter * pParameter = const_cast<Parameter *>(&objParameter);   //5 �������������construction.��Ϊ�˽��copy���õ�����.
 			pParameter->Copy(*this);
// 
// 			if (m_unParamSize > 0 && 
// 				(m_unParamType == PARAMETER_TYPE_STRING ||
// 				m_unParamType == PARAMETER_TYPE_CHUNK))
// 			{
// 				SAFE_DELETE_ARRAY(value_BUF);
// 				m_unParamSize = 0;
// 			}
// 			
// 			switch(m_unParamType)
// 			{
// 			case PARAMETER_TYPE_INT32:
// 				{
// 					value_INT32 = objParameter.value_INT32;
// 				}break;
// 			case PARAMETER_TYPE_INT64:
// 				{
// 					value_INT64 = objParameter.value_INT64;
// 				}break;
// 			case PARAMETER_TYPE_DOUBLE:
// 				{
// 					value_DOUBLE = objParameter.value_DOUBLE;
// 				}break;
// 			case PARAMETER_TYPE_CHUNK:
// 			case PARAMETER_TYPE_STRING:
// 				{
// 					value_BUF = new char[objParameter.GetSize()];
// 					memcpy(value_BUF , objParameter.value_BUF , objParameter.GetSize());
// 				}break; 
// 			default:
// 				break;
// 			} 
// 
// 		    m_unParamSize = objParameter.m_unParamSize;
// 			m_unParamType = objParameter.m_unParamType; 
			return *this;
		} 

	public:
		UINT32     Copy(Parameter & objParam);
		UINT32     GetSize(){ return m_unParamSize; }
		void       SetSize(UINT32 unParamSize){ m_unParamSize = unParamSize;}
		UINT32     GetType(){ return m_unParamType; }
		void       SetType(UINT32 unParamType){ m_unParamType = unParamType; }

		union
		{
			INT32  value_INT32;
			INT64  value_INT64;
			double value_DOUBLE;
			char * value_BUF;           //5 ������Ҫ��Chunk��char*������.
		};

	public:
		void       Clear(void);
		UINT32     Serialization(char * pMsg);
		UINT32     UnSerialization(const char * pMsg);

	private:
		UINT32     m_unParamSize;         //5 �����Ĵ�С  
		UINT32     m_unParamType;         //5 ����������.��ӦPARAMETER_TYPE

	};

}
#endif