#include "TimerLib/inc/GlobalTimerTask.h"
#include "TimerLib/inc/GlobalTimer.h"

namespace Timer
{

	GlobalTimerTask::GlobalTimerTask( void )
	{

	}

	GlobalTimerTask::~GlobalTimerTask( void )
	{

	} 

	void GlobalTimerTask::OnTimer( UINT32 unTimerID , UINT32 unTimers )
	{

	}
	 
	INT32 GlobalTimerTask::SetTimer( UINT32 unInterval , UINT32 unTimes , UINT32 unStartTimer /*= 0*/ )
	{
 		return GlobalTimer::GetInstance().SetTimer(unInterval , unStartTimer , unTimes ,  this , NULL);  
	}

}