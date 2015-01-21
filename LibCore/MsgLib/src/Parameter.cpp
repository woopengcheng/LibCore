#include "MsgLib/inc/Parameter.h"
#include "Marshal/CStream.h"

namespace Msg
{  

	Parameter::Parameter() 
	{  
//		m_objParamStream << (INT32)0 << (INT32)0;   
	}

	Parameter::Parameter( INT32 nType , UINT32 unSize , void * pData ) 
	{
// 		MsgAssert(!(nType > PARAMETER_TYPE_ERROR || nType < PARAMETER_TYPE_COUNT) , "ParamType error.");
// 		m_objParamStream << nType << unSize;    
// 		m_objParamStream.Pushback(pData , unSize);
	} 

	Parameter::Parameter( const Parameter & objParameter )
	{
		m_objParamStream = objParameter.GetParamStream();
	}

	Parameter & Parameter::operator=( const Parameter & objParameter )
	{ 
		m_objParamStream = objParameter.m_objParamStream; 

		return *this;
	} 

	UINT32 Parameter::Copy( Parameter & objParameter )
	{ 
		objParameter.m_objParamStream.Copy(m_objParamStream);

		return ERR_SUCCESS;
	}

	LibCore::CStream & Parameter::marshal( LibCore::CStream & cs )
	{  
		cs.Pushback(m_objParamStream.Begin() , m_objParamStream.GetDataLen());
		 
		return cs; 
	}

	LibCore::CStream & Parameter::unMarshal( LibCore::CStream & cs )
	{  
		UINT32 unSize = 0 , unType = 0;
		void * pBuf = NULL;

		cs >> unType >> unSize;
		if (unSize > 0)
		{
			cs.Pop(pBuf , unSize);
		}

		m_objParamStream << unType << unSize;
		m_objParamStream.Pushback(pBuf , unSize);
		return cs; 
	}

	UINT32 Parameter::GetSize()
	{
		UINT32 unSize = 0 , unType = 0;
		m_objParamStream << LibCore::Marshal::Begin << unType << unSize << LibCore::Marshal::Rollback;

		return unSize;
	}

	UINT32 Parameter::GetType()
	{
		UINT32 unType = 0;
		m_objParamStream << LibCore::Marshal::Begin << unType << LibCore::Marshal::Rollback;

		return unType;
	}

	void    * Parameter::GetData(void)
	{
		UINT32 unSize = 0 , unType = 0;
		void * pBuf = NULL;

		m_objParamStream << LibCore::Marshal::Begin << unType << unSize;
		if (unSize > 0)
		{
			m_objParamStream.Pop(pBuf , unSize);
		}
		m_objParamStream << LibCore::Marshal::Rollback; 

		return pBuf;
	}

	void      Parameter::Clear( void )
	{
		void * pBuf = NULL;
		m_objParamStream.Pop(pBuf , m_objParamStream.GetDataLen());
	}

}