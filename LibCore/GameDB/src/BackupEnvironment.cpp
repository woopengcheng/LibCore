#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include "GameDB/inc/BackupEnvironment.h"
#include "filename.h"

namespace GameDB
{ 

	Status BackupEnvironment::DeleteFile(const std::string & strFile)
	{
		m_objMutex.Lock();

		Status s;
		if (m_bBackuping)
		{
			m_vecWillDeleteFiles.push_back(strFile);
		}
		else
		{
			s = target()->DeleteFile(strFile);
		}

		m_objMutex.Unlock();

		return s;  
	}

	bool BackupEnvironment::CheckCopyFile(const std::string& strName)
	{
		uint64_t llNumber = 0;
		leveldb::FileType objType;
		leveldb::ParseFileName(strName , &llNumber , &objType);
	
		if (objType != leveldb::kTableFile && objType != leveldb::kDBLockFile)
		{
			return true;
		}

		return false;	
	}

	bool BackupEnvironment::CanCopyFile(const std::string& strName)
	{
		uint64_t llNumber = 0;
		leveldb::FileType objType;
		leveldb::ParseFileName(strName , &llNumber , &objType);

		switch(objType)
		{
		case leveldb::kCurrentFile:
		case leveldb::kDescriptorFile:
		case leveldb::kInfoLogFile:
		case leveldb::kLogFile:
		case leveldb::kTableFile: 
			return true;
		}

		return false;
	}
 
	Status BackupEnvironment::LinkFile(const std::string & strSrc , const std::string & strDst)
	{  
#ifdef WIN32 
		if(CreateHardLinkA(strDst.c_str(),strSrc.c_str(),NULL))
			return leveldb::Status::OK();
		return leveldb::Status::IOError("CreateHardLinkA");
#else
		if(link(strSrc.c_str(),strDst.c_str()) == 0)
			return leveldb::Status::OK();
		return leveldb::Status::IOError("link");
#endif
	}

	Status BackupEnvironment::Backup(const std::string & strDir , void * arg)
	{ 
		m_objMutex.Lock();
		std::vector<std::string> vecFiles;
		Status objStatus = GetChildren(strDir , &vecFiles);
		if (!objStatus.ok())
		{
			m_objMutex.Unlock();
			return objStatus;
		}

		//5 这里保证一样的长度是为了后面真正的copy
		std::vector<int64_t> vecFileLengths(vecFiles.size());
		for (size_t i = 0 ;i < vecFiles.size() ; ++i )
		{
			if (vecFiles[i] == "." || vecFiles[i] == "..")
			{
				continue;
			}

			if (CheckCopyFile(vecFiles[i]))
			{
				uint64_t llLength = 0;
				objStatus = GetFileSize(vecFiles[i] , &llLength);
				if (!objStatus.ok())
				{
					m_objMutex.Unlock();
					return objStatus;
				} 
				vecFileLengths[i] = (int64_t)llLength;
			}
			else
			{
				vecFileLengths[i] = -1;
			}
		}  
		m_bBackuping = TRUE;
		m_objMutex.Unlock();

		//5 copy开始
		for (size_t i = 0;i < vecFiles.size();++i)
		{
			if (CanCopyFile(vecFiles[i]))
			{
				objStatus = this->CopyFile(arg , vecFiles[i] , vecFileLengths[i]);
				if (!objStatus.ok())
				{
					break;
				} 
			}
		}

		//5 万一备份时有删除文件.这里将删除.
		m_objMutex.Lock();
		m_bBackuping = FALSE;
		for (size_t i = 0;i < m_vecWillDeleteFiles.size();++i)
		{
			this->target()->DeleteFile(m_vecWillDeleteFiles[i]);
		}
		m_vecWillDeleteFiles.clear();
		m_objMutex.Unlock();

		return objStatus;
	}

	Status BackupEnvironment::CopyFile(void * arg , const std::string & strFile , int64_t llFileLength)
	{
		SBackupDB * pBackup = (SBackupDB * )arg;

		std::string strSrc = pBackup->strSrcDir + "/" + strFile;
		std::string strDst = pBackup->strDstDir + "/" + pBackup->strDstFileName + strFile; 
		
		Status objStatus;
		if (llFileLength == -1)
		{
			objStatus = LinkFile(strSrc , strDst);
		}
		else
		{
			objStatus = CopyFile(strSrc , strDst , llFileLength);
		}
	
		return objStatus;
	}

	Status BackupEnvironment::CopyFile( const std::string& strSrc,const std::string& strDst,int64_t llFileLength )
	{
		leveldb::WritableFile * pWriteFile = NULL;
		leveldb::SequentialFile * pReadFile = NULL;
		Status objStatus;

		objStatus = target()->NewSequentialFile(strSrc , &pReadFile);
		if (!objStatus.ok())
		{
			return objStatus;
		} 

		objStatus = target()->NewWritableFile(strDst , &pWriteFile);
		if (!objStatus.ok())
		{
			SAFE_DELETE(pWriteFile);
			return objStatus;
		} 

		char * pTmpBuf = new char[MAX_DB_TEMP_BUFFER_LENGTH];

		size_t bytes = MAX_DB_TEMP_BUFFER_LENGTH;
		while(true)
		{
			if (llFileLength != -1)
			{
				bytes = __min(llFileLength , MAX_DB_TEMP_BUFFER_LENGTH);
			}

			leveldb::Slice slice;
			objStatus = pReadFile->Read(bytes , &slice , pTmpBuf);
			if(!objStatus.ok())
				break;

			if(slice.size() == 0)
				break;

			objStatus = pWriteFile->Append(slice);
			if(!objStatus.ok())
				break;

			if (llFileLength > 0)
			{
				llFileLength -= bytes;
			}

			if (llFileLength == 0)
			{
				break;
			}
		}


	}
}