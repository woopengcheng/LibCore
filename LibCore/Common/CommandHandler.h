#ifndef __libcore_common_handler_h__ 
#define __libcore_common_handler_h__
#include "Common/Common.h"

namespace LibCore
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