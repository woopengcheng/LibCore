#ifndef __msg_parameter_helper_h__
#define __msg_parameter_helper_h__
#include "MsgCommon.h"
#include "Parameter.h"
#include "Chunk.h"

namespace Msg 
{ 

	template<typename T>
	class  ParameterHelper
	{

	};

	template<> class ParameterHelper<const char *>
	{
	public:
		static PARAMETER_TYPE GetParameterType()
		{
			return PARAMETER_TYPE_STRING;
		}

		static const char * GetParameterValue(Parameter & objParam)
		{
			switch (objParam.GetType())
			{
			case PARAMETER_TYPE_CHUNK:
			case PARAMETER_TYPE_STRING:
				{
					return objParam.value_BUF;
				}
				break;
			default:
				MsgAssert_Re0(false , "invalid convert to const char*");
			}

			return NULL;
		}

		static void MakeParameter(Parameter & objParam , const char * pValue)
		{ 
			if (objParam.GetSize() != 0)
			{
				SAFE_DELETE_ARRAY(objParam.value_BUF);
				objParam.SetSize(0);
			}
			if (!pValue)
			{
				objParam.SetSize(0);
				objParam.value_BUF = NULL;
				objParam.SetType(PARAMETER_TYPE_STRING);
			}
			else
			{
				UINT32 unSize = (UINT32)strlen(pValue) + 1;
				objParam.SetSize(unSize);
				objParam.SetType(PARAMETER_TYPE_STRING);

				objParam.value_BUF = new char[unSize];
				memcpy(objParam.value_BUF , pValue , unSize);  
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
			switch (objParam.GetType())
			{
			case PARAMETER_TYPE_CHUNK: 
				{
					LibCore::Chunk objChunk(objParam.value_BUF , objParam.GetSize()); 
					return objChunk;
				}
				break;
			default:
				MsgAssert_Re(false , LibCore::Chunk() , "invalid convert to Chunk" );
			}

			return LibCore::Chunk();
		}

		static void MakeParameter(Parameter & objParam , LibCore::Chunk pValue)
		{ 
			if (objParam.GetSize() != 0)
			{
				SAFE_DELETE_ARRAY(objParam.value_BUF);
				objParam.SetSize(0);
			}

			objParam.SetSize(pValue.GetSize());
			objParam.SetType(PARAMETER_TYPE_CHUNK);

			objParam.value_BUF = new char[pValue.GetSize()]; 
			memcpy(objParam.value_BUF , pValue.GetBuf() , pValue.GetSize());  
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

	template<> class ParameterHelper<INT32>
	{
	public:
		static PARAMETER_TYPE GetParameterType()
		{
			return PARAMETER_TYPE_INT32;
		}

		static INT32 GetParameterValue(Parameter & objParam)
		{ 
			switch (objParam.GetType())
			{
			case PARAMETER_TYPE_INT32: 
				{ 
					return objParam.value_INT32;
				}
				break; 
			default:
				MsgAssert_ReF1(false , "invalid convert to INT32");
			}

			return ERR_FAILURE;
		}

		static void MakeParameter(Parameter & objParam , INT32 nValue)
		{ 
			objParam.SetSize(sizeof(INT64));
			objParam.SetType(PARAMETER_TYPE_INT32);
			objParam.value_INT32 = nValue;
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_INT32)
			{
				return TRUE;
			}
			return FALSE;
		}
	};

	template<> class ParameterHelper<bool>
	{
	public:
		static PARAMETER_TYPE GetParameterType()
		{
			return PARAMETER_TYPE_INT32;
		}

		static bool GetParameterValue(Parameter & objParam)
		{ 
			switch (objParam.GetType())
			{
			case PARAMETER_TYPE_INT32: 
				{ 
					return objParam.value_INT32 == 1;
				}
				break; 
			default:
				MsgAssert_Re0(false , "invalid convert to bool");
			}

			return false;
		}

		static void MakeParameter(Parameter & objParam , bool bValue)
		{ 
			objParam.SetSize(sizeof(INT64));
			objParam.SetType(PARAMETER_TYPE_INT32);
			objParam.value_INT32 = bValue;
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_INT32)
			{
				return TRUE;
			}
			return FALSE;
		}
	};

	template<> class ParameterHelper<INT64>
	{
	public:
		static PARAMETER_TYPE GetParameterType()
		{
			return PARAMETER_TYPE_INT64;
		}

		static INT64 GetParameterValue(Parameter & objParam)
		{ 
			switch (objParam.GetType())
			{ 
			case PARAMETER_TYPE_INT64: 
				{ 
					return objParam.value_INT64;
				}
				break; 
			default:
				MsgAssert_ReF1(false , "invalid convert to INT64" );
			}

			return -1;
		}

		static void MakeParameter(Parameter & objParam , INT64 nValue)
		{ 
			objParam.SetSize(sizeof(INT64));
			objParam.SetType(PARAMETER_TYPE_INT64);
			objParam.value_INT64 = nValue;
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_INT64)
			{
				return TRUE;
			}
			return FALSE;
		}
	};


	template<> class ParameterHelper<double>
	{
	public:
		static PARAMETER_TYPE GetParameterType()
		{
			return PARAMETER_TYPE_DOUBLE;
		}

		static double GetParameterValue(Parameter & objParam)
		{ 
			switch (objParam.GetType())
			{ 
			case PARAMETER_TYPE_DOUBLE: 
				{ 
					return objParam.value_DOUBLE;
				}
				break; 
			default:
				MsgAssert_Re(false  , 0.0f , "invalid convert to double");
			}

			return 0.0f;
		}

		static void MakeParameter(Parameter & objParam , double dValue)
		{ 
			objParam.SetSize(sizeof(INT64));
			objParam.SetType(PARAMETER_TYPE_DOUBLE);
			objParam.value_DOUBLE = dValue;
		}

		static BOOL CheckParamType(Parameter & objParam)
		{
			if (objParam.GetType() == PARAMETER_TYPE_DOUBLE)
			{
				return TRUE;
			}
			return FALSE;
		}
	};

	template<> struct ParameterHelper<char> : public ParameterHelper<INT32> {};
	template<> struct ParameterHelper<INT16> : public ParameterHelper<INT32> {};
	template<> struct ParameterHelper<UINT16> : public ParameterHelper<INT32> {}; 
	template<> struct ParameterHelper<UINT32> : public ParameterHelper<INT32> {};
	template<> struct ParameterHelper<long> : public ParameterHelper<INT64> {}; 
	template<> struct ParameterHelper<UINT64> : public ParameterHelper<INT64> {}; 
}

#endif
