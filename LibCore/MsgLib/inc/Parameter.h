#ifndef __msg_parameter_h__
#define __msg_parameter_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "Marshal/Marshal.h"

namespace Msg
{ 
	//5 参数类型.主要是这几种.其他的参数类型可以根据这个采取模板特化的方式进行转换.
	enum PARAMETER_TYPE
	{ 
		PARAMETER_TYPE_ERROR  = 0 ,
		PARAMETER_TYPE_BOOL  , 
		PARAMETER_TYPE_INT8  , 
		PARAMETER_TYPE_UINT8  , 
		PARAMETER_TYPE_INT16  , 
		PARAMETER_TYPE_UINT16  , 
		PARAMETER_TYPE_INT32  , 
		PARAMETER_TYPE_LONG  , 
		PARAMETER_TYPE_UINT32  , 
		PARAMETER_TYPE_INT64  , 
		PARAMETER_TYPE_UINT64  , 
		PARAMETER_TYPE_FLOAT ,
		PARAMETER_TYPE_DOUBLE ,
		PARAMETER_TYPE_STRING ,
		PARAMETER_TYPE_CHUNK  ,

		PARAMETER_TYPE_COUNT , 
	};

	struct DLL_EXPORT Parameter : public LibCore::Marshal
	{
	public:
		Parameter() 
			: m_pData(NULL)
			, m_unParamSize(0)
			, m_nParamType(0)
		{

		}

		Parameter(INT32 nType , UINT32 unSize , void * pData) 
			: m_pData(pData)
			, m_unParamSize(unSize)
			, m_nParamType(nType)
		{

		}

		Parameter(const Parameter & objParameter) 
		{  
			m_unParamSize = objParameter.m_unParamSize;
			m_nParamType = objParameter.m_nParamType; 
			m_objParamStream = objParameter.m_objParamStream;
		}

		virtual ~Parameter()
		{

		}

		Parameter & operator = (const Parameter & objParameter)
		{ 
			m_unParamSize = objParameter.m_unParamSize;
			m_nParamType = objParameter.m_nParamType; 
			m_objParamStream = objParameter.m_objParamStream; 

			return *this;
		} 

	public:
		UINT32     GetSize( void );
		UINT32     GetType( void );
		void    *  GetData( void );
		UINT32     Copy(Parameter & objParam);
		LibCore::CStream & GetParamStream() const { return m_objParamStream; } 
// 		 
// 	public:
// 		void       Clear(void);
// 		UINT32     Serialization(char * pMsg);
// 		UINT32     UnSerialization(const char * pMsg);

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	private:
		INT32              m_nParamType;         //5 参数的类型.对应PARAMETER_TYPE
		UINT32			   m_unParamSize;        //5 参数的大小  
		void     *         m_pData;
		LibCore::CStream   m_objParamStream;
	};

}
#endif