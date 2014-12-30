#ifndef __log_log4cplus_adaptee_h__
#define __log_log4cplus_adaptee_h__ 
#include "log4cplus/logger.h"
#include "LogAdapter.h"
 
namespace Log
{    
	/***********************************************************************
	��1��"%%"��ת��Ϊ% ��
	��2��"%c"�����logger���ƣ���test.subtest ��Ҳ���Կ���logger���Ƶ���ʾ��Σ�����"%c{1}"ʱ���"test"���������ֱ�ʾ��Ρ�
	��3��"%D"����ʾ����ʱ�䣬���磺"2004-10-16 18:55:45"��%d��ʾ��׼ʱ�䡣     ����ͨ��%d{...}�������ϸ����ʾ��ʽ������%d{%H:%M:%s}��ʾҪ��ʾСʱ:���ӣ��롣�������п���ʾ��
		Ԥ�����ʶ�����£�

		%a -- ��ʾ��ݼ���Ӣ����д��ʽ������"Fri"
		%A -- ��ʾ��ݼ�������"Friday"
		%b -- ��ʾ���·ݣ�Ӣ����д��ʽ������"Oct"
		%B -- ��ʾ���·ݣ�"October"
		%c -- ��׼�����ڣ�ʱ���ʽ���� "Sat Oct 16 18:56:19 2004"
		%d -- ��ʾ����������µļ���(1-31)"16"
		%H -- ��ʾ��ǰʱ���Ǽ�ʱ(0-23)���� "18"
		%I -- ��ʾ��ǰʱ���Ǽ�ʱ(1-12)���� "6"
		%j -- ��ʾ��������һ��(1-366)���� "290"
		%m -- ��ʾ��������һ��(1-12)���� "10"
		%M -- ��ʾ��ǰʱ������һ����(0-59)���� "59"
		%p -- ��ʾ���������绹�����磬 AM or PM
		%q -- ��ʾ��ǰʱ���к��벿��(0-999)���� "237"
		%Q -- ��ʾ��ǰʱ���д�С���ĺ��벿��(0-999.999)���� "430.732"
		%S -- ��ʾ��ǰʱ�̵Ķ�����(0-59)���� "32"
		%U -- ��ʾ�����ǽ���ĵڼ�����ݣ�������Ϊ��һ�쿪ʼ����(0-53)���� "41"
		%w -- ��ʾ��ݼ���(0-6, �����Ϊ0)���� "6"
		%W -- ��ʾ�����ǽ���ĵڼ�����ݣ�����һΪ��һ�쿪ʼ����(0-53)���� "41"
		%x -- ��׼�����ڸ�ʽ���� "10/16/04"
		%X -- ��׼��ʱ���ʽ���� "19:02:34"
		%y -- ��λ�������(0-99)���� "04"
		%Y -- ��λ������ݣ��� "2004"
		%Z -- ʱ���������� "GMT"

	��4��"%F"�������ǰ��¼�����ڵ��ļ����ƣ�����"main.cpp"
	��5��"%L"�������ǰ��¼�����ڵ��ļ��кţ�����"51"
	��6��"%l"�������ǰ��¼�����ڵ��ļ����ƺ��кţ�����"main.cpp:51"
	��7��"%m"�����ԭʼ��Ϣ��
	��8��"%n"�����з���
	��9��"%p"�����LogLevel������"DEBUG"
	��10��"%t"�������¼�����ڵ��߳�ID������ "1075298944"
	��11��"%x"��Ƕ�����������NDC (nested diagnostic context) ������Ӷ�ջ�е�����������Ϣ��NDC�����öԲ�ͬԴ��log��Ϣ��ͬʱ�أ���������������֡�
	��12����ʽ���룬����"%-10m"ʱ��ʾ����룬�����10����Ȼ�����Ŀ����ַ�Ҳ������ͬ�ķ�ʽ��ʹ�ã�����"%-12d"��"%-5p"�ȵȡ�
	************************************************************************/

	class DLL_EXPORT Log4CPlusAdaptee : public LogAdapter
	{
	public:
		Log4CPlusAdaptee() {}
		virtual ~Log4CPlusAdaptee(){} 

	public: 
		virtual  UINT32  Init(const char * pLogName , const char * pLayoutConfig = NULL , BOOL bMultCategory = TRUE) ; 
		virtual  UINT32  Cleanup(); 

	public:
		virtual  void    Debug( std_ostream & os ); 
		virtual  void    Error( std_ostream & os); 
		virtual  void    Warning( std_ostream & os); 
		virtual  void    Trace( std_ostream & os); 
		virtual  void    Other( std_ostream & os); 

	public: 
		virtual  UINT32				CreateLog(const char * pName , const char * pLayoutConfig , const char * pFile);
//		virtual  log4cplus::Logger  GetLog(LOG_TYPE logType);  
	};

} 
#endif