// TestTimer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "GlobalTimer.h"
#include "GlobalTimerTask.h"
#include "TimerHelp.h"

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
		// Returns:   INT32   ����Timer��ID.-1�������.
		// Qualifier: 
		// Parameter: UINT32 unInterval    ʱ����
		// Parameter: UINT32 unTimes       0�������.1����һ��.
		// Parameter: UINT32 unStartTimer  0�����ɿ�ʼ
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
	return 0;
}

