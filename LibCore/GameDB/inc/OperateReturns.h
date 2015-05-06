#ifndef __gamedb_operate_returns_h__
#define __gamedb_operate_returns_h__ 
#include "GameDB/inc/DBCommon.h" 

namespace GameDB
{  
	class DLL_EXPORT OperateReturns
	{
	public:
		Parameters & GetWriter(){ return m_objParamters; }

	private:
		Parameters   m_objParamters;
	};

}

#endif
