// TestLibCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Marshal/CStream.h"
#include "Marshal/MashalTest.h"
#include "Common/LibCore.h"

int _tmain(int argc, _TCHAR* argv[])
{
	LibCore::Init("InnerMsg");  

	printf("%d" , 0|-1 | -2);
	LibCore::CStream objCS;

	LibCore::MarshalTest objTest(1);
	LibCore::MarshalTest objTest2(2);
	objCS << objTest;
	objCS >> objTest2;

	LibCore::Cleanup();
	return 0;
}

