#include "CUtil/inc/ParameterHelper.h"
#include "CUtil/inc/Parameters.h"
#include "UnitTest++/UnitTestPP.h"

TEST(Parameter)
{
	char t = 1;
	UINT8 t1 = 2;
	bool t2 = 1;
	INT16 t3 = 4;
	UINT16 t4 = 5;
	INT32 t5 = 6;
	UINT32 t6 = 7;
	INT64 t7 = 8;
	UINT64 t8 = 9;
	float t9 = 10;
	double t10 = 11;
	CUtil::CharPtr  t11("12" , sizeof("12"));
	std::string t12 = "13";
	CUtil::CStream  t13;
	t13 << std::string("14"); 
	CUtil::Chunk  t14(15);
	std::vector<INT32> t15(1);
	std::vector<INT32> t16(1);
	std::list<INT32> t17(1);
	std::set<INT32> tempSet;
	tempSet.insert(1);
	std::set<INT32> t18 = tempSet; 
	std::string t19("t19");
	std::map<INT32 , INT32> tempMap;
	tempMap[1] = 2;
	std::map<INT32 , INT32> t20 = tempMap;
	std::pair<INT32 , INT32> t21;

	std::map<INT32 , CUtil::Chunk> t22;
	t22.insert(std::make_pair(1 , CUtil::Chunk(12)));

	std::map<INT32 , std::vector<INT32>> t23;
	t23.insert(std::make_pair(1 , t15));

	std::map<INT32 , std::list<INT32>> t24;
	t24.insert(std::make_pair(1 , t17));

	std::map<INT32 , std::set<INT32>> t25;
	t25.insert(std::make_pair(1 , t18));

	CUtil::Parameter objParam(t);
	CHECK_EQUAL(objParam.IsInt8() , true);
	CUtil::Parameter objPramCopy = objParam;
	CUtil::Parameter objPramCopy2 = objPramCopy;
	CUtil::Parameter objPramCopy3;
	objPramCopy3.Copy(objPramCopy2);
	CHECK_EQUAL(objPramCopy , objParam);
	CHECK_EQUAL(objPramCopy2 , objParam);
	CHECK_EQUAL(objPramCopy3 , objParam);
	CHECK_EQUAL(objParam.GetParamStream().GetData().GetChunkData()->GetRefCount() , 4);

	CHECK_EQUAL(objParam.GetSize() , sizeof(t));
	CHECK_EQUAL(objParam.GetType() , CUtil::PARAMETER_TYPE_SINT8);
	void * pBuf = objParam.GetStreamData();
	CUtil::Parameter objData;
	objData.SetSize(objParam.GetSize());
	objData.GetParamStream().Pushback(pBuf , objParam.GetDataLen());
	CHECK_EQUAL(objData , objPramCopy2);

	CUtil::Parameter objParamter;
	char p = objData;
	objParamter.MakeParameter(t1);
	UINT8 p1 = objParamter.GetParameterValue<UINT8>();
	objParamter.Clear();
	objParamter = CUtil::Parameter(t2);
	bool p2 = objParamter.GetParameterValue<bool>();
	INT16 p3 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t3);
	p3 = objParamter;
	UINT16 p4 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t4);
	p4 = objParamter;
	INT32 p5 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t5);
	p5 = objParamter;
	UINT32 p6 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t6);
	p6 = objParamter;
	INT64 p7 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t7);
	p7 = objParamter;
	UINT64 p8 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t8);
	p8 = objParamter;
	float p9 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t9);
	p9 = objParamter;
	double p10 = 0;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t10);
	p10 = objParamter;
	CUtil::CharPtr p11;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t11);
	p11 = objParamter;
	std::string p12;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t12);
	p12 = objParamter.operator std::string();
	CUtil::CStream  p13; 
	objParamter.Clear();
	objParamter = CUtil::Parameter(t13);
	p13 = objParamter;
	CUtil::Chunk  p14;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t14);
	p14 = objParamter;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t15);
	std::vector<INT32> p15 = objParamter; 
	objParamter.Clear();
	objParamter = CUtil::Parameter(t16);
	std::vector<INT32> p16 = objParamter;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t17);
	std::list<INT32> p17 = objParamter;
	
	objParamter.Clear();
	objParamter = CUtil::Parameter(t18);
	std::set<INT32> p18 = objParamter;
	std::string test;
	std::string & p19 = test;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t19);
	objParamter.GetParameterValue(p19); 
	objParamter.Clear();
	objParamter = CUtil::Parameter(t20);
	std::map<INT32, INT32> p20 = objParamter;
	
	objParamter.Clear();
	objParamter = CUtil::Parameter(t21);
	std::pair<INT32, INT32> p21 = objParamter;
	
	objParamter.Clear();
	objParamter = CUtil::Parameter(t22);
	std::map<INT32, CUtil::Chunk> p22 = objParamter;
	
	objParamter.Clear();
	objParamter = CUtil::Parameter(t23);
	std::map<INT32, std::vector<INT32>> p23 = objParamter;
	;
	objParamter.Clear();
	objParamter = CUtil::Parameter(t24);
	std::map<INT32, std::list<INT32>> p24 = objParamter;
	
	objParamter.Clear();
	objParamter = CUtil::Parameter(t25);
	std::map<INT32, std::set<INT32>> p25 = objParamter;
	CHECK_EQUAL(objParamter.GetType() , CUtil::PARAMETER_TYPE_STD_CONTAINER_OR_OTHERS);

	CHECK_EQUAL(t , p);
	CHECK_EQUAL(t1 , p1);
	CHECK_EQUAL(t2 , p2);
	CHECK_EQUAL(t3 , p3);
	CHECK_EQUAL(t4 , p4);
	CHECK_EQUAL(t5 , p5);
	CHECK_EQUAL(t6 , p6);
	CHECK_EQUAL(t7 , p7);
	CHECK_EQUAL(t8 , p8);
	CHECK_EQUAL(t9 , p9);
	CHECK_EQUAL(t10 , p10);
	//	CHECK_EQUAL(t11 , p11);
	CHECK_EQUAL(t12 , p12);
	CHECK_EQUAL(t13 , p13);
	CHECK_EQUAL(t14 , p14);
	Assert(t15 == p15);
	Assert(t16 == p16);
	Assert(t17 == p17);
	Assert(t18 == p18);
	Assert(t19 == p19);
	Assert(t20 == p20);
	Assert(t21 == p21);
	Assert(t22 == p22);
	Assert(t23 == p23);
	Assert(t24 == p24);
	Assert(t25 == p25);

	CUtil::CStream objCS;
	objCS << objParamter;
	CUtil::Parameter objTestParam;
	objCS >> objTestParam;
	CHECK_EQUAL(objParamter , objTestParam);
}

