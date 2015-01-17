#ifndef __timer_timer_help_h__
#define __timer_timer_help_h__ 
#include "TimerLib/inc/TimerCommon.h"

namespace Timer
{  
	class DLL_EXPORT TimerHelper
	{
	public:  
		static INT64  GetTickCount();                 //5 获得CPU的时钟频率启动后的次数,如果除以频率的速度.就可以得到毫秒
		static INT64  GetTickFrequency();             //5 CPU频率.
		static INT64  GetTickSecond(INT64 llTime = -1);              //5 获取CPU运行的时间(秒)
		static INT64  GetTickMicroSecond(INT64 llTime = -1);         //5 获取CPU运行的时间(毫秒)
		static INT64  GetTickMilliSecond(INT64 llTime = -1);         //5 获取CPU运行的时间(微妙) 

		static INT64  GetMilliSecond(INT64 llTime); //5 获得微妙
		static INT64  GetMicroSecond(INT64 llTime); //5 获得毫秒 
		static INT64  GetSecond(INT64 llTime);      //5 获得秒  

		static INT64  DiffMilliSecond(INT64 llTime1 , INT64 llTime2);  //5 比较两个毫秒的差异
		static INT64  DiffMicroSecond(INT64 llTime1 , INT64 llTime2);  //5 比较两个毫秒的差异
		static INT64  DiffSecond(INT64 llTime1 , INT64 llTime2);       //5 比较两个秒的差异
		
		/*
			%a 星期几的缩写。Eg:Tue 
			%A 星期几的全名。 Eg: Tuesday
			%b 月份名称的缩写。 
			%B 月份名称的全名。 
			%c 本地端日期时间较佳表示字符串。 
			%d 用数字表示本月的第几天 (范围为 00 至 31)。日期
			%H 用 24 小时制数字表示小时数 (范围为 00 至 23)。 
			%I 用 12 小时制数字表示小时数 (范围为 01 至 12)。 
			%j 以数字表示当年度的第几天 (范围为 001 至 366)。 
			%m 月份的数字 (范围由 1 至 12)。
			%M 分钟。 
			%p 以 ''AM'' 或 ''PM'' 表示本地端时间。 
			%S 秒数。 
			%U 数字表示为本年度的第几周，第一个星期由第一个周日开始。 
			%W 数字表示为本年度的第几周，第一个星期由第一个周一开始。 
			%w 用数字表示本周的第几天 ( 0 为周日)。 
			%x 不含时间的日期表示法。 
			%X 不含日期的时间表示法。 Eg: 15:26:30
			%y 二位数字表示年份 (范围由 00 至 99)。 
			%Y 完整的年份数字表示，即四位数。 Eg:2008
			%Z(%z) 时区或名称缩写。Eg:中国标准时间 */
		static std::string GetDate(std::string strFormat = "%Y-%m-%d");

		static  void   sleep(INT64 llMillSec);
	};
}
#endif