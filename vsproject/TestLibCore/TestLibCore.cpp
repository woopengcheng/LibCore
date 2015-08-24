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

int _tmain(int argc, _TCHAR* argv[])
{   

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
	builder.appendBinData("vec" , p.GetStreamSize() , mongo::bdtParamter , (const char *)(p.GetStreamData()));

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
			//int id = 0;

			//if(be.type() == mongo::BinData)
			//{
			//	int len = 0;
			//	const char* data = be.binData(len);
			//	p2.GetParamStream().Pushback((void*)data , len);
			//	p2.GetParameterValue(vec2); 

			CUtil::Parameter p3;
			//	p3.GetParameterValue(vec3); 

			//	if (vec2 == vec3)
			//	{
			//		std::cout << " id: "<< id <<std::endl;
			//	}
			//	if (t1 == t2)
			//	{
			//		std::cout << " id: "<< id <<std::endl;
			//	}
			//}

			CUtil::BsonToCpp(p3 , be);
			vec2 = p3;
		}

	}
	 
	CUtil::Cleanup();
	return 0;
}

