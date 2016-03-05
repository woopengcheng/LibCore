// TestLibCore.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "CUtil/inc/CUtil.h"
#include "CSVConfigs/ConfigManager.h"

int _tmain(int argc, _TCHAR* argv[])
{   
	CUtil::Init();
	
	Config::ConfigManager::GetInstance().Init("./csv_config");

	while (true)
	{
		Config::ConfigManager::GetInstance().Cleanup();

	}

	CUtil::Cleanup();
	return 0;
}

