#ifndef __timer_timer_help_h__
#define __timer_timer_help_h__ 
#include "TimerLib/inc/TimerCommon.h"

namespace Timer
{  
	class DLL_EXPORT TimerHelper
	{
	public:  
		static INT64  GetTickCount();                 //5 ���CPU��ʱ��Ƶ��������Ĵ���,�������Ƶ�ʵ��ٶ�.�Ϳ��Եõ�����
		static INT64  GetTickFrequency();             //5 CPUƵ��.
		static INT64  GetTickSecond(INT64 llTime = -1);              //5 ��ȡCPU���е�ʱ��(��)
		static INT64  GetTickMicroSecond(INT64 llTime = -1);         //5 ��ȡCPU���е�ʱ��(����)
		static INT64  GetTickMilliSecond(INT64 llTime = -1);         //5 ��ȡCPU���е�ʱ��(΢��) 

		static INT64  GetMilliSecond(INT64 llTime); //5 ���΢��
		static INT64  GetMicroSecond(INT64 llTime); //5 ��ú��� 
		static INT64  GetSecond(INT64 llTime);      //5 �����  

		static INT64  DiffMilliSecond(INT64 llTime1 , INT64 llTime2);  //5 �Ƚ���������Ĳ���
		static INT64  DiffMicroSecond(INT64 llTime1 , INT64 llTime2);  //5 �Ƚ���������Ĳ���
		static INT64  DiffSecond(INT64 llTime1 , INT64 llTime2);       //5 �Ƚ�������Ĳ���
		
		/*
			%a ���ڼ�����д��Eg:Tue 
			%A ���ڼ���ȫ���� Eg: Tuesday
			%b �·����Ƶ���д�� 
			%B �·����Ƶ�ȫ���� 
			%c ���ض�����ʱ��ϼѱ�ʾ�ַ����� 
			%d �����ֱ�ʾ���µĵڼ��� (��ΧΪ 00 �� 31)������
			%H �� 24 Сʱ�����ֱ�ʾСʱ�� (��ΧΪ 00 �� 23)�� 
			%I �� 12 Сʱ�����ֱ�ʾСʱ�� (��ΧΪ 01 �� 12)�� 
			%j �����ֱ�ʾ����ȵĵڼ��� (��ΧΪ 001 �� 366)�� 
			%m �·ݵ����� (��Χ�� 1 �� 12)��
			%M ���ӡ� 
			%p �� ''AM'' �� ''PM'' ��ʾ���ض�ʱ�䡣 
			%S ������ 
			%U ���ֱ�ʾΪ����ȵĵڼ��ܣ���һ�������ɵ�һ�����տ�ʼ�� 
			%W ���ֱ�ʾΪ����ȵĵڼ��ܣ���һ�������ɵ�һ����һ��ʼ�� 
			%w �����ֱ�ʾ���ܵĵڼ��� ( 0 Ϊ����)�� 
			%x ����ʱ������ڱ�ʾ���� 
			%X �������ڵ�ʱ���ʾ���� Eg: 15:26:30
			%y ��λ���ֱ�ʾ��� (��Χ�� 00 �� 99)�� 
			%Y ������������ֱ�ʾ������λ���� Eg:2008
			%Z(%z) ʱ����������д��Eg:�й���׼ʱ�� */
		static std::string GetDate(std::string strFormat = "%Y-%m-%d");

		static  void   sleep(INT64 llMillSec);
	};
}
#endif