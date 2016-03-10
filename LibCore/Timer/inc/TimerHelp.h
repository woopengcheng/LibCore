#ifndef __timer_timer_help_h__
#define __timer_timer_help_h__ 
#include "Timer/inc/TimerCommon.h"

namespace Timer
{
	extern INT64 	DLL_EXPORT	GetTickCount();									//5 ���CPU��ʱ��Ƶ��������Ĵ���,�������Ƶ�ʵ��ٶ�.�Ϳ��Եõ�����
	extern INT64	DLL_EXPORT	GetTickFrequency();								//5 CPUƵ��.
	extern INT64	DLL_EXPORT	GetTickSecond(INT64 llTime = -1);				//5 ��ȡCPU���е�ʱ��(��)
	extern INT64	DLL_EXPORT	GetTickMicroSecond(INT64 llTime = -1);			//5 ��ȡCPU���е�ʱ��(����)
	extern INT64	DLL_EXPORT	GetTickMilliSecond(INT64 llTime = -1);			//5 ��ȡCPU���е�ʱ��(΢��) 

	extern INT64	DLL_EXPORT	GetMilliSecond(INT64 llTime);					//5 ���΢��
	extern INT64	DLL_EXPORT	GetMicroSecond(INT64 llTime);					//5 ��ú��� 
	extern INT64	DLL_EXPORT	GetSecond(INT64 llTime);						//5 �����  

	extern INT64	DLL_EXPORT	DiffMilliSecond(INT64 llTime1, INT64 llTime2);	//5 �Ƚ�����΢��Ĳ���
	extern INT64	DLL_EXPORT	DiffMicroSecond(INT64 llTime1, INT64 llTime2);	//5 �Ƚ���������Ĳ���
	extern INT64 	DLL_EXPORT	DiffSecond(INT64 llTime1, INT64 llTime2);		//5 �Ƚ�������Ĳ���

	extern time_t	DLL_EXPORT	GetTime();
	extern void		DLL_EXPORT	sleep(INT64 llMillSec);
	extern INT32	DLL_EXPORT	GetCurTimingwheelPos(INT32 nFutureTime, INT32 & nWheelSize, INT32 & nTimerSize);

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
	extern std::string	DLL_EXPORT	GetDate(std::string strFormat = "%Y-%m-%d");
}
#endif