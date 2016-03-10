#include "Timer/inc/TimerHelp.h"
#include "Timer/inc/GlobalTimer.h"
#include "Timer/inc/TimingWheel.h"

#ifdef WIN32
#include <windows.h>
#endif

namespace Timer
{  
#ifdef WIN32
	INT64 GetTickCount()
	{  
		INT64  llCount = 0;
		QueryPerformanceCounter((LARGE_INTEGER *)(&llCount));

		return llCount;
	}

	INT64 GetTickFrequency()
	{
		static INT64  s_llFrequency = 0;
		if (!s_llFrequency)
		{
			QueryPerformanceFrequency((LARGE_INTEGER *)(&s_llFrequency));
		}

		return s_llFrequency;
	} 
#else
	INT64 GetTickCount()
	{ 
		timespec t;
		::clock_gettime(CLOCK_MONOTONIC,&t);              //5 CLOCK_REALTIME不同.这个是过去的某个逝去的时间点的次数.
		return (INT64)t.tv_sec * TIME_PRECISE + t.tv_nsec / (1e9 / TIME_PRECISE);   //5 微妙级别

		return llCount;
	}

	INT64 GetTickFrequency()
	{  
		return TIME_PRECISE;
	}  
#endif

	INT64 GetTickSecond(INT64 llTime /*= -1*/ )
	{
		if (llTime == -1)
		{
			return  GetTickCount() / GetTickFrequency(); 
		} 
		else
		{
			return  llTime / GetTickFrequency(); 
		}
	}

	INT64 GetTickMicroSecond( INT64 llTime /*= -1*/ )
	{
		if (llTime == -1)
		{
			return  GetTickCount() * 1000  / GetTickFrequency(); 
		} 
		else
		{
			return  llTime * 1000  / GetTickFrequency(); 
		} 
	}

	INT64 GetTickMilliSecond( INT64 llTime /*= -1*/ )
	{
		if (llTime == -1)
		{
			return  GetTickCount() * 1000000 / GetTickFrequency(); 
		} 
		else
		{
			return  llTime * 1000000 / GetTickFrequency(); 
		} 
	}

	INT64 GetMilliSecond( INT64 llTime )
	{
		return llTime * GetTickFrequency() / 1000000;

	}

	INT64 GetMicroSecond( INT64 llTime )
	{
		return llTime * GetTickFrequency() / 1000;
	}

	INT64 GetSecond( INT64 llTime )
	{
		return llTime * GetTickFrequency();
	}

	INT64 DiffMilliSecond( INT64 llTime1 , INT64 llTime2 )
	{
		return (llTime1 - llTime2) * 1000000 / GetTickFrequency(); 
	}

	INT64 DiffMicroSecond( INT64 llTime1 , INT64 llTime2 )
	{
		return (llTime1 - llTime2) * 1000 / GetTickFrequency(); 

	}

	INT64 DiffSecond( INT64 llTime1 , INT64 llTime2 )
	{
		return (llTime1 - llTime2) / GetTickFrequency(); 
	}

	std::string GetDate(std::string strFormat/* = "%Y-%m-%d"*/)
	{
		time_t t = time(0); 
		char tmp[64]; 
		strftime( tmp, sizeof(tmp), strFormat.c_str(),localtime(&t) );  
		return std::string(tmp); 
	}

	time_t GetTime()
	{
		return time(0);
	}

	void sleep(INT64 llMillSec)
	{
#ifdef WIN32
		::Sleep((DWORD)llMillSec);
#else  
		struct timespec objTimeSpec;
		objTimeSpec.tv_sec = llMillSec / 1000;
		objTimeSpec.tv_nsec = (llMillSec % 1000) * 1000000L;
		::nanosleep (&objTimeSpec, 0);
#endif
	}

	INT32 GetCurTimingwheelPos(INT32 nFutureTime , INT32 & nWheelSize , INT32 & nTimerSize)
	{
		if (nFutureTime < 0)
		{
			nTimerSize = 0;
			nWheelSize = -1;
			return nWheelSize;
		}

		INT32 nPos = 0; 
		nFutureTime = nFutureTime << TIMER_ROOT_SIZE_MASK; 
		if ( nFutureTime < (1 << TIMER_ROOT_SIZE_MASK)) 
		{ 
			nTimerSize = nFutureTime % (1 << TIMER_ROOT_SIZE_MASK) ; 
			nWheelSize = 0;
			return nWheelSize;
		}

		INT32 nSize = 0;
		while(1)
		{
			nFutureTime = nFutureTime << TIMER_OTHER_SIZE_MASK;
			if (nFutureTime < (1 << TIMER_OTHER_SIZE_MASK))
			{
				nTimerSize = nFutureTime % (1 << TIMER_OTHER_SIZE_MASK) ; 
				break;
			} 
			++nSize;
		} 

		nWheelSize = nSize;

		return nWheelSize;
	} 

}