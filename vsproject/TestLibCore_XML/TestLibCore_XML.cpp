// InnerMsgLib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "XMLLib/inc/xml.h"
#include "LogLib/inc/Log.h"
#include "Common/inc/CUtil.h" 

int _tmain(int argc, _TCHAR* argv[])
{ 
	CUtil::Init("xml");
	XML::XML xml;
	xml.LoadFromFile("test.xml");
	std::cout << xml.GetXMLValue("/pwdist/communicator/listen_addr");
	 
	gErrorStream ("xmdl");
	Log::Cleanup();

	system("pause");
	return 0;
}

