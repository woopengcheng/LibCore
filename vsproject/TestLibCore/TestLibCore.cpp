// TestLibCore.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "CUtil/inc/CUtil.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	CUtil::Init();
	
	INT32 * p = new INT32;

	*p = 123;
	delete p;

	CUtil::Cleanup();
	return 0;
}

