#include "Marshal/inc/CStream.h"
#include "UnitTest++/UnitTestPP.h"


TEST(CStream_SINT8)
{
	CUtil::CStream cs;
	SINT8 p1 = 0x00000000;
	SINT8 p2 = 0x0000000F;
	SINT8 p3 = 0x00000010;  
	SINT8 p4 = 0x0000007F; 
	SINT8 p5 = -0x00000000; 
	SINT8 p6 = -0x0000000F; 
	SINT8 p7 = -0x0000007F; 

	SINT8 q1 = 0;
	SINT8 q2 = 0;
	SINT8 q3 = 0;
	SINT8 q4 = 0; 
	SINT8 q5 = 0;
	SINT8 q6 = 0; 
	SINT8 q7 = 0; 
	cs << p1 << p2 << p3 << p4 << p5 << p6 << p7;
	cs >> q1 >> q2 >> q3 >> q4 >> q5 >> q6 >> q7;

	CHECK_EQUAL(p1 , q1); 
	CHECK_EQUAL(p2 , q2); 
	CHECK_EQUAL(p3 , q3);
	CHECK_EQUAL(p4 , q4);  
	CHECK_EQUAL(p5 , q5); 
	CHECK_EQUAL(p6 , q6); 
	CHECK_EQUAL(p7 , q7); 
} 

TEST(CStream_UINT8)
{
	CUtil::CStream cs;
	UINT8 p1 = 0x00000000;
	UINT8 p2 = 0x0000000F;
	UINT8 p3 = 0x00000010;
	UINT8 p4 = 0x0000007F; 
	UINT8 p5 = 0x00000080; 
	UINT8 p6 = 0x0000008F; 
	UINT8 p7 = 0x000000FF; 

	UINT8 q1 = 0;
	UINT8 q2 = 0;
	UINT8 q3 = 0;
	UINT8 q4 = 0; 
	UINT8 q5 = 0;
	UINT8 q6 = 0; 
	UINT8 q7 = 0; 
	cs << p1 << p2 << p3 << p4 << p5 << p6 << p7;
	cs >> q1 >> q2 >> q3 >> q4 >> q5 >> q6 >> q7;

	CHECK_EQUAL(p1 , q1); 
	CHECK_EQUAL(p2 , q2); 
	CHECK_EQUAL(p3 , q3);
	CHECK_EQUAL(p4 , q4);  
	CHECK_EQUAL(p5 , q5); 
	CHECK_EQUAL(p6 , q6); 
	CHECK_EQUAL(p7 , q7); 
} 

TEST(CStream_INT16)
{
	CUtil::CStream cs;
	INT16 p[] = { 0x00000000, 0x0000000F, 0x00000010,	0x000000FF,
		0x00000100,	0x00000FFF,	0x00001000,	0x00007FFF,
		-0x00000000,-0x0000000F,-0x00000010,-0x000000FF,	
		-0x00000100,-0x00000FFF,-0x00007FFF };

	INT16 q[ARRAY_SIZE(p)];  
	for (UINT16 i = 0;i < ARRAY_SIZE(p);++i)
	{
		cs << p[i];
		cs >> q[i];

		CHECK_EQUAL(p[i] , q[i]); 
	}   
} 

TEST(CStream_UINT16)
{
	CUtil::CStream cs;
	UINT16 p[] = { 0x00000000, 0x0000000F, 0x00000010,	0x000000FF,
		0x00000100,	0x00000FFF,	0x00001000,	0x00007FFF,
		0x00008000,	0x0000800F,	0x00008010,	0x000080FF,	
		0x00008100,	0x00008FFF,	0x0000FFFF };

	UINT16 q[ARRAY_SIZE(p)];  
	for (UINT16 i = 0;i < ARRAY_SIZE(p);++i)
	{
		cs << p[i];
		cs >> q[i];

		CHECK_EQUAL(p[i] , q[i]); 
	}   
} 

TEST(CStream_INT32)
{
	CUtil::CStream cs;
	INT32 p[] = { 0x00000000, 0x0000000F, 0x00000010, 0x000000FF,
		0x00000100,	0x00000FFF,	0x00001000,	0x0000FFFFF,
		0x00010000,	0x00FFFFFF,	0x00100000,	0x0FFFFFFF,	
		0x10000000,	0x7FFFFFFF,	0xFFFFFFFF,	0x80000001,	
		0x8000000F,	0x80000010,	0x800000FF,	0x80000100,	
		0x80000FFF,	0x80001000,	0x800FFFFF,	0x80100000,
		0x80FFFFFF,	0x81000000,	0x8FFFFFFF,	0xFFFFFFFF};

	INT32 q[ARRAY_SIZE(p)] = {0};  

	for (INT32 i = 0;i < ARRAY_SIZE(p);++i)
	{
		cs << p[i];
		cs >> q[i];

		CHECK_EQUAL(p[i] , q[i]); 
	}   
}  

