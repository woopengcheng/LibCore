#ifndef __timer_timer_help_h__
#define __timer_timer_help_h__ 
#include "Timer/inc/TimerCommon.h"

namespace Timer
{
	extern UINT64 	DLL_EXPORT	GetTickCount();									//5 ���CPU��ʱ��Ƶ��������Ĵ���,�������Ƶ�ʵ��ٶ�.�Ϳ��Եõ�����
	extern UINT64	DLL_EXPORT	GetTickFrequency();								//5 CPUƵ��.
	extern UINT64	DLL_EXPORT	GetTickSecond(UINT64 llTime = -1);				//5 ��ȡCPU���е�ʱ��(��)
	extern UINT64	DLL_EXPORT	GetTickMicroSecond(UINT64 llTime = -1);			//5 ��ȡCPU���е�ʱ��(����)
	extern UINT64	DLL_EXPORT	GetTickMilliSecond(UINT64 llTime = -1);			//5 ��ȡCPU���е�ʱ��(΢��) 

	extern UINT64	DLL_EXPORT	GetMilliSecond(UINT64 llTime);					//5 ���΢��
	extern UINT64	DLL_EXPORT	GetMicroSecond(UINT64 llTime);					//5 ��ú��� 
	extern UINT64	DLL_EXPORT	GetSecond(UINT64 llTime);						//5 �����  

	extern UINT64	DLL_EXPORT	DiffMilliSecond(UINT64 llTime1, UINT64 llTime2);	//5 �Ƚ�����΢��Ĳ���
	extern UINT64	DLL_EXPORT	DiffMicroSecond(UINT64 llTime1, UINT64 llTime2);	//5 �Ƚ���������Ĳ���
	extern UINT64 	DLL_EXPORT	DiffSecond(UINT64 llTime1, UINT64 llTime2);		//5 �Ƚ�������Ĳ���

	extern time_t	DLL_EXPORT	GetTime();
	extern void		DLL_EXPORT	sleep(UINT64 llMillSec);

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