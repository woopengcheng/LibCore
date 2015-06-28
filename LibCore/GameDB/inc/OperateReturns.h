#ifndef __gamedb_operate_returns_h__
#define __gamedb_operate_returns_h__ 
#include "GameDB/inc/DBCommon.h" 

namespace GameDB
{  
	class DLL_EXPORT OperateReturns
	{
	public: 
		LibCore::CStream & GetStream(){ return m_objStream; }

	private: 
		LibCore::CStream	m_objStream;
	};

}

#endif
