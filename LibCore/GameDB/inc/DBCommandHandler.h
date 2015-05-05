#ifndef __gamedb_db_command_handler_h__ 
#define __gamedb_db_command_handler_h__
#include "GameDB/inc/DatabaseCommon.h"

namespace GameDB
{ 
	class DLL_EXPORT DBCommandHandler
	{
	public:
//		typedef int (ServerConnection::*fnCommandHandler)(gdb::SProtocolPacket** packets,size_t count);
		typedef int (*fnCommandHandler)();
		typedef std::map<UINT32 , fnCommandHandler> CollectDBCommandHandlersT;

	public:
		BOOL   InitCommandMaps();
	private:
		CollectDBCommandHandlersT    m_mapCommandHandlers;
	};
}

#endif