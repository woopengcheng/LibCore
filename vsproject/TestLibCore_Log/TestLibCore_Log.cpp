// TestNetLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"  
#include "LogLib/inc/Log.h" 

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
	// 	google::SetStderrLogging(google::INFO); //5 设置级别高于INFO的输出到屏幕
	// 	FLAGS_logbufsecs = 0;                   //5 缓冲日志输出，默认为30秒，此处改为立即输出
	// 	FLAGS_max_log_size = 100;               //5 最大日志大小为 100MB
	// 	FLAGS_stop_logging_if_full_disk = true; //5 当磁盘被写满时，停止日志输出
	// 	FLAGS_colorlogtostderr = true;          //5 设置输出到屏幕的日志显示相应颜色
	// 
	// 	google::SetLogDestination(google::GLOG_ERROR, "./logs/ses_2014-08-27_error.log");
	// 	google::SetLogDestination(google::GLOG_ERROR, "./logs/ses_2014-08-27_errorw.log");
	// 	LOG(ERROR)<<"test";

	return 0;
}

