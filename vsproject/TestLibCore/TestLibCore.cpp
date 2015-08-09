// TestLibCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "ctype.h"
#include "Marshal/Marshal.h"
#include "MsgLib/inc/ParameterHelper.h"
#include "MsgLib/inc/GenMsgHelper.h"
#include "MsgLib/inc/Parameters.h"

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
	Msg::Parameters         m_objParams;  
	Msg::GenMsgHelper::GenMsgParams(m_objParams , vec);

}

// template<typename P1 , typename P2 , typename P3 , typename P4 , typename P5 , typename P6 , typename P7 , typename P8>
// BOOL GetValue(P1 &p1 = INT32(0) , P2 &p2 = INT32(0) , P3 &p3 = INT32(0) , P4 &p4 = INT32(0) , P5 &p5 = INT32(0) , P6 &p6 = INT32(0) , P7 &p7 = INT32(0) , P8 &p8 = INT32(0))
// {
// 	std::cout << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << std::endl;
// }


static INT32 testA;

template<typename P1 = INT32 , typename P2 = INT32, typename P3 = INT32 , typename P4  = INT32, typename P5  = INT32, typename P6 = INT32 , typename P7 = INT32 , typename P8 = INT32>
class GetValueA
{
public:
public:
	BOOL GetValue(P1 &p1 = testA , P2 &p2 = testA , P3 &p3 = testA , P4 &p4 = testA , P5 &p5 = testA , P6 &p6 = testA , P7 &p7 = testA , P8 &p8 = testA)
	{
		std::cout << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << std::endl;
	}
};

class GetValueB
{
public:
public:
	BOOL GetValue(P1 &p1 = testA , P2 &p2 = testA , P3 &p3 = testA , P4 &p4 = testA , P5 &p5 = testA , P6 &p6 = testA , P7 &p7 = testA , P8 &p8 = testA)
	{
		std::cout << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << std::endl;
		return 1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{ 
	Msg::Parameters         m_objParams;  
	std::vector<INT32> vec;
	vec.push_back(1);
	vec.push_back(2);
	Msg::ParameterHelper<std::vector<INT32>& >::MakeParameter(m_objParams.m_aParameter[0] , vec);
	std::vector<INT32> & vt = Msg::ParameterHelper<std::vector<INT32>&>::GetParameterValue(m_objParams.m_aParameter[0]);
	
	INT32 n;
	GetValueA<>  t;
	t.GetValue(n);

//	testFunc(vec);
//	testRe(vec);
	return 0;
}

