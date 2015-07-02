#include "MasterHandler.h"
#include "leveldb/env.h"
#include <fstream>
#include "RPCCallFuncs.h"

namespace Server
{  



	void MasterHandler::StartSyncToSlave(std::string strDBDir)
	{
		std::vector<std::string> files;
		GameDB::GetDefaultEnv()->GetChildren(strDBDir,&files);

		int nType = 1;  
		std::vector<Msg::Object> vecTargets;
		vecTargets.push_back(Msg::Object(1));

		rpc_MasterStartSync("tcp://127.0.0.1:9002" , "" , nType , nType , LibCore::Chunk() ,  vecTargets , GetObjectID());

		for(size_t i = 0; i < files.size(); ++i)
		{
			const std::string& filename = files[i];
			if(filename == "." || filename == "..")
				continue;

			SendFile(strDBDir + "/" + filename,filename);
		}

		nType = 2;
		rpc_MasterStartSync("tcp://127.0.0.1:9002" , "" , nType , nType , LibCore::Chunk() ,  vecTargets , GetObjectID());
	}

	bool MasterHandler::SendFile(const std::string & strFilePath , const std::string & strFileName)
	{
		static const size_t cst_buffer_size = 1*1024*1024;

		std::fstream fs;
		fs.open(strFilePath.c_str(),std::ios_base::in | std::ios_base::binary);
		if(!fs.good())
			return false;

		fs.seekg(0,std::ios_base::end);
		INT32 filesize = fs.tellg();
		fs.seekg(0,std::ios_base::beg);

		char* tmpbuf = new char[cst_buffer_size]; 

		while(filesize > 0)
		{
			size_t size = __min(filesize,cst_buffer_size);
			fs.read(tmpbuf,size);
			filesize -= size;

			std::vector<Msg::Object> vecTargets;
			vecTargets.push_back(Msg::Object(1));

			int nType = 0; 
			rpc_MasterStartSync("tcp://127.0.0.1:9002" , strFileName , filesize , nType , LibCore::Chunk(tmpbuf , size) ,  vecTargets , GetObjectID());
			
			gDebugStream("send file:" << strFileName << "send size: " << size );
		}

		delete [] tmpbuf;

		return filesize == 0;

	}

}