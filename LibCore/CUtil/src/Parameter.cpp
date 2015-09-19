#include "CUtil/inc/Parameter.h"
#include "Marshal/inc/CStream.h"

namespace CUtil
{  

	Parameter::Parameter() 
		: m_unSize(0)
	{   
	}
	
	Parameter::Parameter( const Parameter & objParameter )
		: m_unSize(objParameter.m_unSize)
	{
		m_objParamStream = objParameter.GetParamStream();
	}

	Parameter & Parameter::operator=( const Parameter & objParameter )
	{ 
		m_unSize = objParameter.m_unSize;
		m_objParamStream = objParameter.m_objParamStream; 

		return *this;
	} 

	CErrno Parameter::Copy(const Parameter & objParameter )
	{ 
		m_unSize = objParameter.m_unSize;
		m_objParamStream.Copy(objParameter.m_objParamStream);

		return CErrno::Success();
	}

	CUtil::CStream & Parameter::marshal( CUtil::CStream & cs )const 
	{  
		cs << m_unSize;
		cs << m_objParamStream; 
		 
		return cs; 
	}

	CUtil::CStream & Parameter::unMarshal( CUtil::CStream & cs )
	{  
		cs >> m_unSize;
		cs >> m_objParamStream;
		return cs; 
	}

	UINT32 Parameter::GetSize() const
	{ 
		return m_unSize;
// 		UINT32 unSize = 0 ;
// 		UINT8 unType = 0;
// 		m_objParamStream >> CUtil::Marshal::Begin >> unType >> unSize >> CUtil::Marshal::Rollback;
// 
// 		return unSize;
	}

	UINT8 Parameter::GetType()
	{ 
		UINT8 unType = 0;
		m_objParamStream >> CUtil::Marshal::Begin >> unType >> CUtil::Marshal::Rollback;

		return unType;
	}

	void    * Parameter::GetValue(void)
	{
		UINT8 unType = 0;
		void * pBuf = NULL;

		m_objParamStream >> CUtil::Marshal::Begin >> unType;
		m_objParamStream.Pop(pBuf , m_unSize);
		m_objParamStream >> CUtil::Marshal::Rollback; 

		return pBuf;
	}

	void      Parameter::Clear( void )
	{ 
		m_unSize = 0;
		m_objParamStream.Clear();
	}

	void * Parameter::GetStreamData(void)
	{
		return m_objParamStream.Begin();
	}

}