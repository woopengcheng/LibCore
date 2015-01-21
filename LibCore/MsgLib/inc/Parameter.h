#ifndef __msg_parameter_h__
#define __msg_parameter_h__ 
#include "MsgLib/inc/MsgCommon.h"
#include "Marshal/Marshal.h"
#include "Marshal/CStream.h"

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
		Parameter(); 
		Parameter(INT32 nType , UINT32 unSize , void * pData); 
		Parameter(const Parameter & objParameter) ;

		virtual ~Parameter(){}

		Parameter & operator = (const Parameter & objParameter);

	public:
		void       Clear(void);
		UINT32     GetSize( void );
		UINT32     GetType( void );
		void    *  GetData( void );
		UINT32     Copy(Parameter & objParam);
		LibCore::CStream  GetParamStream() const { return m_objParamStream; } 
		LibCore::CStream & GetParamStream() { return m_objParamStream; } 

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	private:
		LibCore::CStream   m_objParamStream;
	};

}
#endif