TEST(CStream_UINT32)
{
	CUtil::CStream cs;
	UINT32 p[] = { 0x00000000, 0x0000000F, 0x00000010, 0x000000FF,
		0x00000100,	0x00000FFF,	0x00001000,	0x0000FFFFF,
		0x00010000,	0x00FFFFFF,	0x00100000,	0x0FFFFFFF,	
		0x10000000,	0x7FFFFFFF,	0xFFFFFFFF,	0x80000001,	
		0x8000000F,	0x80000010,	0x800000FF,	0x80000100,	
		0x80000FFF,	0x80001000,	0x800FFFFF,	0x80100000,
		0x80FFFFFF,	0x81000000,	0x8FFFFFFF,	0xFFFFFFFF};

	UINT32 q[ARRAY_SIZE(p)] = {0};  

	for (INT32 i = 0;i < ARRAY_SIZE(p);++i)
	{
		cs << p[i];
		cs >> q[i];

		CHECK_EQUAL(p[i] , q[i]); 
	}   
} 

TEST(CStream_INT64)
{
	CUtil::CStream cs;
	INT64 p[] = { 0x0000000000000000 , 0x000000000000000F, 0x0000000000000010,	0x00000000000000FF,
	0x0000000000000100,	0x0000000000000FFF,	0x0000000000001000,	0x000000000000FFFFF,0x0000000000010000,
	0x0000000000FFFFFF,	0x0000000000100000,	0x000000000FFFFFFF,	0x0000000010000000,	0x00000000FFFFFFFF,
	0x0000000100000000, 0x0000000FFFFFFFFF, 0x0000001000000000,	0x000000FFFFFFFFFF,	0x0000010000000000,
	0x00000FFFFFFFFFFF,	0x0000100000000000,	0x0000FFFFFFFFFFFF,	0x0001000000000000,	0x000FFFFFFFFFFFFF,
	0x0010000000000000,	0x00FFFFFFFFFFFFFF,	0x0100000000000000,	0x0FFFFFFFFFFFFFFF,	0x1000000000000000,
	0x7FFFFFFFFFFFFFFF, 0x8000000000000001,	0x800000000000000F,	0x8000000000000010,	0x80000000000000FF,
	0x8000000000000100,	0x8000000000000FFF,	0x8000000000001000,	0x80000000000FFFFF,	0x8000000000100000,
	0x8000000000FFFFFF,	0x8000000001000000,	0x800000000FFFFFFF,	0x8000000010000000, 0x80000000FFFFFFFF,
	0x8000001000000000,	0x800000FFFFFFFFFF,	0x8000010000000000,	0x80000FFFFFFFFFFF,	0x8000100000000000,
	0x8000FFFFFFFFFFFF,	0x8001000000000000,	0x800FFFFFFFFFFFFF,	0x8010000000000000,	0x80FFFFFFFFFFFFFF,
	0x8100000000000000,	0x8FFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF };

	INT64 q[ARRAY_SIZE(p)] = { 0 };

	for (INT32 i = 0;i < ARRAY_SIZE(p);++i)
	{
		cs << p[i];
		cs >> q[i];

		CHECK_EQUAL(p[i] , q[i]); 
	}  
} 

TEST(CStream_UINT64)
{
	CUtil::CStream cs;
	UINT64 p[] = { 0x0000000000000000 , 0x000000000000000F, 0x0000000000000010,	0x00000000000000FF,
		0x0000000000000100,	0x0000000000000FFF,	0x0000000000001000,	0x000000000000FFFFF,0x0000000000010000,
		0x0000000000FFFFFF,	0x0000000000100000,	0x000000000FFFFFFF,	0x0000000010000000,	0x00000000FFFFFFFF,
		0x0000000100000000, 0x0000000FFFFFFFFF, 0x0000001000000000,	0x000000FFFFFFFFFF,	0x0000010000000000,
		0x00000FFFFFFFFFFF,	0x0000100000000000,	0x0000FFFFFFFFFFFF,	0x0001000000000000,	0x000FFFFFFFFFFFFF,
		0x0010000000000000,	0x00FFFFFFFFFFFFFF,	0x0100000000000000,	0x0FFFFFFFFFFFFFFF,	0x1000000000000000,
		0x7FFFFFFFFFFFFFFF, 0x8000000000000001,	0x800000000000000F,	0x8000000000000010,	0x80000000000000FF,
		0x8000000000000100,	0x8000000000000FFF,	0x8000000000001000,	0x80000000000FFFFF,	0x8000000000100000,
		0x8000000000FFFFFF,	0x8000000001000000,	0x800000000FFFFFFF,	0x8000000010000000, 0x80000000FFFFFFFF,
		0x8000001000000000,	0x800000FFFFFFFFFF,	0x8000010000000000,	0x80000FFFFFFFFFFF,	0x8000100000000000,
		0x8000FFFFFFFFFFFF,	0x8001000000000000,	0x800FFFFFFFFFFFFF,	0x8010000000000000,	0x80FFFFFFFFFFFFFF,
		0x8100000000000000,	0x8FFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF };

	UINT64 q[sizeof(ARRAY_SIZE(p))] = { 0 };

	for (INT32 i = 0;i < sizeof(ARRAY_SIZE(p));++i)
	{
		cs << p[i];
		cs >> q[i];

		CHECK_EQUAL(p[i] , q[i]); 
	} 
}  

