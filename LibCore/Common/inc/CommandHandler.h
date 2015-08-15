#ifndef __cutil_common_handler_h__ 
#define __cutil_common_handler_h__
#include "Common/inc/Common.h"

namespace CUtil
{
	//////////////////////////////////////对象的命令处理////////////////////////////////////
	template<typename T , typename func>
	class CommandHandler_O
	{
	public:
		typedef std::map<UINT32 , func> CollectCommandHandlersT;
	
	public:
		BOOL   InitCommandMaps();
	private:
		CollectCommandHandlersT    m_mapCommandHandlers;
	};
}

#endif