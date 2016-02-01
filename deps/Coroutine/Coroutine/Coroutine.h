#ifndef __coroutine_coroutine_h__
#define __coroutine_coroutine_h__

#define WIN32
typedef int INT32;
typedef void  (*coroutine_func)(void*);

namespace Coroutine
{
	struct CoTask
	{
		void * pCoID;
		void * pArg;
	};

	extern void *	g_fiber_context;  //5 这里需要每个线程一个.

	INT32		CoInit();
	INT32		CoCreate(void ** pCoID, coroutine_func pFunc, void * arg);
	void		CoResume(void * pCoID);
	void		CoYield(void * pCoID);
	void		CoYieldCur(void);
	void		CoRelease(void * pCoID);
	void		CoCleanup();

}


#endif // !__coroutine_coroutine_h__

