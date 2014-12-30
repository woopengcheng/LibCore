#ifndef __protobuf_generate_generate_cpp_h__
#define __protobuf_generate_generate_cpp_h__

#include "Common.h"  
#include "GenerateBase.h"

namespace ProtobufGenerate
{
	class GenerateCPP : public GenerateBase
	{
	public:
		virtual UINT32 Init(google::protobuf::DescriptorPool & objPool , std::string strInputFile , std::string strOutputFile , std::string strNamespace);
		virtual UINT32 Cleanup();
		virtual UINT32 Generate();

	private:
		BOOL  GenerateMsgDefines();        //5 �����ļ�,�������е���ϢID.
		BOOL  GenerateMsgProcess();        //5 ����ÿ����Ϣ��Ӧ�Ĵ����ļ�.ÿ����Ϣ����һ��Process.
		BOOL  GenerateMsgHandlerHeader();  //5 �����ļ�.������ϢID�ҵ���Ӧ����Ϣ������process.
		BOOL  GenerateMsgHandlerSource();  //5 �����ļ�.msgHandler��ʵ���ļ�.
	};

}

#endif