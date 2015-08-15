#ifndef __cutil_parameter_helper_h__
#define __cutil_parameter_helper_h__
#include "Common/inc/Parameter.h"
#include "Common/Chunk.h"
#include "Marshal/CStream.h"
#include "Marshal/CommonMarshal.h"

namespace CUtil 
{ 
#define GEN_PARAMTER_HELPER_REFER(type_name , type_macro )	template<> class ParameterHelper<type_name &>\
	{\
	public:\
		static INT32 GetParameterType()\
		{\
			return type_macro ;\
		}\
		\
		static type_name GetParameterValue(Parameter & objParam)\
		{ \
			return ParameterHelper<type_name>::GetParameterValue(objParam);\
		}\
		static BOOL GetParameterValue(Parameter & objParam , type_name & val)\
		{ \
			return ParameterHelper<type_name>::GetParameterValue(objParam , val);\
		}\
		\
		static void MakeParameter(Parameter & objParam , type_name & val)\
		{ \
			return ParameterHelper<type_name>::MakeParameter(objParam , val); \
		}\
		\
		static BOOL CheckParamType(Parameter & objParam)\
		{\
			if (objParam.GetType() == type_macro)\
			{\
				return TRUE;\
			}\
			return FALSE;\
		}\
	};


#define GEN_PARAMTER_HELPER(type_name , type_macro )	template<> class ParameterHelper<type_name>\
	{\
	public:\
		static INT32 GetParameterType()\
		{\
			return type_macro ;\
		}\
		\
		static type_name GetParameterValue(Parameter & objParam)\
		{ \
			UINT32 unType = 0;\
			type_name  val;\
			\
			objParam.GetParamStream() >> CUtil::Marshal::Begin >> unType >> val >> CUtil::Marshal::Rollback;   \
			MsgAssert_Re(unType == type_macro , val , "获取参数值错误.");\
			\
			return val;\
		}\
		\
		static BOOL GetParameterValue(Parameter & objParam , type_name & val)\
		{ \
			UINT32 unType = 0;\
			\
			objParam.GetParamStream() >> CUtil::Marshal::Begin >> unType >> val >> CUtil::Marshal::Rollback;   \
			MsgAssert_Re0(unType == type_macro , "获取参数值错误.");\
			\
			return TRUE;\
		}\
		\
		static void MakeParameter(Parameter & objParam , type_name & val)\
		{ \
			objParam.GetParamStream() << (INT32)type_macro << val;      \
		}\
		\
		static BOOL CheckParamType(Parameter & objParam)\
		{\
			if (objParam.GetType() == type_macro)\
			{\
				return TRUE;\
			}\
			return FALSE;\
		}\
	};\
	GEN_PARAMTER_HELPER_REFER(type_name , type_macro)
	
//	template<typename T > class  ParameterHelper { };
	 
	template<typename T> class ParameterHelper
	{
	public:
		static UINT32 GetParameterType(){ return PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS; } 
// 		static T GetParameterValue(Parameter & objParam)
// 		{
// 			INT32 nType = 0 ;
// 			T Value = T();
// 
// 			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType ;
// 			MsgAssert_Re(nType == PARAMETER_TYPE_STD_CONTAINER , Value , "paramter type is error:" << nType << ":cur=" << PARAMETER_TYPE_STD_CONTAINER);
// 
// 			CUtil::STLContainer<T> value = CUtil::STLContainer<T>(Value);
// 			objParam.GetParamStream() >> value >> CUtil::Marshal::Rollback;
// 
// 			return Value; 
// 		}
// 
// 		static void MakeParameter(Parameter & objParam , CUtil::STLContainer<T> value)
// 		{   
// 			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_STD_CONTAINER;  
// 			objParam.GetParamStream() << value;
// 		} 

		static T GetParameterValue(Parameter & objParam)
		{
			INT32 nType = 0 ;
			T Value = T();

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType ;
			MsgAssert_Re(nType == PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS , Value , "paramter type is error:" << nType << ":cur=" << PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS);

			objParam.GetParamStream() >> Value >> CUtil::Marshal::Rollback;

			return Value; 
		}

		static BOOL GetParameterValue(Parameter & objParam , T & Value)
		{
			INT32 nType = 0 ; 

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType ;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS , "paramter type is error:" << nType << ":cur=" << PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS);

			objParam.GetParamStream() >> Value >> CUtil::Marshal::Rollback;

			return TRUE; 
		}

