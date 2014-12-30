#include "TimerHelp.h"
#include "Log4CppAdaptee.h" 

#ifdef WIN32
#include <direct.h>
#else
#endif

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/TimeStamp.hh>
#include <log4cpp/FileAppender.hh>

namespace Log
{ 
	UINT32 Log4CppAdaptee::Init( const char * pLogName , const char * pLayoutConfig , BOOL bMultCategory /* = FALSE*/)
	{
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
		if (m_bMultCategory)
		{	
			CreateLog(g_strLogTypeName[LOG_ALL_TYPE].c_str() , pLayoutConfig , (strFileName + "_" + g_strLogTypeName[LOG_ALL_TYPE] + ".log").c_str()); 
		}
		else
		{
			for (int i = 0;i < MAX_LOG_TYPE - 1;++i)
			{
				CreateLog(g_strLogTypeName[i].c_str() , pLayoutConfig , (strFileName + "_" + g_strLogTypeName[i] + ".log").c_str()); 
			}
		}
		 
		return 0;
	}
	 
	UINT32 Log4CppAdaptee::CreateLog( const char * pName , const char * pLayoutConfig , const char * pFile )
	{
		if (pName == NULL)
		{
			return 0;
		}

		//Log4cpp���ڴ����Զ��ͷŵ�.

		//5 1.����layout,�������ȶ���Layout�ĸ�ʽ.
		log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
		if (pLayoutConfig == NULL)
		{
			pLayout->setConversionPattern("%d [%t] %p - %m%n");
		}
		else
			pLayout->setConversionPattern(pLayoutConfig);

		//5 2.��������Layout��appender.�����������ʾ������ʲô��ʽ���д洢.������ʽ.sys����.Զ�̷���.�ļ��ȵ�.
#ifdef _DEBUG
		log4cpp::Appender * pAppender =  new log4cpp::OstreamAppender("osAppender", &std::cout);
#else
		log4cpp::Appender * pAppender =  new log4cpp::FileAppender("FileAppender", pFile); 
#endif
		pAppender->setLayout(pLayout);

		//5 3.����Categteoy������װAppender.
		log4cpp::Category & objCategory = log4cpp::Category::getInstance(pName);
		objCategory.setAdditivity(false);                      //5 �滻���е�appender.
		objCategory.setAppender(pAppender);
		objCategory.setPriority(log4cpp::Priority::DEBUG);     //5 ��debug���ȼ����ϵĶ�Ҫ�洢

		return 0;
	} 

	UINT32 Log4CppAdaptee::Cleanup()
	{
		log4cpp::Category::shutdown(); 
		return 0;
	}
 	// 
 	//log4cpp::CategoryStream  Log4CppInterface::GetLog( LOG_TYPE logType)
 	//{ 
 	//	int nPriority = 0;
 
 	//	if (logType == LOG_DEBUG)
 	//	{
 	//		nPriority = log4cpp::Priority::DEBUG; 
 	//	}
 	//	else if (logType == LOG_ERROR)
 	//	{
 	//		nPriority = log4cpp::Priority::ERROR; 
 	//	}
 	//	else if (logType == LOG_WARNING)
 	//	{
 	//		nPriority = log4cpp::Priority::WARN; 
 	//	}
 	//	else if (logType == LOG_OTHERS)
 	//	{
 	//		nPriority = log4cpp::Priority::INFO; 
 	//	} 
 	//	else if(logType == LOG_TRACE)
 	//	{
 	//		nPriority = log4cpp::Priority::INFO; 
 	//	} 
 	//	
 	//	if (m_bMultCategory)
		//{
 	//		logType = LOG_ALL_TYPE;
		//} 
 	//	 
 	//	return log4cpp::Category::getInstance(g_strLogTypeName[logType].c_str()).getStream(nPriority);    
 	//} 

	void Log4CppAdaptee::Debug( std_ostream & os )
	{
		log4cpp::Category::getInstance(g_strLogTypeName[LOG_DEBUG].c_str()).getStream(log4cpp::Priority::DEBUG)<<os.str(); 
	}

	void Log4CppAdaptee::Error( std_ostream & os )
	{
		log4cpp::Category::getInstance(g_strLogTypeName[LOG_ERROR].c_str()).getStream(log4cpp::Priority::ERROR)<<os.str(); 
	}

	void Log4CppAdaptee::Warning( std_ostream & os )
	{
		log4cpp::Category::getInstance(g_strLogTypeName[LOG_WARNING].c_str()).getStream(log4cpp::Priority::WARN)<<os.str(); 
	}

	void Log4CppAdaptee::Trace( std_ostream & os )
	{
		log4cpp::Category::getInstance(g_strLogTypeName[LOG_TRACE].c_str()).getStream(log4cpp::Priority::INFO)<<os.str(); 
	}

	void Log4CppAdaptee::Other( std_ostream & os )
	{
		log4cpp::Category::getInstance(g_strLogTypeName[LOG_OTHERS].c_str()).getStream(log4cpp::Priority::INFO)<<os.str(); 
	} 
}