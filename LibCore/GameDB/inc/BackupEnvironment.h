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

	class DLL_EXPORT BackupEnvironment : public leveldb::EnvWrapper
	{
	public:
		typedef std::vector<std::string> CollectionWillDeleteFilesT;

	public:
		BackupEnvironment()
			: EnvWrapper(leveldb::Env::Default())
			, m_bBackuping(FALSE)
		{

		}
		explicit BackupEnvironment(leveldb::Env * pEnv)
			: EnvWrapper(pEnv)
			, m_bBackuping(FALSE)
		{

		}
		virtual ~BackupEnvironment(){}

	public:
		virtual Status Backup(const std::string & strDir , void * arg);
		virtual Status DeleteFile(const std::string & strFile){ return RemoveFile(strFile); }
		virtual bool   CheckCopyFile(const std::string& strName);
		virtual bool   CanCopyFile(const std::string& strName);
		virtual Status CloneFile(void * arg , const std::string & strFile , int64_t llFileLength);
		virtual Status CloneFile(const std::string& strSrc,const std::string& strDst,int64_t llFileLength );
		virtual Status LinkFile(const std::string & strSrc , const std::string & strDst);
		virtual Status TouchFile(const std::string & strDir );
 
	public: 
		Status RemoveFile(const std::string & strFile);  //5 ���windows��DeleteFile����������

	protected:
		BOOL						 m_bBackuping;		//5 �Ƿ����ڱ���,����ɾ���ļ�֮��
		leveldb::port::Mutex		 m_objMutex;
		CollectionWillDeleteFilesT	 m_vecWillDeleteFiles;
	}; 
}

#endif