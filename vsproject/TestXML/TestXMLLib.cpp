// InnerMsgLib.cpp : �������̨Ӧ�ó������ڵ㡣
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

