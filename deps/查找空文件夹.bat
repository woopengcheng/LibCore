@echo off
setlocal enabledelayedexpansion
mode con cols=80 lines=25
set /a sum=0
echo.
echo.
echo ɾ����ǰ����Ŀ¼������Ŀ¼��10���ڵ����п��ļ��У��Խ�ʡ�ռ䡣
echo.
echo       ��ǰ����Ŀ¼Ϊ�� %cd%
echo.
echo                                                   �����   ��ʼɾ�����ļ���
pause>nul
echo -----------------------------------------------------------------------------

for /l %%i in (1 1 10) do (
for /f "delims=" %%i in ('dir /ad /b /s') do (
dir /b "%%i"|findstr .>nul||rd "%%i"&&echo �ɹ�ɾ�����ļ��У�%%i&&set /a sum=sum+1
)

)
echo -----------------------------------------------------------------------------
echo      ��ɾ��%cd%Ŀ¼�� ���ļ��и�����%sum%
echo.
echo.
echo    ��������˳�
pause>nul
set sum=
exit