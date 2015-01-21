#ifndef __msg_parameter_helper_h__
#define __msg_parameter_helper_h__
#include "MsgLib/inc/MsgCommon.h"
#include "MsgLib/inc/Parameter.h"
#include "Common/Chunk.h"
#include "Marshal/CStream.h"
#include "Marshal/CommonMarshal.h"

namespace Msg 
{ 
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
			UINT32 unType = 0 , unSize = 0;\
			type_name  val = 0;\
			\
			objParam.GetParamStream() >> unType >> unSize >> val;   \
			MsgAssert_Re0(unType == type_macro && unSize == sizeof(val) , "获取参数值错误.");\
			\
			return val;\
		}\
		\
		static void MakeParameter(Parameter & objParam , type_name val)\
		{ \
			objParam.GetParamStream() << (INT32)type_macro << (INT32)sizeof(val) << val;      \
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
	
	template<typename T> class  ParameterHelper { };


	template<> class ParameterHelper<const char *>
	{
	public:
		static PARAMETER_TYPE GetParameterType(){ return PARAMETER_TYPE_STRING; } 
		static const char * GetParameterValue(Parameter & objParam)
		{
			INT32 nType = 0 , nSize = 0;

			objParam.GetParamStream() >> nType >> nSize;
			MsgAssert_Re0(nType == PARAMETER_TYPE_STRING , "paramter type is error. :" << nType << " cur: " << PARAMETER_TYPE_STRING);
			MsgAssert_Re0(!((UINT32)nSize > objParam.GetParamStream().GetDataLen() - objParam.GetParamStream().GetCurPos()) , "unMarshal invalid length."); 
			 
			void * pBuf = NULL;
			objParam.GetParamStream().Pop(pBuf , nSize);

			return (const char * )pBuf; 
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

	template<> class ParameterHelper<LibCore::Chunk>
	{
	public:
		static PARAMETER_TYPE GetParameterType()
		{
			return PARAMETER_TYPE_CHUNK;
		}

		static LibCore::Chunk GetParameterValue(Parameter & objParam)
		{
			INT32 unType = 0 , unSize = 0;
			LibCore::Chunk val; 

			objParam.GetParamStream() >> unType >> unSize >> val;   
			MsgAssert_Re(unType == PARAMETER_TYPE_CHUNK && unSize == val.GetDataLen() , val , "获取参数值错误."); 

			return val;
		}

		static void MakeParameter(Parameter & objParam , LibCore::Chunk val)
		{ 
			objParam.GetParamStream() << (INT32)PARAMETER_TYPE_CHUNK << val.GetDataLen() << val;    
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_CHUNK)
			{
				return TRUE;
			}
			return FALSE;
		}
	}; 

	GEN_PARAMTER_HELPER(bool , PARAMETER_TYPE_BOOL); 
	GEN_PARAMTER_HELPER(char , PARAMETER_TYPE_INT8);
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

}

#endif
