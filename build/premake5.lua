--lua����֧�ּ����Ż��߲�������.�������������ַ������߱�����ʱ����Ҫ������.���Ի��Ǽ����űȽϺ�.

--��������
solution("HelloWorld")

--����һ��solution,ȷ�����е���Ŀ���������Ǹ�����.premake���Զ�ʶ��debug,release,debugDLL,releaseDLL,
--��������Զ����,��Ҫ��filter����һЩ����.
configurations({ "Debug", "Release" })

--��Ŀ����
project("HelloWorld")
	
	--����̨����windowsApp,SharedLib,StaticLib,MakeFile(����ǳ�����,��Ҫ��https://github.com/premake/premake-core/wiki/Makefile_Projects),None(������.)
	kind("ConsoleApp")

	--���������,ò��ֻ��"C++"��"C"����
	language("C++")
	
	targetdir "bin/%{cfg.buildcfg}"

	--�������������ļ�.**������Ǳ������еİ������ļ��з��ϵ��ļ�,��ȻҲ����д������ļ�
	files({ "**.h", "**.c","**.cpp" })
	
	--�ڱ����ʱ����Ҫ�������ļ�.�������溬������ļ��еĶ�������.
	--excludes { "**/Win32Specific/**" }
	--excludes { "tests/*.c" } ����ļ����º�׺Ϊ.c�Ĳ�����.
	excludes({"tests/*.c"})

	--��������Զ����configurations������
	--filter���÷�:filter({ "prefix:keywords" })
	filter("configurations:Debug")
	
		--һЩ�궨��
		--ȥ���궨����ǰ���remove:����
		--removedefines({"TRACE"})
		defines({ "DEBUG" })
		
		-- ��������������Ϣ.
		flags({ "Symbols" })

	filter "configurations:Release"
		defines { "NDEBUG" }
		
		-- �����Ż�,Ϊrelease��׼����.
		optimize "On"