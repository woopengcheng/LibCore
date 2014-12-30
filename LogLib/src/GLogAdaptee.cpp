#include "GLogAdaptee.h"
#include "TimerHelp.h"
#include "glog/raw_logging.h"
#include "glog/logging.h"

namespace Log
{ 
	UINT32 GLogAdaptee::Init( const char * pLogName , const char * pLayoutConfig /*= NULL */, BOOL bMultCategory /*= TRUE*/ )
	{
		google::InitGoogleLogging("./"); 
 		google::SetStderrLogging(0); //5 ���ü������INFO���������Ļ
		FLAGS_logbufsecs = 0;                   //5 ������־�����Ĭ��Ϊ30�룬�˴���Ϊ�������
		FLAGS_max_log_size = 1024;              //5 �����־��СΪ 100MB
		FLAGS_stop_logging_if_full_disk = true; //5 �����̱�д��ʱ��ֹͣ��־���
		FLAGS_colorlogtostderr = true;          //5 �����������Ļ����־��ʾ��Ӧ��ɫ
 		FLAGS_v = 3;                         //5 �Զ�����־���

		std::string strFileName = "";

		int nResult = 0;
#ifdef WIN32
		nResult = _mkdir("./logs");
#else
		nResult = mkdir("./logs",S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
#endif 
		strFileName = "./logs/"; 
		strFileName += pLogName;
		strFileName += "_";

		strFileName += Timer::TimerHelper::GetDate();

		m_bMultCategory = bMultCategory;
		if (bMultCategory)
		{	
			CreateLog(LOG_ALL_TYPE , pLayoutConfig , (strFileName + "_" + g_strLogTypeName[LOG_ALL_TYPE] + ".log").c_str()); 
		}
		else
		{
			for (int i = 0;i < MAX_LOG_TYPE - 1;++i)
			{
				CreateLog((LOG_TYPE)i , pLayoutConfig , (strFileName + "_" + g_strLogTypeName[i] + ".log").c_str()); 
			}
		}  
		return TRUE;
	}

	UINT32 GLogAdaptee::Cleanup()
	{
		return TRUE;
	}

	void GLogAdaptee::Debug( std_ostream & os )
	{   
//		LOG(INFO , os.str().c_str()); 
		RAW_VLOG(LOG_DEBUG , os.str().c_str()); 
	}

	void GLogAdaptee::Error( std_ostream & os )
	{  
		RAW_VLOG(LOG_ERROR , os.str().c_str()); 
	}

	void GLogAdaptee::Warning( std_ostream & os )
	{ 
		RAW_VLOG(LOG_WARNING , os.str().c_str()); 
	}

	void GLogAdaptee::Trace( std_ostream & os )
	{
		RAW_VLOG(LOG_TRACE , os.str().c_str()); 
	}

	void GLogAdaptee::Other( std_ostream & os )
	{
//		RAW_VLOG(LOG_OTHERS , os.str().c_str());
	}

	UINT32 GLogAdaptee::CreateLog( LOG_TYPE objLogType , const char * pLayoutConfig , const char * pFile )
	{ 
		switch(objLogType)
		{
			case LOG_ALL_TYPE:
				{ 
					google::SetLogDestination(LOG_ERROR, pFile);
					google::SetLogDestination(LOG_WARNING, pFile);
					google::SetLogDestination(LOG_DEBUG, pFile);
					google::SetLogDestination(LOG_TRACE, pFile); 
					google::SetLogDestination(LOG_OTHERS, pFile);
				}break;
			case LOG_DEBUG:
				google::SetLogDestination(LOG_DEBUG, pFile);
				break; 
			case LOG_ERROR:
				google::SetLogDestination(LOG_ERROR, pFile);
				break; 
			case LOG_WARNING:
				google::SetLogDestination(LOG_WARNING, pFile);
				break; 
			case LOG_TRACE:
				google::SetLogDestination(LOG_TRACE, pFile); 
				break;
			case LOG_OTHERS:
//				google::SetLogDestination(LOG_OTHERS, pFile);
				break;
			default:
				break; 
		} 

		return TRUE;
	}

}