		static void MakeParameter(Parameter & objParam , T & value)
		{   
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS;  
			objParam.GetParamStream() << value;
		} 

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == typeName)
			{
				return TRUE;
			}
			return FALSE;
		}

		static BOOL CheckParamType(Parameter & objParam , T & value = T())
		{
			if (objParam.GetType() == typeName)
			{
				return TRUE;
			}
			return FALSE;
		}
	};  

	template<typename T> class ParameterHelper<T &>
	{
	public:
		static UINT32 GetParameterType(){ return PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS; } 
		static T GetParameterValue(Parameter & objParam)
		{
			INT32 nType = 0 ;
			T Value = T();

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType ;
			MsgAssert_Re(nType == PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS , Value , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS);

//			CUtil::STLContainer<T> value = CUtil::STLContainer<T>(Value);
			objParam.GetParamStream() >> Value >> CUtil::Marshal::Rollback;

			return Value; 
		}

		static BOOL GetParameterValue(Parameter & objParam , T & Value)
		{
			INT32 nType = 0 ;

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType ;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STD_VECTOR);

//			CUtil::STLContainer<T> value = CUtil::STLContainer<T>(Value);
			objParam.GetParamStream() >> Value >> CUtil::Marshal::Rollback;

			return TRUE; 
		}

		static void MakeParameter(Parameter & objParam , T & value)
		{   
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS;  
			objParam.GetParamStream() << value;
		}
		 
		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == typeName)
			{
				return TRUE;
			}
			return FALSE;
		}
	};  

	template<> class ParameterHelper<const char *>
	{
	public:
		static UINT32 GetParameterType(){ return PARAMETER_TYPE_STRING; } 
		static const char * GetParameterValue(Parameter & objParam)
		{
			INT32 nType = 0 , nSize = 0;

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType >> nSize;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STRING , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STRING);
			MsgAssert_Re0(!((UINT32)nSize > objParam.GetParamStream().GetDataLen() - objParam.GetParamStream().GetCurPos()) , "unMarshal invalid length."); 
			 
			void * pBuf = NULL;
			objParam.GetParamStream().Pop(pBuf , nSize);

			objParam.GetParamStream() >> CUtil::Marshal::Rollback;
			return (const char * )pBuf; 
		}

		static BOOL GetParameterValue(Parameter & objParam , char *& p1)
		{
			INT32 nType = 0 , nSize = 0;

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType >> nSize;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STRING , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STRING);
			MsgAssert_Re0(!((UINT32)nSize > objParam.GetParamStream().GetDataLen() - objParam.GetParamStream().GetCurPos()) , "unMarshal invalid length."); 

			void * pBuf = NULL;
			objParam.GetParamStream().Pop(pBuf , nSize);

			objParam.GetParamStream() >> CUtil::Marshal::Rollback;
			p1 = (char *)pBuf;
			return TRUE; 
		}

		static void MakeParameter(Parameter & objParam , const char * pValue)
		{  
			if (!pValue)
			{
				objParam.GetParamStream() << (INT32)PARAMETER_TYPE_STRING << 0;  
				objParam.GetParamStream().Pushback((void*)pValue , 0);
			}
			else
			{
				UINT32 unSize = (UINT32)strlen(pValue) + 1;

				objParam.GetParamStream() << (INT32)PARAMETER_TYPE_STRING << unSize;  
				objParam.GetParamStream().Pushback((void*)pValue , unSize);
			} 
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_STRING)
			{
				return TRUE;
			}
			return FALSE;
		}
	};

	template<> class ParameterHelper<std::string>
	{
	public:
		static UINT32 GetParameterType(){ return PARAMETER_TYPE_STD_STRING; } 
		static std::string GetParameterValue(Parameter & objParam)
		{
			INT32 nType = 0 , nSize = 0;

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType >> nSize;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STD_STRING , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STD_STRING);
			MsgAssert_Re0(!((UINT32)nSize > objParam.GetParamStream().GetDataLen() - objParam.GetParamStream().GetCurPos()) , "unMarshal invalid length."); 

			std::string strValue;
			objParam.GetParamStream() >> strValue >> CUtil::Marshal::Rollback;

			return strValue; 
		}

		static BOOL GetParameterValue(Parameter & objParam , std::string & strValue)
		{
			INT32 nType = 0 , nSize = 0;

			objParam.GetParamStream() >> CUtil::Marshal::Begin >> nType >> nSize;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STD_STRING , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STD_STRING);
			MsgAssert_Re0(!((UINT32)nSize > objParam.GetParamStream().GetDataLen() - objParam.GetParamStream().GetCurPos()) , "unMarshal invalid length."); 
			 
			objParam.GetParamStream() >> strValue >> CUtil::Marshal::Rollback;

			return TRUE; 
		}

		static void MakeParameter(Parameter & objParam , std::string & strValue)
		{   
				UINT32 unSize = (UINT32)(strValue.length() + 1);

				objParam.GetParamStream() << (INT32)PARAMETER_TYPE_STD_STRING << unSize;  
				objParam.GetParamStream() << strValue;
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_STD_STRING)
			{
				return TRUE;
			}
			return FALSE;
		}
	};

	template<> class ParameterHelper<std::string &>
	{
	public:
		static UINT32 GetParameterType(){ return PARAMETER_TYPE_STD_STRING; } 
		static std::string GetParameterValue(Parameter & objParam)
		{
			return ParameterHelper<std::string>::GetParameterValue(objParam);
		}

		static BOOL GetParameterValue(Parameter & objParam , std::string & p1)
		{
			return ParameterHelper<std::string>::GetParameterValue(objParam , p1);
		}

		static void MakeParameter(Parameter & objParam , std::string & strValue)
		{   
			return ParameterHelper<std::string>::MakeParameter(objParam , strValue);
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_STD_STRING)
			{
				return TRUE;
			}
			return FALSE;
		}
	};
