#include "CUtil/inc/CUtil.h"
#include "CUtil/inc/Iconv.h"
#include "UnitTest++/UnitTestPP.h"

TEST(strcmp)
{
	const char * pStr1 = "strcmp";
	const char * pStr2 = "strcmp"; 
	CHECK_EQUAL(CUtil::strcmp(pStr1 , pStr2), 0); // succeeds 
	CHECK_EQUAL(CUtil::strcmp("" , "") , 0); // succeeds 

	const char * p1 = "strCMP";
	const char * p2 = "strcmp";
	CHECK_EQUAL(CUtil::stricmp(p1 , p2) , 0);
} 

TEST(atoi)
{
	const char * pStr1 = "-1";
	const char * pStr2 = "4294967295";
	const char * pStr3 = "9223372036854775807";
	std::string str1 = pStr1;
	std::string str2 = pStr2;
	CHECK_EQUAL(CUtil::atoi(pStr1), -1); // succeeds 
	CHECK_EQUAL(CUtil::atoi(pStr2) , 4294967295); // succeeds 
	CHECK_EQUAL(CUtil::atoi(str1), -1); // succeeds 
	CHECK_EQUAL(CUtil::atoi(str2) , 4294967295); // succeeds 
	CHECK_EQUAL(CUtil::atoi(pStr3) , 0x7FFFFFFFFFFFFFFF); // succeeds 

	char *endptr;
	char npstr[]="-1238abc";
	INT64 ret = CUtil::strtoll(npstr, &endptr, 10);
	CHECK_EQUAL(ret , -1238);
	CHECK_EQUAL(CUtil::strcmp(endptr , "abc") , 0);

	ret = CUtil::strtoll(npstr, &endptr, 16);
	CHECK_EQUAL(ret , -0x1238abc);
	CHECK_EQUAL(CUtil::strcmp(endptr , "") , 0);

	ret = CUtil::strtoll(npstr, &endptr, 8);
	CHECK_EQUAL(ret , -0123);
	CHECK_EQUAL(CUtil::strcmp(endptr , "8abc") , 0);

	ret = CUtil::strtoll(npstr, &endptr, 2);
	CHECK_EQUAL(ret , -01);
	CHECK_EQUAL(CUtil::strcmp(endptr , "238abc") , 0);

	UINT64 llRet = CUtil::strtoull(&npstr[1], &endptr, 10);
	CHECK_EQUAL(llRet , 1238);
	CHECK_EQUAL(CUtil::strcmp(endptr , "abc") , 0);

	llRet = CUtil::strtoull(&npstr[1], &endptr, 16);
	CHECK_EQUAL(llRet , 0x1238abc);
	CHECK_EQUAL(CUtil::strcmp(endptr , "") , 0);

	llRet = CUtil::strtoull(&npstr[1], &endptr, 8);
	CHECK_EQUAL(llRet , 0123);
	CHECK_EQUAL(CUtil::strcmp(endptr , "8abc") , 0);

	llRet = CUtil::strtoull(&npstr[1], &endptr, 2);
	CHECK_EQUAL(llRet , 01);
	CHECK_EQUAL(CUtil::strcmp(endptr , "238abc") , 0);

	char * pf = "-1.123456789";
	float f = 0.0f;
	double df = 0.0f;
	std::string strf = pf;
	f = (float)CUtil::atof(pf);
	df = CUtil::atof(pf);
	CHECK_EQUAL(df , -1.123456789);
	CHECK_EQUAL(f , -1.1234568f);
	f = (float)CUtil::atof(strf);
	CHECK_EQUAL(f , -1.1234568f);
	CHECK_EQUAL(df , -1.123456789);
} 

TEST(itoa)
{
	INT64 ll = 0xffffffffffffffff;
	CHECK_EQUAL(CUtil::itoa(ll) , "-1");
 
	float f = -1.123456789f;
	char pf[1024];;
	CUtil::ftoa(pf , f);
	CHECK_EQUAL(CUtil::strcmp(pf , "-1.123457") , 0);
} 

TEST(floatcmp)
{ 
	CHECK_EQUAL(CUtil::floatcmp(0.0f , -0.0f) , false);
	CHECK_EQUAL(CUtil::floatcmp(0.1f , 0.1f) , false);
	CHECK_EQUAL(CUtil::floatcmp(0.0001f , 0.00001f) , true);
	CHECK_EQUAL(CUtil::floatcmp(0.000001f , 0.0000001f) , false);
} 

TEST(strncpy)
{ 
	const char * p1 = "0.123456789";
	char p2[1024];
	CUtil::strncpy(p2 , strlen(p1) + 1 , p1);

	CHECK_EQUAL(CUtil::strcmp(p2 , p1) , 0); 
} 

struct StrlowerFixture
{
	StrlowerFixture() 
	{ 
		pStr1 = "Strlower";
		pStr2 = "strLOWER"; 

		pStr1 = CUtil::strlower(pStr1.c_str());
		pStr2 = CUtil::strlower(pStr2.c_str()); 
	}
	~StrlowerFixture() { /* some teardown */ }

	std::string pStr1;
	std::string pStr2; 
};
TEST_FIXTURE(StrlowerFixture, strlower)
{
	CHECK_EQUAL(pStr2 , pStr1); // succeeds 
}

