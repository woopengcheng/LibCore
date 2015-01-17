#ifndef __thread_pool_thread_task_h__
#define __thread_pool_thread_task_h__
#include "ThreadPoolLib/inc/ThreadCommon.h"

namespace ThreadPool
{
	class DLL_EXPORT ThreadTask
	{
	public:
		ThreadTask(UINT32 unPriority , char * pTaskName = "UnknownName" , BOOL bInStack = TRUE);
		~ThreadTask(void){}

	public:
		virtual void  OnStartThread( void );    //5 �߳̿�ʼִ�е�ʱ�����.
		virtual void  Run( void );
		virtual INT32 Update( void ) = 0 ;

		//************************************
		// Method:    OnEndThread
		// FullName:  ThreadPool::ThreadTask::OnEndThread
		// Access:    virtual public 
		// Returns:   void
		// Qualifier: ������Ϊ�ͷ��߳���Դ�ĵط�.��ʹ�߳��쳣�˳�Ҳ��������Ϊ�ͷŴ�.
		// Parameter: void
		//************************************
		virtual void  OnEndThread( void );      //5 �߳̽�����ʱ�����. 

	public:
		char *  GetTaskName( void );
		void    SetTaskName(char * pName);
		UINT32  GetThreadPriority( void );
		void    SetThreadPriority(UINT32 unPriority);
		BOOL	GetInStack() const { return m_bInStack; }
		void	SetInStack(BOOL val) { m_bInStack = val; }

	private:
		UINT32  m_unPriority;                    //5 ��ʼ��ֻ��.�����̰߳�ȫ.
		char    m_aTaskName[MAX_NAME_LENGTH];    //5 ��ʼ��ֻ��.�����̰߳�ȫ.
		BOOL    m_bInStack;                      //5 ��ʼ��ֻ��.�̰߳�ȫ.
	};


	class DLL_EXPORT ThreadNormalTask : public ThreadTask
	{ 
	public:
		ThreadNormalTask(UINT32 unPriority , char * pTaskName = "UnknownName", BOOL bInStack = FALSE):ThreadTask(unPriority , pTaskName , bInStack){}

	public:  
		virtual INT32  Update( void ); 
	};

	class DLL_EXPORT ThreadSustainTask : public ThreadTask
	{ 
	public:
		ThreadSustainTask(UINT32 unPriority , char * pTaskName = "UnknownName", BOOL bInStack = TRUE):ThreadTask(unPriority , pTaskName , bInStack){}
		~ThreadSustainTask(void){}

	public: 
		virtual void   Run( void );
		//************************************
		// Method:    Update
		// FullName:  ThreadPool::ThreadSustainTask::Update
		// Access:    virtual public 
		// Returns:   INT32
		// Qualifier: ���ﲻ��Ҫ����Update�������ѭ��.����������.
		// Parameter: void
		//************************************
		virtual INT32  Update( void ); 
	};
}


#endif