// 
// 	template<> class ParameterHelper<CUtil::Chunk>
// 	{
// 	public:
// 		static UINT32 GetParameterType()
// 		{
// 			return PARAMETER_TYPE_CHUNK;
// 		}
// 
// 		static CUtil::Chunk GetParameterValue(Parameter & objParam)
// 		{
// 			INT32 unType = 0 , unSize = 0;
// 			CUtil::Chunk val; 
// 
// 			objParam.GetParamStream() >> unType >> unSize >> val;   
// 			MsgAssert_Re(unType == PARAMETER_TYPE_CHUNK && unSize == val.GetDataLen() , val , "获取参数值错误."); 
// 
// 			return val;
// 		}
// 
// 		static void MakeParameter(Parameter & objParam , CUtil::Chunk val)
// 		{ 
// 			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_CHUNK << val.GetDataLen() << val;    
// 		}
// 
// 		static BOOL CheckParamType(Parameter & objParam)
// 		{
// 			if (objParam.GetType() == PARAMETER_TYPE_CHUNK)
// 			{
// 				return TRUE;
// 			}
// 			return FALSE;
// 		}
// 	}; 
// 
// 	template<> class ParameterHelper<CUtil::Chunk &>
// 	{
// 	public:
// 		static UINT32 GetParameterType()
// 		{
// 			return PARAMETER_TYPE_CHUNK;
// 		}
// 
// 		static CUtil::Chunk GetParameterValue(Parameter & objParam)
// 		{
// 			return ParameterHelper<CUtil::Chunk>::GetParameterValue(objParam);
// 		}
// 
// 		static void MakeParameter(Parameter & objParam , CUtil::Chunk val)
// 		{ 
// 			return ParameterHelper<CUtil::Chunk>::MakeParameter(objParam , val);  
// 		}
// 
// 		static BOOL CheckParamType(Parameter & objParam)
// 		{
// 			if (objParam.GetType() == PARAMETER_TYPE_CHUNK)
// 			{
// 				return TRUE;
// 			}
// 			return FALSE;
// 		}
// 	}; 

	GEN_PARAMTER_HELPER(bool , PARAMETER_TYPE_BOOL); 
	GEN_PARAMTER_HELPER(char , PARAMETER_TYPE_SINT8); 
	GEN_PARAMTER_HELPER(UINT8 , PARAMETER_TYPE_UINT8);
	GEN_PARAMTER_HELPER(INT16 , PARAMETER_TYPE_INT16);
	GEN_PARAMTER_HELPER(UINT16 , PARAMETER_TYPE_UINT16);
	GEN_PARAMTER_HELPER(long , PARAMETER_TYPE_LONG); 
	GEN_PARAMTER_HELPER(INT32 , PARAMETER_TYPE_INT32); 
	GEN_PARAMTER_HELPER(UINT32 , PARAMETER_TYPE_UINT32);
	GEN_PARAMTER_HELPER(INT64 , PARAMETER_TYPE_INT64);
	GEN_PARAMTER_HELPER(UINT64 , PARAMETER_TYPE_UINT64); 
	GEN_PARAMTER_HELPER(float , PARAMETER_TYPE_FLOAT);
	GEN_PARAMTER_HELPER(double , PARAMETER_TYPE_DOUBLE); 
//	GEN_PARAMTER_HELPER(std::string  , PARAMETER_TYPE_STD_STRING); 
	GEN_PARAMTER_HELPER(CUtil::Chunk , PARAMETER_TYPE_CHUNK);  
}

#endif
