#ifndef __gamedb_backup_environment_h__ 
#define __gamedb_backup_environment_h__
#include "GameDB/inc/DatabaseCommon.h"
#include "leveldb/env.h"
#include "port/port.h"

namespace GameDB
{
	struct SBackupDB
	{
		std::string strSrcDir;
		std::string strDstFileName;
		std::string strDstDir;
	};

	class BackupEnvironment : public leveldb::EnvWrapper
	{
	public:
		typedef std::vector<std::string> CollectionWillDeleteFilesT;

	public:
		explicit BackupEnvironment(leveldb::Env * pEnv)
			: EnvWrapper(pEnv)
			, m_bBackuping(FALSE)
		{

		}

	public:
		virtual Status Backup(const std::string & strDir , void * arg);
		virtual Status DeleteFile(const std::string & strFile);
		virtual bool   CheckCopyFile(const std::string& strName);
		virtual bool   CanCopyFile(const std::string& strName);
		virtual Status CopyFile(void * arg , const std::string & strFile , int64_t llFileLength);
		virtual Status CopyFile(const std::string& strSrc,const std::string& strDst,int64_t llFileLength );
		virtual Status LinkFile(const std::string & strSrc , const std::string & strDst);
 
	protected:
		BOOL						 m_bBackuping;		//5 �Ƿ����ڱ���,����ɾ���ļ�֮��
		leveldb::port::Mutex		 m_objMutex;
		CollectionWillDeleteFilesT	 m_vecWillDeleteFiles;
	};
}

#endif