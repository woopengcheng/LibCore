#ifndef __client_client_commands_h__ 
#define __client_client_commands_h__
#include "GameDB/inc/DBCommon.h"
#include "DBClient.h"

namespace Client
{
	class ClientCommands;
//	typedef void (* pfnClientCommand)(DBClient * pClient , INT32 argc , char ** argv);
	typedef void (* pfnClientCommand)(DBClient * pClient , std::vector<std::string> & objParams);

	class ClientCommands
	{
	public:
		typedef std_unordered_map<std::string , pfnClientCommand> CollectionClientCommandsT;

	public:
		ClientCommands(); 

	public:
		void InitCommands(); 
		void Execute(DBClient * pClient , std::vector<std::string> & objParams);

	public:
		//5 ���ز���
		static void  pfnHandleHelp(DBClient * pClient ,  std::vector<std::string> & objParams);

		//5 ���ݿ���ز���
		static void  pfnHandleSelectDatabase(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleCreateDatabase(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleDeleteDatabase(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleShowDatabases(DBClient * pClient ,  std::vector<std::string> & objParams);

		//5 ���,ɾ��,�޸��û�Ȩ�� 
		static void  pfnHandleCreateUser(DBClient * pClient ,  std::vector<std::string> & objParams); 
		static void  pfnHandleDeleteUser(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleModifyUser(DBClient * pClient ,  std::vector<std::string> & objParams);

		//5 ���ݿ������޸�
		static void  pfnHandleHSet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHGet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHSetNX(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHSetOW(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHDel(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHMultiSet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHMultiGet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHMultiDel(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHSetIncr(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHSetIncrFloat(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHGetKeys(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHGetVals(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHKeyVals(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHScan(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHCount(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHDrop(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleHList(DBClient * pClient ,  std::vector<std::string> & objParams);  //5 ��HGetKeys���ܸ���.

		static void  pfnHandleZSet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZDel(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZGet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZTop(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZRTop(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZDrop(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZCount(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleZList(DBClient * pClient ,  std::vector<std::string> & objParams);

		static void  pfnHandleDump(DBClient * pClient ,  std::vector<std::string> & objParams);

		//5 Orm����.
		static void  pfnHandleOrmHSet(DBClient * pClient ,  std::vector<std::string> & objParams);
		static void  pfnHandleOrmCollectInsert(DBClient * pClient ,  std::vector<std::string> & objParams);

	private:
		CollectionClientCommandsT m_mapCommands;
	};
}

#endif
