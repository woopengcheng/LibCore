#ifndef __log_log_adapter_h__
#define __log_log_adapter_h__
#include "LogCommon.h"

namespace Log
{
	class DLL_EXPORT LogAdapter
	{
	public:
		LogAdapter(){}
		virtual ~LogAdapter(){}
		 
	public: 
		virtual  UINT32  Init(const char * pLogName , const char * pLayoutConfig = NULL , BOOL bMultCategory = TRUE) { return FALSE; }
		virtual  UINT32  Cleanup(){ return FALSE; }

	public:
		static LogAdapter & GetInstance(){ static LogAdapter m_sLogAdapter; return m_sLogAdapter; }

	public:
		virtual  void    Debug( std_ostream & os){} 
		virtual  void    Error( std_ostream & os){}
		virtual  void    Warning( std_ostream & os){} 
		virtual  void    Trace( std_ostream & os){}
		virtual  void    Other( std_ostream & os){}

	protected:
		BOOL     m_bMultCategory;
	}; 
} 
#endif 