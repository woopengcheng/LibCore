#ifndef __timer_min_heap_timer_h
#define __timer_min_heap_timer_h
#include "TimerLib/inc/TimerCommon.h"
#include "TimerLib/inc/MinHeap.h"

namespace Timer
{ 
	class MinHeapTimer : public MinHeap<INT64>
	{
	public:
		MinHeapTimer( void ){}
		virtual ~MinHeapTimer( void ){}

	public:
		virtual INT32    Init( void ){ return ERR_SUCCESS; }
		virtual INT32    Cleanup( void ){ return ERR_SUCCESS; }
 		virtual INT32    SetTimer(UINT32 unTimeInterval , UINT32 unStartTime , UINT32 unTimes , void * pObj = NULL , TimerCallBackFunc pFunc = NULL){ return ERR_SUCCESS; }
	};
} 
#endif