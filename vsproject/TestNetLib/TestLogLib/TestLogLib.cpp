// TestNetLib.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"  
#include "Log.h"
#include "glog/logging.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	Log::LogInterface::GetInstance().Init("ses" , NULL , 0);
	gDebugStream("asdfadf");
	gErrorStream("asdfadf");
	gWarniStream("asdfadf");
  	gTraceStream("asdfadf"); 
  	gOtherStream("asdfadf"); 
    Log::LogInterface::GetInstance().Cleanup();


// 	google::InitGoogleLogging("asdf"); 
// 	google::SetStderrLogging(google::INFO); //5 ���ü������INFO���������Ļ
// 	FLAGS_logbufsecs = 0;                   //5 ������־�����Ĭ��Ϊ30�룬�˴���Ϊ�������
// 	FLAGS_max_log_size = 100;               //5 �����־��СΪ 100MB
// 	FLAGS_stop_logging_if_full_disk = true; //5 �����̱�д��ʱ��ֹͣ��־���
// 	FLAGS_colorlogtostderr = true;          //5 �����������Ļ����־��ʾ��Ӧ��ɫ
// 
// 	google::SetLogDestination(google::GLOG_ERROR, "./logs/ses_2014-08-27_error.log");
// 	google::SetLogDestination(google::GLOG_ERROR, "./logs/ses_2014-08-27_errorw.log");
// 	LOG(ERROR)<<"test";

	return 0;
}

