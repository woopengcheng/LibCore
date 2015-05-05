// TestTimer.cpp : 定义控制台应用程序的入口点。
//

#include "TimerLib/inc/GlobalTimer.h"
#include "TimerLib/inc/GlobalTimerTask.h"
#include "TimerLib/inc/TimerHelp.h"

#include "stdafx.h"

class TestTimer : public Timer::TimerTask
{
public:
	TestTimer(){}
	virtual ~TestTimer(){}

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
	printf("TimerID %d , Times: %d" , unTimerID , unTimers); 
}

INT32 TestTimer::SetTimer( UINT32 unInterval , UINT32 unTimes , UINT32 unStartTimer /*= 0*/ )
{
	return Timer::GlobalTimer::GetInstance().SetTimer(unInterval , unStartTimer , unTimes ,  this , TimerTask::RunTimer);  
}

int _tmain(int argc, _TCHAR* argv[])
{
	Timer::GlobalTimer::GetInstance().Init(1,1);
	TestTimer test;
	test.SetTimer(1);
	while (1)
	{
		Timer::TimerHelper::sleep(1);
	}
	Timer::GlobalTimer::GetInstance().Cleanup();
	system("pause");
	return 0;
}