TEST(CStream)
{
	CUtil::CStream c; 
	CUtil::CStream cs(c); 
	
	const char t = 1;
	const UINT8 t1 = 2;
	const bool t2 = 1;
	const INT16 t3 = 4;
	const UINT16 t4 = 5;
	const INT32 t5 = 6;
	const UINT32 t6 = 7;
	const INT64 t7 = 8;
	const UINT64 t8 = 9;
	const float t9 = 10;
	const double t10 = 11;
	const CUtil::CharPtr  t11("12" , sizeof("12"));
	const std::string t12 = "13";
	const CUtil::CStream  t13("14" , sizeof("14")); 
	const CUtil::Chunk  t14(15);
	const std::vector<INT32> t15(1);
 	const std::vector<INT32> t16(1);
 	const std::list<INT32> t17(1);
	std::set<INT32> tempSet;
	tempSet.insert(1);
	const std::set<INT32> t18 = tempSet; 
	const std::string t19("t19");
	std::map<INT32 , INT32> tempMap;
	tempMap[1] = 2;
	const std::map<INT32 , INT32> t20 = tempMap;
	const std::pair<INT32 , INT32> t21;

	std::map<INT32 , CUtil::Chunk> t22;
	t22.insert(std::make_pair(1 , CUtil::Chunk(12)));

	std::map<INT32 , std::vector<INT32>> t23;
	t23.insert(std::make_pair(1 , t15));

	std::map<INT32 , std::list<INT32>> t24;
	t24.insert(std::make_pair(1 , t17));

	std::map<INT32 , std::set<INT32>> t25;
	t25.insert(std::make_pair(1 , t18));

	char p = 0;
	UINT8 p1 = 0;
	bool p2 = 0;
	INT16 p3 = 0;
	UINT16 p4 = 0;
	INT32 p5 = 0;
	UINT32 p6 = 0;
	INT64 p7 = 0;
	UINT64 p8 = 0;
	float p9 = 0;
	double p10 = 0;
	CUtil::CharPtr p11;
	std::string p12;
	CUtil::CStream  p13; 
	CUtil::Chunk  p14;
	std::vector<INT32> p15; 
 	std::vector<INT32> p16;
 	std::list<INT32> p17;
 	std::set<INT32> p18; 
	std::string p19;
	std::map<INT32 , INT32> p20;
	std::pair<INT32 , INT32> p21;
	std::map<INT32 , CUtil::Chunk> p22;
	std::map<INT32 , std::vector<INT32>> p23;
	std::map<INT32 , std::list<INT32>> p24;
	std::map<INT32 , std::set<INT32>> p25;
// 
// 	const char cp = 0;
// 	const UINT8 cp1 = 0;
// 	const bool cp2 = 0;
// 	const INT16 cp3 = 0;
// 	const UINT16 cp4 = 0;
// 	const INT32 cp5 = 0;
// 	const UINT32 cp6 = 0;
// 	const INT64 cp7 = 0;
// 	const UINT64 cp8 = 0;
// 	const float cp9 = 0;
// 	const double cp10 = 0;
// 	const CUtil::CharPtr cp11;
// 	const std::string cp12;
// 	const CUtil::CStream  cp13; 
// 	const CUtil::Chunk  cp14;
// 	const std::vector<INT32> cp15; 
// 	const std::vector<INT32> cp16;
// 	const std::list<INT32> cp17;
// 	const std::set<INT32> cp18; 
// 	const std::string cp19;
// 	const std::map<INT32 , INT32> cp20;
// 	const std::pair<INT32 , INT32> cp21;
// 	const std::map<INT32 , CUtil::Chunk> cp22;
// 	const std::map<INT32 , std::vector<INT32>> cp23;
// 	const std::map<INT32 , std::list<INT32>> cp24;
// 	const std::map<INT32 , std::set<INT32>> cp25;

	cs << t << t1 << t2 << t3 << t4 << t5 << t6 << t7 << t8 << t9 << t10 << t11 << t12 << t13 << t14 << t15 << t16 << t17 << t18 << t19 << t20 << t21 << t22 << t23 << t24 << t25 ;
	INT32 nLengthData = cs.GetDataLen();
	CHECK_EQUAL(cs.GetCurPos() , 0);

	cs >> CUtil::Marshal::Begin >> p >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8 >> p9 >> p10 >> p11 >> p12 >> p13 >> p14 >> p15 >> p16 >> p17 >> p18 >> p19 >> p20 >> p21 >> p22 >> p23 >> p24 >> p25 >> CUtil::Marshal::Rollback;//  ;
	INT32 nLengthData2 = cs.GetDataLen();
	CHECK_EQUAL(nLengthData , nLengthData2);
	CHECK_EQUAL(cs.GetCurPos() , 0);

	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 1);
	CUtil::CStream csCopy(cs);
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 2);
	CUtil::CStream csCopyData(cs.Begin() , cs.GetDataLen());
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 2);
	CUtil::CStream csCopyChunk(cs.GetData());
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 3);
	CUtil::CStream csCopyFunc;
	csCopyFunc.Copy(cs);
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 4);
	CUtil::CStream csCopyEqual;
	csCopyEqual = cs;
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 5);
	CUtil::CStream csNotEqual(cs);
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 6);
	csNotEqual >> p;
	CUtil::CStream csNotEqual2(cs);
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() , 7);
	csNotEqual2 >> CUtil::Marshal::Begin >> p;

	csCopy >> p >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8 >> p9 >> p10 >> p11 >> p12 >> p13 >> p14 >> p15 >> p16 >> p17 >> p18 >> p19 >> p20 >> p21 >> p22 >> p23 >> p24 >> p25;//  ;
	CHECK_EQUAL(csCopy.GetDataLen() , nLengthData);
	CHECK_EQUAL(csCopy.GetCurPos() , nLengthData2);
	CHECK_EQUAL(csCopyData.GetCurPos() , 0);
	CHECK_EQUAL(csCopyData.GetDataLen() , nLengthData2);
	CHECK_EQUAL(csCopyChunk.GetCurPos() , 0);
	CHECK_EQUAL(csCopyChunk.GetDataLen() , nLengthData2);
	CHECK_EQUAL(csCopyFunc.GetCurPos() , 0);
	CHECK_EQUAL(csCopyFunc.GetDataLen() , nLengthData2);
	CHECK_EQUAL(csCopyEqual.GetCurPos() , 0);
	CHECK_EQUAL(csCopyEqual.GetDataLen() , nLengthData2);
	CHECK_EQUAL(cs.GetData().GetChunkData()->GetRefCount() ,7);
	CHECK_EQUAL(cs != csCopy && cs == csCopyData && cs == csCopyChunk && cs == csCopyFunc && cs == csCopyEqual, true);
	CHECK_EQUAL(cs != csNotEqual, 1);
	CHECK_EQUAL(cs != csNotEqual2, 1);

	INT32 nCopyPushBack = 10 , nCopyPushBack2 = 0 ,nCopyPushBack3 = 11 , nCopyPushBack4 = 0,nCopyPushBack5 = 12 , nCopyPushBack6 = 23 , nCopyPushBack7 = 23 , nCopyPushBack8 = 23;
	csCopy.Pushback(&nCopyPushBack , sizeof(nCopyPushBack));
	csCopy.Pushback(&nCopyPushBack3 , sizeof(nCopyPushBack3));
	csCopy.Insert((char *)(csCopy.Begin()) + csCopy.GetDataLen() , &nCopyPushBack5 , sizeof(nCopyPushBack5));
	csCopy.Insert(csCopy.End() , &nCopyPushBack7 , sizeof(nCopyPushBack7));
	csCopy.Pop(nCopyPushBack2);
	void * pBuf = NULL;
	csCopy.Pop(pBuf , sizeof(nCopyPushBack4));
	nCopyPushBack4 = *(INT32*)(pBuf);
	csCopy.Pop(nCopyPushBack6);
	csCopy.Pop(nCopyPushBack8);
	CHECK_EQUAL(nCopyPushBack , nCopyPushBack2);
	CHECK_EQUAL(nCopyPushBack3 , nCopyPushBack4);
	CHECK_EQUAL(nCopyPushBack5 , nCopyPushBack6);
	CHECK_EQUAL(nCopyPushBack7 , nCopyPushBack8);

	csCopyData.Clear();
	CHECK_EQUAL(csCopyData.GetCurPos() , 0);
	CHECK_EQUAL(csCopyData.GetDataLen() , 0);

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
	p13 >> p13;
	CHECK_EQUAL(p13.GetDataLen() , 12);
	std::string str((char *)t13.Begin());
	CHECK_EQUAL(str , std::string("14"));
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
}  