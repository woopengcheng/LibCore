/************************************
FileName	:	ActionConfigLoad.h
Author		:	generate by tools
HostName	:	DESKTOP-5AT4DK2
IP			:	192.168.16.104
Version		:	0.0.1
Date		:	2016-03-09 21:42:33
Description	:	csv�����ļ�
************************************/
#ifndef __ActionConfigLoad_define_h__
#define __ActionConfigLoad_define_h__
#include "CUtil/inc/Common.h "

namespace Config
{
	struct SActionConfigLoad
	{
		INT32							curve_id;	//�켣ID
		std::vector<INT32>				validStages;	//��Ч����--�����ʾ���г�������Ч--����������ó�������Ч
		std::string						wrapMode;	//ѭ����ʽ
		std::vector<std::string>		InterfaceIcon;	//������ͼ��
		double							attr_mod_val;	//�����޸�ֵ
		std::vector<double>				start_x;	//��ʼ��
		INT64							col_1;	//��ע1
		bool							isLocal;	//����ϵ

		//�ṹ��
		struct STestStruct
		{
			bool						test1;
			INT64						test2;
			double						test3;
			INT32						test4;
			std::string					test6;
		}TestStruct;

		//�ṹ������
		struct STestStructArray
		{
			bool						test1;
			INT64						test2;
			double						test3;
			INT32						test4;
			std::string					test5;
		};
		std::vector<STestStructArray>		vecTestStructArray;
	};


	class ActionConfigLoad
	{
	public:
		typedef std::vector<SActionConfigLoad> CollectionConfigsT;

	public:
		bool LoadFrom(const std::string& filename);

	public:
		SActionConfigLoad & Get(size_t row);

	public:
		inline size_t Count(){ return m_vtConfigs.size(); }

	private:
		CollectionConfigsT m_vtConfigs;
	};
}

#endif// end  __ActionConfigLoad_define_h__
