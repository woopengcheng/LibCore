#ifndef __thread_pool_thread_common_h__
#define __thread_pool_thread_common_h__
#include "CUtil/inc/Common.h"
#include "tbb/concurrent_unordered_map.h"
#include "tbb/concurrent_hash_map.h"
#include "tbb/concurrent_queue.h"
#include "tbb/concurrent_vector.h"
#include "tbb/concurrent_unordered_set.h"

#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h> 
  
namespace ThreadPool
{ 
#define MAX_THREAD_TASK_NUMBER   0xfffffff
	
#define tbb_unordered_map tbb::concurrent_unordered_map 
#define tbb_hash_map      tbb::concurrent_hash_map 
#define tbb_queue         tbb::concurrent_queue 
#define tbb_unordered_set tbb::concurrent_unordered_set

#define THREAD_SLEEP_COUNT       1000   //5 �ر��̵߳�ʱ��ÿ����Ҫִ�еĴ���
#define MAX_THREAD_SLEEP_COUNT   100000 //5 �ر��߳����ִ�еĴ���.

#define DEFAULT_THREAD_SEM_PATH  "./ThreadSem.sem"

	enum ETHREAD_SIG
	{
		THREAD_SIG_ALIVE = 0   , //5 0��ѯ���߳�������.
		THREAD_SIG_QUIT  = 250 , //5 Ҫ���߳��˳�
	};

	enum THREAD_PRIORITY
	{ 
		
	};

	struct ThreadFuncParam
	{
		void * pParam;
		UINT32 unPriority;

		ThreadFuncParam(void * p , UINT32 unPrio) : pParam(p) , unPriority(unPrio){}
		~ThreadFuncParam(){}
	};



} //Thread
#endif