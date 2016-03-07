/************************************
FileName	:	ConfigManager.cpp
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.16.104
Version		:	0.0.1
Description	:	ConfigManager���ݹ����ļ�ʵ��
************************************/
#include "ConfigManager.h"
#include "LogLib/inc/Log.h"
#include "ActionConfig.h"
#include "ActivityConfig.h"
	

namespace Config
{
	ConfigManager::ConfigManager()
	{
		g_pActionConfig = new Config::ActionConfig;
// 		g_pActivityConfig = new Config::ActivityConfig;
	}

	ConfigManager::~ConfigManager()
	{
		SAFE_DELETE(Config::g_pActionConfig);
// 		SAFE_DELETE(Config::g_pActivityConfig);
	}

	ConfigManager & ConfigManager::GetInstance()
	{
		static ConfigManager instance;
		return instance;
	}

	INT32 ConfigManager::Init(std::string  strCsvPath)
	{
		MsgAssert_ReF1(strCsvPath.length(), "ConfigManager::Init error.");

		if (strCsvPath[strCsvPath.length() - 1] != '/')
		{
			strCsvPath = strCsvPath + "/";
		}

		MsgAssert_ReF1(Config::g_pActionConfig , "ConfigManager not Init")
		Config::g_pActionConfig->LoadFrom(strCsvPath + "ActionConfig.tabcsv");

// 		MsgAssert_ReF1(Config::g_pActivityConfig , "ConfigManager not Init")
// 		Config::g_pActivityConfig->LoadFrom(strCsvPath + "ActivityConfig.tabcsv");

		return 0;
	}

	INT32 ConfigManager::Cleanup()
	{
		return -1;
	}

}

