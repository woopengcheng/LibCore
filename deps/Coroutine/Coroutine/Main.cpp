// Coroutine.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Coroutine.h"
#include <stdio.h>
#include <Windows.h>
#include <map>

/*
#include <windows.h>
#define FIBER_COUNT 10

void *fiber_context[FIBER_COUNT];
VOID WINAPI fiberProc(void*);

int main()
{
	int i;
	int fibers[FIBER_COUNT];

	for (i = 0; i < FIBER_COUNT; i++) {
		fibers[i] = i;
	}

	fiber_context[0] = ConvertThreadToFiber(NULL);

	for (i = 1; i < FIBER_COUNT; ++i) {
		fiber_context[i] = CreateFiber(0, fiberProc, &fibers[i]);
		if (fiber_context[i] != NULL)
			printf("Fiber %d created\n", i);
	}

	for (i = 1; i < FIBER_COUNT; ++i) {
		if (fiber_context[i] != NULL) {
			SwitchToFiber(fiber_context[i]);
		}
	}
	printf("Over\n");
}
*/

typedef std::map<INT32, Coroutine::CoTask*> MapCoTasksT;
MapCoTasksT	g_mapCoTasks;

static void fiberProc(void * pArg)
{
	Coroutine::CoTask * pTask = (Coroutine::CoTask *)pArg;
	while (1)
	{
		int nbr;
		nbr = (int)(pTask->pArg);
		printf("Hello from fiber %d\n", nbr);
		Coroutine::CoYieldCur();
	}
}

void loop()
{
	while (true)
	{
		INT32 nIndex = 0;
		char buf[256] = { 0 };
		if (scanf_s("%d", &nIndex))
		{
			Coroutine::CoResume(g_mapCoTasks[nIndex]->pCoID);
		}

		Sleep(1);
	}

}

int main()
{
	Coroutine::CoInit();
	for (INT32 i = 0; i < 5; i++)
	{
		Coroutine::CoTask * pTask = new Coroutine::CoTask;
		pTask->pArg = (void*)(i + 1);

		Coroutine::CoCreate(&(pTask->pCoID), fiberProc, pTask);
		g_mapCoTasks.insert(std::make_pair(i , pTask));
	}

	loop();

	for (INT32 i = 0; i < 5; i++)
	{
		Coroutine::CoTask * pTask = g_mapCoTasks[i];
		if (pTask)
		{
			Coroutine::CoRelease(pTask);
		}
		delete pTask;
	}
	g_mapCoTasks.clear();
	Coroutine::CoCleanup();

	printf("Over\n");
}