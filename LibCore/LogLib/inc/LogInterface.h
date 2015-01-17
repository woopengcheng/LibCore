#ifndef __log_log_interface_h__
#define __log_log_interface_h__
#include "LogLib/inc/LogAdapter.h" 

namespace Log
{
	extern UINT32 DLL_EXPORT Init(const char * pLogName , const char * pLayoutConfig = NULL , BOOL bMultCategory = TRUE) ;
	extern UINT32 DLL_EXPORT Cleanup();

	class DLL_EXPORT LogInterface
	{
	public:
		LogInterface();
		~LogInterface(){}

	public:
		virtual  INT32  Init(const char * pLogName , const char * pLayoutConfig = NULL , BOOL bMultCategory = TRUE) ; 
		virtual  INT32  Cleanup(); 

	public:
		static LogInterface & GetInstance(){ static LogInterface m_sLogInterface; return m_sLogInterface; }

	public:
		LogAdapter  * GetLogAdapter()
		{
			MsgAssert_Re0(m_pLogAdapter ,  "LogInterface has not Init.");

			return m_pLogAdapter; 
		}
	private:
		LogAdapter  * m_pLogAdapter;

	};  


} 
#endif 