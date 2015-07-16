#include "MasterHandler.h"
#include "leveldb/env.h"
#include <fstream>
#include "RPCCallFuncs.h"
#include "SlaveRecord.h"

namespace Server
{  
	void MasterHandler::StartSyncToSlave(std::string strDBDir)
	{
		std::vector<std::string> files;
		GameDB::GetDefaultEnv()->GetChildren(strDBDir,&files);

		INT32 nType = 1;  		 
		rpc_MasterStartSync("tcp://127.0.0.1:9002" , m_pRpcMsgCall->GetProxySrcID() , GetObjectID() , std::string() , nType , nType , LibCore::Chunk());

		for(size_t i = 0; i < files.size(); ++i)
		{
			std::string& filename = files[i];
			if(filename == "." || filename == "..")
				continue;

			SendFile(strDBDir + "/" + filename,filename);
		}

		nType = 2;
		rpc_MasterStartSync("tcp://127.0.0.1:9002" , m_pRpcMsgCall->GetProxySrcID() , GetObjectID() , std::string() , nType , nType , LibCore::Chunk());
	}

	bool MasterHandler::SendFile(const std::string & strFilePath , std::string & strFileName)
	{
		static const size_t cst_buffer_size = 1*1024*1024;

		std::fstream fs;
		fs.open(strFilePath.c_str(),std::ios_base::in | std::ios_base::binary);
		if(!fs.good())
			return false;

		fs.seekg(0,std::ios_base::end);
		INT64 filesize = (INT64)fs.tellg();
		fs.seekg(0,std::ios_base::beg);

		char* tmpbuf = new char[cst_buffer_size]; 

		while(filesize > 0)
		{
			size_t size = __min(filesize,cst_buffer_size);
			fs.read(tmpbuf,size);
			filesize -= (INT64)size; 

			INT32 nType = 0; 
			rpc_MasterStartSync("tcp://127.0.0.1:9002" , m_pRpcMsgCall->GetProxySrcID() , GetObjectID() , strFileName , (INT32)filesize , nType , LibCore::Chunk(tmpbuf , (UINT32)size));
			
			gDebugStream("send file:" << strFileName << "send size: " << size );
		}

		delete [] tmpbuf;

		return filesize == 0;

	}

	void MasterHandler::CreateSlaveRecord(Msg::Object id , GameDB::User & objUser)
	{
		SlaveRecord * pRecord = new SlaveRecord(this);
		if (pRecord)
		{
			GameDB::UserAuth objAuth(objUser);
			pRecord->SetUserAuth(objAuth);

			m_mapSlaveRecords.insert(std::make_pair(id , pRecord));
		}


	}

	MasterHandler::~MasterHandler()
	{
		CollectionSlaveRecordsT::iterator iter = m_mapSlaveRecords.begin();
		for (;iter != m_mapSlaveRecords.end();++iter)
		{
			SAFE_DELETE(iter->second);
		}
		m_mapSlaveRecords.clear();
	}

	SlaveRecord * MasterHandler::GetSlaveRecord(Msg::Object id)
	{
		CollectionSlaveRecordsT::iterator iter = m_mapSlaveRecords.find(id);
		if (iter != m_mapSlaveRecords.end())
		{
			return iter->second;
		}

		return NULL;
	}

}