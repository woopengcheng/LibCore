// TestLibCore.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "ctype.h"
#include "Marshal/inc/Marshal.h"
#include "CUtil/inc/ParameterHelper.h"
#include "CUtil/inc/GenMsgHelper.h"
#include "CUtil/inc/Parameters.h"
#include "bson/bson.h"
#include "CUtil/inc/BsonToCpp.h"
#include "half.h"
#include "CUtil/inc/ReferCount.h"

class TestS
{
public:
	TestS()
	{
		t = 3;
		printf("asdf");
	}
	char t;
};

class Stream
{
public:
	const Stream & operator >> (const TestS & t)	const		
	{
		print(CUtil::remove_const<TestS>(t)); return *this;
	}  

	const Stream & operator >> (const char & t)	const		
	{ 
		return *this;
	}  

	void print(TestS & t)		const 
	{ 
		const TestS tt; 
		t = tt;
	} 
};

class TestString
{
public:
	TestString()
	{

	}
	template<typename T>
	operator T()
	{
		T t;
		return t;
	}

	operator std::basic_string<char>()
	{
		return std::string("1");
	}
	 
	INT32 n;
};

int _tmain(int argc, _TCHAR* argv[])
{   
// 	std::string str ;
// 	str = (TestString());
	const TestS t;
	const TestS &tt = t;
	Stream o;
	o >> t;

	const char c = 1;
	o >> c;
	CUtil::Init();
	

	CUtil::Parameter p;
	CUtil::Parameter p2;
	int a = 1;

	std::vector<int> vec;
	std::vector<int> vec2;
	std::vector<int> vec3;
	std::map<int , int> t1;
	std::map<int , int> t2;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	p.MakeParameter(vec);
	mongo::BSONObjBuilder builder;
	builder.append("_T",a);
	builder.appendBinData("vec" , p.GetDataLen() , mongo::bdtParamter , (const char *)(p.GetStreamData()));

	mongo::BSONObj obj = builder.obj();
	mongo::BSONObjIterator  iter(obj); 
	while(iter.more())	
	{			
		mongo::BSONElement be = iter.next();
		const char* fieldName = be.fieldName(); 
		if (strcmp(fieldName , "_T") == 0 )
		{
			int id = 0;
			CUtil::BsonToCpp( id , be);

			std::cout << " id: "<< id <<std::endl;
		}
		if (strcmp(fieldName , "vec") == 0 )
		{
			CUtil::Parameter p3;
			CUtil::BsonToCpp(p3 , be);
			vec2 = p3;
		}

	}

	float aaa = 1023.f;

	std::cout << FLOAT16::ToFloat16Fast(aaa);
	 
	CUtil::Cleanup();
	return 0;
}

