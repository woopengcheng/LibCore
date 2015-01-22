#include "ThreadPoolLib/inc/ThreadTask.h"
#include "TimerLib/inc/TimerHelp.h"
#include "ThreadPoolLib/inc/ThreadContext.h"
#include "ThreadPoolLib/inc/ThreadState.h"
#include "Common/LibCore.h"

namespace ThreadPool
{ 
	ThreadTask::ThreadTask( UINT32 unPriority , char * pTaskName /*= "UnknownName"*/ , BOOL bInStack /*=TRUE*/ )
		: m_unPriority(unPriority) 
		, m_bInStack(bInStack)
	{
		SetTaskName(pTaskName);   
	}

	void ThreadTask::SetThreadPriority( UINT32 unPriority )
	{
		 m_unPriority = unPriority; 
	}

	UINT32 ThreadTask::GetThreadPriority( void )
	{
		return m_unPriority; 
	} 

	void ThreadTask::OnStartThread( void )
	{

	}

	void ThreadTask::Run( void )
	{
		Update();
	}
	
	void ThreadTask::OnEndThread( void )
	{

	}

	char * ThreadTask::GetTaskName( void )
	{
		return m_aTaskName;
	}

	void ThreadTask::SetTaskName( char * pName )
	{
		LibCore::strncpy(m_aTaskName , MAX_NAME_LENGTH ,pName);
	}


	INT32 ThreadNormalTask::Update( void )
	{ 
		return 0; 
	}


	void ThreadSustainTask::Run( void )
	{
		while (1)
		{
			//5 处理线程退出的信号量的问题.
			ThreadContext<ThreadState> * pThreadContext = (ThreadContext<ThreadState> *)(pthread_getspecific(ThreadContext<ThreadState>::GetThreadKey()));
			if (pThreadContext && (pThreadContext->GetContext()->GetThreadState() == THREAD_STATE_CLOSEING || pThreadContext->GetContext()->GetThreadState() == THREAD_STATE_CLOSED))
			{
				pThreadContext->GetContext()->SetThreadState(THREAD_STATE_CLOSED);
				return ;
			}

			//5 这里处理当线程收到退出的时候.要退出线程.
			sem_t & objSem = ThreadContext<ThreadState>::GetThreadSem(); 
			INT32 nValue = -1;
			sem_getvalue(&objSem , &nValue);
			if (nValue == 1)
			{
				pThreadContext->GetContext()->SetThreadState(THREAD_STATE_CLOSED);
				return ;
			}  

			Update();

			Timer::TimerHelper::sleep(1);
// 			pthread_testcancel();
		}
	}

	INT32 ThreadSustainTask::Update( void )
	{

		return 0;
	}

}