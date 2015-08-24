#ifndef __cutil_parameter_h__
#define __cutil_parameter_h__ 
#include "CUtil/inc/Common.h"
#include "Marshal/inc/Marshal.h"
#include "Marshal/inc/CStream.h"

namespace CUtil
{ 
	//5 参数类型.主要是这几种.其他的参数类型可以根据这个采取模板特化的方式进行转换.
	enum PARAMETER_TYPE
	{ 
		PARAMETER_TYPE_NIL  = 0 ,
		PARAMETER_TYPE_BOOL  , 
		PARAMETER_TYPE_SINT8  , 
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
		PARAMETER_TYPE_STD_STRING ,
		PARAMETER_TYPE_CHUNK  ,
		PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS  ,  //5 可能是容器,或者重写过CString的都支持.

		PARAMETER_TYPE_SYSTEM_COUNT ,

		PARAMETER_TYPE_USER_DEFINE = 32 ,   //5 用户自定义类型.从32后面开始吧.
	};

	struct DLL_EXPORT Parameter : public CUtil::Marshal
	{
	public:
		Parameter(); 
		Parameter(const Parameter & objParameter) ;
		template<typename T>
		Parameter(T & t)
		{
			MakeParameter(t);
		}

		virtual ~Parameter(){}

		Parameter & operator = (const Parameter & objParameter);

	public:
		void       Clear(void);
		UINT32     GetSize( void );
		UINT8	   GetType( void );
		void    *  GetData( void );
		UINT32     GetStreamSize( void ){ return m_objParamStream.GetDataLen(); }
		void    *  GetStreamData( void );
		UINT32     Copy(Parameter & objParam);
		CUtil::CStream  GetParamStream() const { return m_objParamStream; } 
		CUtil::CStream & GetParamStream() { return m_objParamStream; } 

	public:
		bool	   IsNil(){ return GetType() == PARAMETER_TYPE_NIL; }
		bool	   IsBoolean(){ return GetType() == PARAMETER_TYPE_BOOL; }
		bool	   IsInt8(){ return GetType() == PARAMETER_TYPE_SINT8; }
		bool	   IsUInt8(){ return GetType() == PARAMETER_TYPE_UINT8; }
		bool	   IsInt16(){ return GetType() == PARAMETER_TYPE_INT16; }
		bool	   IsUInt16(){ return GetType() == PARAMETER_TYPE_UINT16; }
		bool	   IsInt32(){ return GetType() == PARAMETER_TYPE_INT32; }
		bool	   IsUInt32(){ return GetType() == PARAMETER_TYPE_UINT32; }
		bool	   IsLong(){ return GetType() == PARAMETER_TYPE_LONG; }
		bool	   IsInt64(){ return GetType() == PARAMETER_TYPE_INT64; }
		bool	   IsUInt64(){ return GetType() == PARAMETER_TYPE_UINT64; } 
		bool	   IsFloat(){ return GetType() == PARAMETER_TYPE_FLOAT; }
		bool	   IsDouble(){ return GetType() == PARAMETER_TYPE_DOUBLE; }
		bool	   IsString(){ return GetType() == PARAMETER_TYPE_STRING; }
		bool	   IsStdString(){ return GetType() == PARAMETER_TYPE_STD_STRING; }
		bool	   IsChunk(){ return GetType() == PARAMETER_TYPE_CHUNK; }  
		bool	   IsContainerOrOthers(){ return GetType() == PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS; }  
		bool	   IsUserDefine(){ return GetType() >= PARAMETER_TYPE_USER_DEFINE; }  

	public:
		template<typename T>
		operator T ()
		{
			Parameter p;
			T t;
			p.MakeParameter(t);

			MsgAssert_Re(p.GetType() == GetType() , t , "not convert , type error.");
			return GetParameterValue<T>();
		}

	public: 
		virtual CUtil::CStream & marshal(CUtil::CStream & cs);
		virtual CUtil::CStream & unMarshal(CUtil::CStream & cs);

	public:
		template<typename P1>
		void MakeParameter(P1 & p1)
		{
			ParameterHelper<P1>::MakeParameter(*this , p1);
		} 

		template<typename P1>
		void GetParameterValue(P1 & p1)
		{
			ParameterHelper<P1>::GetParameterValue(*this , p1);
		} 

		template<typename P1>
		P1 GetParameterValue()
		{
			return ParameterHelper<P1>::GetParameterValue(*this);
		} 
	private:
		CUtil::CStream   m_objParamStream;
	};

}
#endif