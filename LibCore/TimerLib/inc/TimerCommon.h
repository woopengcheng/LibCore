#ifndef __timer_timer_common_h__
#define __timer_timer_common_h__
#include "Common/Common.h"

#ifdef WIN32
#include <Windows.h>
#else 
#endif

#define MAX_NODE_SIZE 10000                   //5 ����100000����ʱ��.
#define TIME_PRECISE 1000                     //5 ���徫ȷ����Ϊ΢��.
 
#define DEFAULT_TIMER_THREAD_ID 1             //5 Ĭ�ϼ�ʱ������ID.
#define DEFAULT_TIMER_HANDLE_THREAD_ID 2      //5 Ĭ�ϼ�ʱ������ID
#define TIMER_ROOT_SIZE_MASK    8#define TIMER_OTHER_SIZE_MASK   6

typedef INT64 TimerType;

typedef void (*TimerCallBackFunc)(void * pObj , UINT32 unTimerID , UINT32 unRemainTimes ); 

#endif