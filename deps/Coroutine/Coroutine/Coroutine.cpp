#include "Coroutine.h"
#include <stdio.h>
#include <assert.h>

#ifdef WIN32
	#include <windows.h>
#else
	#include "libco/co_routine.h"
	#include "libco/co_routine_inner.h"
	#include "libco/coctx.h"
#endif

namespace Coroutine
{
	void *	g_fiber_context = NULL;
#ifdef WIN32
	INT32 CoInit()
	{
		g_fiber_context = ConvertThreadToFiber(NULL);
		assert(g_fiber_context);

		return 0;
	}
	INT32 CoCreate(void ** pCoID, coroutine_func pFunc, void * arg)
	{
		*pCoID = CreateFiber(0, pFunc, arg);
		if (*pCoID)
		{
			printf("create fiber success.\n");
		}

		return 0;
	}

	void CoResume(void * pCoID)
	{
		SwitchToFiber(pCoID);
	}

	void CoYield(void * pCoID)
	{
		SwitchToFiber(pCoID);
	}

	void Coroutine::CoYieldCur(void)
	{
		Coroutine::CoResume(g_fiber_context);
	}

	void CoRelease(void * pCoID)
	{
		DeleteFiber(pCoID);
	}

	void CoCleanup()
	{
		ConvertFiberToThread();
	}

#else
	INT32 CoInit()
	{

		return 0;
	}
	INT32 CoCreate(void ** pCoID, coroutine_func pFunc, void * arg)
	{
		return co_create((stCoRoutine_t**)pCoID, NULL, pFunc, arg);
	}

	void CoResume(void * pCoID)
	{
		co_resume((stCoRoutine_t *)pCoID);
	}

	void CoYield(void * pCoID)
	{
		co_yield((stCoRoutine_t *)pCoID);
	}

	void Coroutine::CoYieldCur(void)
	{
		co_yield_ct();
	}

	void CoRelease(void * pCoID)
	{
		co_release((stCoRoutine_t *)pCoID);
	}

	void CoCleanup()
	{
	}


#endif // !WIN32

}
