// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include <corecrt.h>
#include "re2/re2.h"
#include "re2/regexp.h"

int main()
{
	_Mbstatet s;
	std::cout << _MSC_VER << std::endl;
	char buf[1024];
	RE2::FullMatch("test1231", "(-?[0-9]+)[uUlL]*" , buf);

	std::cout << buf;
    return 0;
}

