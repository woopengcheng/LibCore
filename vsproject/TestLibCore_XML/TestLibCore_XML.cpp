// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "XMLLib/inc/xml.h"
#include "LogLib/inc/Log.h"
#include "Common/LibCore.h" 

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

