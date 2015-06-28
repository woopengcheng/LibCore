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
		//5 ���ز���
		static void  pfnHandleHelp(DBClient * pClient , INT32 argc , char ** argv);

		//5 ���ݿ���ز���
		static void  pfnHandleSelectDatabase(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleCreateDatabase(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleDeleteDatabase(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleShowDatabases(DBClient * pClient , INT32 argc , char ** argv);

		//5 ���,ɾ��,�޸��û�Ȩ�� 
		static void  pfnHandleCreateUser(DBClient * pClient , INT32 argc , char ** argv); 
		static void  pfnHandleDeleteUser(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleModifyUser(DBClient * pClient , INT32 argc , char ** argv);

		//5 ���ݿ������޸�
		static void  pfnHandleHSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHGet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHSetNX(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHSetOW(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHDel(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHMultiSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHMultiGet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHMultiDel(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHSetIncr(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHSetIncrFloat(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHGetKeys(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHGetVals(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHKeyVals(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHScan(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHCount(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHDrop(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleHList(DBClient * pClient , INT32 argc , char ** argv);  //5 ��HGetKeys���ܸ���.

		static void  pfnHandleZSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZDel(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZGet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZTop(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZRTop(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZDrop(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZCount(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleZList(DBClient * pClient , INT32 argc , char ** argv);

		static void  pfnHandleDump(DBClient * pClient , INT32 argc , char ** argv);

		//5 Orm����.
		static void  pfnHandleOrmHSet(DBClient * pClient , INT32 argc , char ** argv);
		static void  pfnHandleOrmCollectInsert(DBClient * pClient , INT32 argc , char ** argv);

	private:
		CollectionClientCommandsT m_mapCommands;
	};
}

#endif