TEST(Parameters)
{

	char t = 1;
	UINT8 t1 = 2;
	bool t2 = 1;
	INT16 t3 = 4;
	UINT16 t4 = 5;
	INT32 t5 = 6;
	UINT32 t6 = 7;
	INT64 t7 = 8;
	UINT64 t8 = 9;
	float t9 = 10;
	double t10 = 11;
	CUtil::CharPtr  t11("12" , sizeof("12"));
	std::string t12 = "13";
	CUtil::CStream  t13;
	t13 << std::string("14"); 
	CUtil::Chunk  t14(15);
	std::vector<INT32> t15(1);
	std::vector<INT32> t16(1);
	std::list<INT32> t17(1);
	std::set<INT32> tempSet;
	tempSet.insert(1);
	std::set<INT32> t18 = tempSet; 
	std::string t19("t19");
	std::map<INT32 , INT32> tempMap;
	tempMap[1] = 2;
	std::map<INT32 , INT32> t20 = tempMap;
	std::pair<INT32 , INT32> t21;
	std::map<INT32 , CUtil::Chunk> t22;
	t22.insert(std::make_pair(1 , CUtil::Chunk(12)));
	std::map<INT32 , std::vector<INT32>> t23;
	t23.insert(std::make_pair(1 , t15));
	std::map<INT32 , std::list<INT32>> t24;
	t24.insert(std::make_pair(1 , t17));
	std::map<INT32 , std::set<INT32>> t25;
	t25.insert(std::make_pair(1 , t18));

	CUtil::Parameters objParams1;
	objParams1.GenMsgParams(t , t1 , t2 , t3 , t4 , t5 , t6 , t7);
	CUtil::Parameters objParams2;
	objParams2.GenMsgParams(t8 , t9 , t10 , t11 , t12 , t13 , t14 , t15);
	CUtil::Parameters objParams3;
	objParams3.GenMsgParams(t16 , t17 , t18 , t19 , t20 , t21 , t22 , t23);
	CUtil::Parameters objParams4;
	objParams4.GenMsgParams(t24 , t25); 
	
	CUtil::Parameter t26(t);
	CUtil::Parameters objParams5;
	objParams5.GenMsgParams(t26); 

	CUtil::Parameters t27 = objParams4;
	CUtil::Parameters objParams6;
	objParams6.GenMsgParams(t27); 

	CHECK_EQUAL(t27 , objParams4);
	CHECK_EQUAL(objParams1.GetParamCount() , 8);
	CHECK_EQUAL(objParams2.GetParamCount() , 8);
	CHECK_EQUAL(objParams3.GetParamCount() , 8);
	CHECK_EQUAL(objParams4.GetParamCount() , 2);
	CHECK_EQUAL(objParams5.GetParamCount() , 1);
	CHECK_EQUAL(objParams6.GetParamCount() , 1);
	 
	char p = objParams1[0]; 
	UINT8 p1 = objParams1[1];  
	bool p2 = objParams1[2];
	INT16 p3 = objParams1[3];  
	UINT16 p4 = objParams1[4]; 
	INT32 p5 = objParams1[5]; 
	UINT32 p6 = objParams1[6]; 
	INT64 p7 = objParams1[7]; 
	UINT64 p8 = objParams2[0]; 
	float p9 = objParams2[1]; 
	double p10 = objParams2[2]; 
	CUtil::CharPtr p11 = objParams2[3];  
	std::string p12 = objParams2[4];  
	CUtil::CStream  p13 = objParams2[5];  
	CUtil::Chunk  p14 = objParams2[6];  
	std::vector<INT32> p15 = objParams2[7];  
	std::vector<INT32> p16 = objParams3[0];  
	std::list<INT32> p17 = objParams3[1];  
	std::set<INT32> p18 = objParams3[2];  
	std::string p19 = objParams3[3];  
	std::map<INT32 , INT32> p20 = objParams3[4];  
	std::pair<INT32 , INT32> p21 = objParams3[5];  
	std::map<INT32 , CUtil::Chunk> p22 = objParams3[6];  
	std::map<INT32 , std::vector<INT32>> p23 = objParams3[7];  
	std::map<INT32 , std::list<INT32>> p24 = objParams4[0];  
	std::map<INT32 , std::set<INT32>> p25 = objParams4[1];  
	CUtil::Parameter p26;
	objParams5[0].GetParameterValue(p26); 
	CUtil::Parameters p27 = objParams6[0]; 

	CHECK_EQUAL(t , p);
	CHECK_EQUAL(t1 , p1);
	CHECK_EQUAL(t2 , p2);
	CHECK_EQUAL(t3 , p3);
	CHECK_EQUAL(t4 , p4);
	CHECK_EQUAL(t5 , p5);
	CHECK_EQUAL(t6 , p6);
	CHECK_EQUAL(t7 , p7);
	CHECK_EQUAL(t8 , p8);
	CHECK_EQUAL(t9 , p9);
	CHECK_EQUAL(t10 , p10);
	//	CHECK_EQUAL(t11 , p11);
	CHECK_EQUAL(t12 , p12);
	CHECK_EQUAL(t13 , p13);
	CHECK_EQUAL(t14 , p14);
	Assert(t15 == p15);
	Assert(t16 == p16);
	Assert(t17 == p17);
	Assert(t18 == p18);
	Assert(t19 == p19);
	Assert(t20 == p20);
	Assert(t21 == p21);
	Assert(t22 == p22);
	Assert(t23 == p23);
	Assert(t24 == p24);
	Assert(t25 == p25);
	CHECK_EQUAL(t26, p26);
	CHECK_EQUAL(t27 , p27);
	 
}