// attention dont't change this line:INT32 ActivityId;std::string ActivityName;INT32 ActivityLevelLow;INT32 ActivityLevelHigh;bool IsShowEntrance;std::vector<std::string> EntranceIcon;bool IsShowInterface;std::vector<std::string> InterfaceIcon;INT32 StartTimeWeek;INT32 EndTimeWeek;INT32 StartTimeDate;INT32 EndTimeDate;std::string StartTime;std::string EndTime;INT32 Description;std::string RewardIcon;
/************************************
FileName	:	ActivityConfig.h
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.16.104
Version		:	0.0.1
Date		:	2016-03-09 21:35:57
Description	:	csv��ȡ�ļ�
************************************/
#ifndef __Config_ActivityConfig_define_h__
#define __Config_ActivityConfig_define_h__
#include "ActivityConfigLoad.h"

namespace Config
{

	struct SActivityConfig
	{
		INT32							ActivityId;	//�id
		std::string						ActivityName;	//�����
		INT32							ActivityLevelLow;	//��ʾ�ȼ�����,�����ȼ�����������������ʾ
		INT32							ActivityLevelHigh;	//��ʾ�ȼ����ޣ������ȼ�����������������ʾ
		bool							IsShowEntrance;	//�Ƿ���ʾ���ͼ�꣬���ͼ��ͽ���ͼ���ǻ���ģ����ͼ�����ʽ�ʺϵ�����������Ļ������ͼ�����ͨ�û�е�ͼ��
		std::vector<std::string>		EntranceIcon;	//���ͼ��
		bool							IsShowInterface;	//�Ƿ��������ʾ����������ʾ������ͨ�û����ʽ��������������ͼ������ʾ����ʾΪ���������ʽ
		std::vector<std::string>		InterfaceIcon;	//������ͼ��
		INT32							StartTimeWeek;	//���ʼʱ���ܣ���ÿ�ܵ���һ�죻������д��ֵ���ȼ��������忪ʼʱ���죬����ʱ�����޹�
		INT32							EndTimeWeek;	//�����ʱ����
		INT32							StartTimeDate;	//���ʼʱ���죬���ڴ�ʱ���ڣ���������ʾ
		INT32							EndTimeDate;	//�����ʱ����
		std::string						StartTime;	//���ʼʱ��㣬���ڴ�ʱ����������ʾ
		std::string						EndTime;	//�����ʱ���
		INT32							Description;	//�˵����ͨ�û�����еĻ����
		std::string						RewardIcon;	//����ͼ�꣬�콱�����иû���콱ͼ��
	};


	class ActivityConfig
	{
	public:
		typedef std_unordered_map<INT32 , SActivityConfig> MapConfigsT;

	public:
		bool LoadFrom(const std::string& filepath);
		SActivityConfig * GetActivityConfig(INT32 nIndex);

	private:
		MapConfigsT m_mapConfigs;

	};
	extern ActivityConfig * g_pActivityConfig;
}

#endif// end  __Config_ActivityConfig_define_h__
