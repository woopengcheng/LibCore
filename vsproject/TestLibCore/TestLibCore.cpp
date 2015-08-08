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

int _tmain(int argc, _TCHAR* argv[])
{ 
	Msg::Parameters         m_objParams;  
	std::vector<INT32> vec;
	vec.push_back(1);
	vec.push_back(2);
	Msg::ParameterHelper<std::vector<INT32>& >::MakeParameter(m_objParams.m_aParameter[0] , vec);
	std::vector<INT32> & vt = Msg::ParameterHelper<std::vector<INT32>&>::GetParameterValue(m_objParams.m_aParameter[0]);
	
//	testFunc(vec);
//	testRe(vec);
	return 0;
}

