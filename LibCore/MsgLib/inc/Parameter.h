#ifndef __msg_parameter_h__
#define __msg_parameter_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "Marshal/Marshal.h"

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

		PARAMETER_TYPE_COUNT , 
	};

	struct DLL_EXPORT Parameter : public LibCore::Marshal
	{
	public:
		Parameter()
			: m_unParamSize(0)
			, m_objParamType(PARAMETER_TYPE_ERROR)
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
			if ((PARAMETER_TYPE_STRING == m_objParamType ||
				 PARAMETER_TYPE_CHUNK == m_objParamType) &&
				 value_BUF != NULL)
			{
				SAFE_DELETE_ARRAY(value_BUF);
			}
		}

		Parameter & operator = (const Parameter & objParameter)
		{ 
			Parameter * pParameter = const_cast<Parameter *>(&objParameter);   //5 �������������construction.��Ϊ�˽��copy���õ�����.
 			pParameter->Copy(*this);

			return *this;
		} 

	public:
		UINT32     Copy(Parameter & objParam);
		UINT32     GetSize(){ return m_unParamSize; }
		void       SetSize(UINT32 unParamSize){ m_unParamSize = unParamSize;}
		UINT32     GetType(){ return m_objParamType; }
		void       SetType(UINT32 unParamType){ m_objParamType = unParamType; }

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

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	private:
		UINT32			   m_unParamSize;         //5 �����Ĵ�С  
		INT32              m_objParamType;         //5 ����������.��ӦPARAMETER_TYPE

	};

}
#endif