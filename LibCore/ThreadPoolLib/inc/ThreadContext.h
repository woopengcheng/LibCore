#ifndef __thread_pool_thread_context_h__
#define __thread_pool_thread_context_h__
#include "ThreadCommon.h"
#include "pthread.h"  
#include "semaphore.h"
#include "ThreadState.h"
#include <fcntl.h>

namespace ThreadPool
{ 
	template<typename Context>
	class ThreadContext
	{
	public:
		ThreadContext()
			: m_pContext(new Context)
		{}
		~ThreadContext()
		{
			SAFE_DELETE(m_pContext);
		}

	public:
		static INT32 Init();
		static void  Cleanup(void * pContext);
		static void  ThreadCleanup(void * pThreadTask);

	public:
		static sem_t  &  GetThreadSem(){ static sem_t m_objThreadSem; return m_objThreadSem; }
		static pthread_key_t & GetThreadKey(){ static pthread_key_t m_sThreadKey; return m_sThreadKey; }  

	public:
		Context  *  GetContext(){ return m_pContext; }

	private:
		Context  *  m_pContext;
	}; 

	template<typename Context>
	void ThreadContext<Context>::ThreadCleanup( void * pThread )
	{
		ThreadTask * pThreadTask = (ThreadTask *)pThread;
		if (pThreadTask)
		{
			pThreadTask->OnEndThread();

			if (pThreadTask->GetInStack())
			{
				SAFE_DELETE(pThreadTask);
			}
		}
	}

	template<typename Context>
	void ThreadContext<Context>::Cleanup( void * pContext )
	{
		Assert(pContext);
		SAFE_DELETE(pContext);	
	}

	template<typename Context>
	INT32 ThreadContext<Context>::Init()
	{ 
		static sem_t & objSem = ThreadContext<Context>::GetThreadSem();
		if( sem_init(&objSem , 0 , 0) )
		{ 
			Assert_Re0(0 && "´´½¨ÐÅºÅµÆÊ§°Ü...\n"); 
		} 
		return pthread_key_create(&ThreadContext<Context>::GetThreadKey() , ThreadContext<Context>::Cleanup);  
	}

};



#endif