TEST(strupper)
{
	char * pStr1 = "Strupper";
	char * pStr2 = "strUPPER"; 
	CHECK_EQUAL(CUtil::strupper(pStr1) , CUtil::strupper(pStr2)); // succeeds 
}

TEST(is_between)
{ 
	CHECK_EQUAL(CUtil::is_between(1 , 1 , 2) , FALSE); // succeeds 
	CHECK_EQUAL(CUtil::is_between(1 , 2 , 2) , TRUE); // succeeds 
	CHECK_EQUAL(CUtil::is_between(1 , 3 , 2) , TRUE); // succeeds 
	CHECK_EQUAL(CUtil::is_between(1.0f , 1.0f , 2.0f) , FALSE); // succeeds 
	CHECK_EQUAL(CUtil::is_between(1.0f , 1.0f , 1.0f) , TRUE); // succeeds 
	CHECK_EQUAL(CUtil::is_between(1.0f , 3.0f , 2.0f) , TRUE); // succeeds 
}

TEST(clamp)
{ 
	CHECK_EQUAL(CUtil::clamp(2 , 1 , 2) , 2); // succeeds 
	CHECK_EQUAL(CUtil::clamp(2 , 1 , 1) , 1); // succeeds  
	CHECK_EQUAL(CUtil::clamp(2.0f , 1.0f , 2.0f) , 2.0f); // succeeds 
	CHECK_EQUAL(CUtil::clamp(12.0f , 1.0f , 1.0f) , 1.0f); // succeeds  
}

TEST(strtobool)
{ 
	CHECK_EQUAL(CUtil::strtobool("True") , 1); // succeeds 
	CHECK_EQUAL(CUtil::strtobool("False") , 0); // succeeds  
	CHECK_EQUAL(CUtil::strtobool("1") , 1); // succeeds 
	CHECK_EQUAL(CUtil::strtobool("0") , 0); // succeeds  
	CHECK_EQUAL(CUtil::strtobool("2") , 1); // succeeds 
	CHECK_EQUAL(CUtil::strtobool("1w") , 1); // succeeds  
}

TEST(isNumber)
{ 
	CHECK_EQUAL(CUtil::isNumber("123456789") , 1); // succeeds 
	CHECK_EQUAL(CUtil::isNumber("0xffffffff") , 0); // succeeds   
}

TEST(tohex)
{ 
	INT64 ll = 4294967295;
	char p[1024];
	CUtil::tohex(ll , p , 1024);

	CHECK_EQUAL(CUtil::strcmp(p , "ffffffff") , 0); // succeeds 

// 	const char * p1 = "81985529216486895";
// 	char  p2[1024];
// 	INT32 nSize = 0;
// 	CUtil::tohex(p1 , (UINT32)(strlen(p1) + 1) , p2 , nSize);
}

TEST(create_token)
{ 
	char p[1024];
	CUtil::create_token(p , 1024);

	bool bSame = false;
	static const char s_objTokenPool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()-=+_";
	for (INT32 i = 0;i < 1024;++i)
	{
		for (INT32 j = 0;j < sizeof(s_objTokenPool);++j)
		{
			if (s_objTokenPool[j] == p[i])
			{
				bSame = true;
				break;
			}			
		}
		CHECK_EQUAL(bSame , true);
		bSame = false;
	}
}


TEST(strncat)
{ 
	char *p1 = "123456";
	char *p2 = "789";
	char p3[1024] = {0};
	CUtil::strncat(p3 , p1 , (UINT32)(strlen(p1) + 1));
	CUtil::strncat(p3 , p2 , (UINT32)(strlen(p2) + 1));

	CHECK_EQUAL(CUtil::strcmp(p3 , "123456789") , 0);
	 
}

TEST(ParseHumanSizeFromString)
{ 
	char *p1 = "10K";
	char *p2 = "10M";
	char *p3 = "1G";
	char *p4 = "10240K"; 
	INT64 nSize = CUtil::ParseHumanSizeFromString(p1);
	UINT64 nValue = 1 * 1024 * 1024 * 1024;
	CHECK_EQUAL(nSize , 10 * 1024);
	nSize = CUtil::ParseHumanSizeFromString(p2);
	CHECK_EQUAL(nSize , 10 * 1024 * 1024 );
	nSize = CUtil::ParseHumanSizeFromString(p3);
	CHECK_EQUAL(nSize ,  nValue);
	nSize = CUtil::ParseHumanSizeFromString(p4);
	CHECK_EQUAL(nSize , 10 * 1024 * 1024); 
}

TEST(Compress)
{ 
	std::string strUncompressed;
	char *p1 = "10Kasdfadfasdfadfadfadfasdfa";
	CUtil::Compress(p1 , (UINT32)(strlen(p1) + 1) , strUncompressed);

	std::string strUncompressed2;
	CUtil::Uncompress(strUncompressed.c_str() , (UINT32)(strUncompressed.length() + 1) , strUncompressed2);
	CHECK_EQUAL(strUncompressed2 , std::string(p1 , strlen(p1) + 1)); 
}

TEST(IConv)
{
	std::string strUTF8 = "UTF8-编码";
	std::string strGBK = CUtil::UTF8ToGBK(strUTF8);
	std::string strNewUTF8 = CUtil::GBKToUTF8(strGBK);

	CHECK_EQUAL(strNewUTF8 , strUTF8);
}