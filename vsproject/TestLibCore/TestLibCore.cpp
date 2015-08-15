// TestLibCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "ctype.h"
#include "Marshal/inc/Marshal.h"
#include "CUtil/inc/ParameterHelper.h"
#include "CUtil/inc/GenMsgHelper.h"
#include "CUtil/inc/Parameters.h"

template<typename T>
class test
{
public:
	test(T & t):m_t(&t){}

private:
	T * m_t;
};
//template<typename T > class  helper { };

template <typename T>
class helper
{
public:
	static void te(test<T> t)
	{
		printf("adsf");
	}
	static void te(test<T> & t)
	{
		printf("adsf");
	}
};

template<typename T>
void testFunc(T & vec)
{
	helper<T>::te(vec);
}


template<typename Container>
class STContainer 
{
	Container *pc;
public:
	STContainer(Container & c) : pc(&c) { }
};

void testRe(std::vector<INT32> & vec)
{
	CUtil::Parameters         m_objParams;  
	CUtil::GenMsgHelper::GenMsgParams(m_objParams , vec);

}

// template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
// BOOL GetValue(P1 &p1 = INT32(0) , P2 &p2 = INT32(0) , P3 &p3 = INT32(0) , P4 &p4 = INT32(0) , P5 &p5 = INT32(0) , P6 &p6 = INT32(0) , P7 &p7 = INT32(0) , P8 &p8 = INT32(0))
// {
// 	std::cout << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << std::endl;
// }


static INT32 testA;

class testb
{
public:
	int a ;
protected:
private:
};

class Paramter
{
public:
	int a ;

	operator bool()
	{
		return a;
	}
	template <typename T>
	operator T()
	{
		return a;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{ 
	Paramter p;
	int a = p;

//	testFunc(vec);
//	testRe(vec);
	return 0;
}

