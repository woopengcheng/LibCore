// InnerMsgLib.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h" 
#include "xml.h"
#include "Log.h"
#include "LibCore.h" 

int _tmain(int argc, _TCHAR* argv[])
{ 
	LibCore::Init("xml");
	XML::XML xml;
	xml.LoadFromFile("test.xml");
	std::cout << xml.GetXMLValue("/pwdist/communicator/listen_addr");
	 
	gErrorStream ("xmdl");
	Log::Cleanup();
	return 0;
}

