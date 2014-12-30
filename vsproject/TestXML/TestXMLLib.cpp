// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "xml.h"
#include "Log.h"

int _tmain(int argc, _TCHAR* argv[])
{ 
	Log::Init("xml");
	XML::XML xml;
	xml.LoadFromFile("test.xml");


	Log::Cleanup();
	return 0;
}

