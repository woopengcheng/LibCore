#ifndef __timer_timer_common_h__
#define __timer_timer_common_h__
#include "Common/Common.h"

#ifdef WIN32
#include <Windows.h>
#else 
#endif

#define TIME_PRECISE 1000                     //5 定义精确级别为微妙.
 
#define DEFAULT_TIMER_THREAD_ID 1             //5 默认计时器中心ID.
#define DEFAULT_TIMER_HANDLE_THREAD_ID 2      //5 默认计时器处理ID

typedef INT64 TimerType;

typedef void (*TimerCallBackFunc)(void * pObj , UINT32 unTimerID , UINT32 unRemainTimes ); 

#endif