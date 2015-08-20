#include "CUtil/inc/Parameter.h"
#include "Marshal/inc/CStream.h"

namespace CUtil
{  

	Parameter::Parameter() 
	{   
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

	CUtil::CStream & Parameter::marshal( CUtil::CStream & cs )
	{  
		cs << m_objParamStream; 
		 
		return cs; 
	}

	CUtil::CStream & Parameter::unMarshal( CUtil::CStream & cs )
	{  
		cs >> m_objParamStream;
		return cs; 
	}

	UINT32 Parameter::GetSize()
	{
		UINT32 unSize = 0 ;
		UINT8 unType = 0;
		m_objParamStream >> CUtil::Marshal::Begin >> unType >> unSize >> CUtil::Marshal::Rollback;

		return unSize;
	}

	UINT8 Parameter::GetType()
	{
		UINT8 unType = 0;
		m_objParamStream >> CUtil::Marshal::Begin >> unType >> CUtil::Marshal::Rollback;

		return unType;
	}

	void    * Parameter::GetData(void)
	{
		UINT32 unSize = 0 ;
		UINT8 unType = 0;
		void * pBuf = NULL;

		m_objParamStream >> CUtil::Marshal::Begin >> unType >> unSize;
		if (unSize > 0)
		{
			m_objParamStream.Pop(pBuf , unSize);
		}
		m_objParamStream >> CUtil::Marshal::Rollback; 

		return pBuf;
	}

	void      Parameter::Clear( void )
	{ 
		m_objParamStream.Clear();
	}

	void * Parameter::GetStreamData(void)
	{
		return m_objParamStream.Begin();
	}

}