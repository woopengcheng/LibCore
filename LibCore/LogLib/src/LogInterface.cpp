#include "LogInterface.h" 

#ifdef USE_LOG4CPP
#include "Log4CppAdaptee.h"
#elif defined USE_LOG4CPLUS
#include "Log4CPlusAdaptee.h"
#elif defined USE_GLOG
#include "GLogAdaptee.h"
#endif

namespace Log
{   
	std::string g_strLogTypeName[MAX_LOG_TYPE] = {"debug" , "error" , "warning" , "trace" , "others" , "all"};

	LogInterface::LogInterface()
	{
#ifdef USE_LOG4CPP
		m_pLogAdapter = new Log4CppAdaptee; 
		std::cout << "USE_LOG4CPP"<<std::endl;
#elif defined USE_LOG4CPLUS
		m_pLogAdapter = new Log4CPlusAdaptee;
		std::cout << "USE_LOG4CPLUS"<<std::endl;
#elif defined USE_GLOG
		m_pLogAdapter = new GLogAdaptee;
		std::cout << "USE_GLOG"<<std::endl;
#endif

	}

	INT32 LogInterface::Init( const char * pLogName , const char * pLayoutConfig /*= NULL */, BOOL bMultCategory /*= TRUE*/ )
	{
		if (m_pLogAdapter)
		{
			return m_pLogAdapter->Init(pLogName , pLayoutConfig , bMultCategory);
		}
		return -1;
	}

	INT32 LogInterface::Cleanup()
	{
		if (m_pLogAdapter)
		{ 
			m_pLogAdapter->Cleanup();
			SAFE_DELETE(m_pLogAdapter);
			return 0;
		}
		return  -1;
	} 

	UINT32  Init(const char * pLogName , const char * pLayoutConfig  , BOOL bMultCategory ) 
	{ 
		return LogInterface::GetInstance().Init(pLogName , pLayoutConfig , bMultCategory);
	}

	UINT32  Cleanup()
	{
		return Log::LogInterface::GetInstance().Cleanup(); 
	}
}