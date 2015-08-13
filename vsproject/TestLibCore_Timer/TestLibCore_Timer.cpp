// TestTimer.cpp : 定义控制台应用程序的入口点。
//

#include "TimerLib/inc/GlobalTimer.h"
#include "TimerLib/inc/GlobalTimerTask.h"
#include "TimerLib/inc/TimerHelp.h"
#include "Common/CUtil.h"

#include "stdafx.h"

class TestTimer : public Timer::TimerTask
{
public:
	TestTimer()
	: test(1)
	{}
	virtual ~TestTimer(){}
	int test;

public:
	virtual void  OnTimer(UINT32 unTimerID , UINT32 unTimers);
		//************************************
		// Method:    SetTimer
		// FullName:  GlobalTimerTask::SetTimer
		// Access:    virtual public 
		// Returns:   INT32   返回Timer的ID.-1代表错误.
		// Qualifier: 
		// Parameter: UINT32 unInterval    时间间隔
		// Parameter: UINT32 unTimes       0代表持续.1代表一次.
		// Parameter: UINT32 unStartTimer  0代表即可开始
		//************************************
		virtual INT32  SetTimer( UINT32 unInterval , UINT32 unTimes = 0, UINT32 unStartTimer = 0);
};

void TestTimer::OnTimer( UINT32 unTimerID , UINT32 unTimers )
{
	printf("TimerID %d , Times: %d\n" , unTimerID , unTimers); 
}

//************************************
// Method:    RunTimer
// FullName:  TimerTask::RunTimer
// Access:    static public 
// Returns:   void
// Qualifier: 计时器调用计时器任务的函数.
// Parameter: UINT32 unTimerID
// Parameter: UINT32 unTimers
//************************************
static void  RunTimer(void * pObj , UINT32 unTimerID , UINT32 unTimers) 
{ 
	TestTimer * pTimerTask = (TestTimer *)pObj;
	printf("static run time timerID %d , Times: %d , test:%d\n" , unTimerID , unTimers , pTimerTask->test);  
}

static void  RunTimer2(void * pObj , UINT32 unTimerID , UINT32 unTimers) 
{  
	printf("static run time timerID %d , Times: %d ,noObj\n" , unTimerID , unTimers );  
}

INT32 TestTimer::SetTimer( UINT32 unInterval , UINT32 unTimes , UINT32 unStartTimer /*= 0*/ )
{
//	return Timer::GlobalTimer::GetInstance().SetTimer(unInterval , unStartTimer , unTimes ,  this ,NULL);  
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	CUtil::Init("Timer");
	Timer::GlobalTimer::GetInstance().Init(1,1);

	TestTimer test;
	test.SetTimer(1 , 1);
	Timer::GlobalTimer::GetInstance().SetTimer(1 , 1 , 1 ,  &test ,RunTimer);
 	Timer::GlobalTimer::GetInstance().SetTimer(1 , 1 , 1 ,  NULL ,RunTimer2);
//	Timer::GlobalTimer::GetInstance().SetTimer(1 , 1 , 1 ,  NULL ,NULL);
//	test.SetTimer(1 , 2);
	while (1)
	{
		Timer::TimerHelper::sleep(1);
	}

	Timer::GlobalTimer::GetInstance().Cleanup();
	CUtil::Cleanup();
	return 0;
}