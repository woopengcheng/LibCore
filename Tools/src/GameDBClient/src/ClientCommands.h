#ifndef __client_client_commands_h__ 
#define __client_client_commands_h__
#include "GameDB/inc/DBCommon.h"
#include "DBClient.h"

namespace Client
{
	class ClientCommands;
	typedef void (* pfnClientCommand)(DBClient * pClient , INT32 argc , char ** argv);

	class ClientCommands
	{
	public:
		typedef std_unordered_map<std::string , pfnClientCommand> CollectionClientCommandsT;

	public:
		ClientCommands(); 

	public:
		void InitCommands(); 
		void Execute(DBClient * pClient , INT32 argc , char ** argv);

	public:
		static void  pfnHandleHSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHGet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZGet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZTop(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZRTop(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleOrmHSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleCreateUser(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleOrmCollectInsert(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleDump(DBClient * pClient , INT32 argc , char ** argv);
	private:
		CollectionClientCommandsT m_mapCommands;
	};
}

#endif
