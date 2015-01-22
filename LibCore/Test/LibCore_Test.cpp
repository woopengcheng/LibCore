#include "Common/LibCore.h"
#include "UnitTest++/UnitTestPP.h"

TEST(strcmp)
{
	const char * pStr1 = "strcmp";
	const char * pStr2 = "strcmp"; 
	CHECK_EQUAL(LibCore::strcmp(pStr1 , pStr2), 0); // succeeds 
} 

struct StrlowerFixture
{
	StrlowerFixture() 
	{ 
		pStr1 = "Strlower";
		pStr2 = "strLOWER"; 

		pStr1 = LibCore::strlower(pStr1.c_str());
		pStr2 = LibCore::strlower(pStr2.c_str()); 
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
	CHECK_EQUAL(LibCore::strupper(pStr1) , LibCore::strupper(pStr2)); // succeeds 
}

TEST(is_between)
{ 
	CHECK_EQUAL(LibCore::is_between(1 , 1 , 2) , FALSE); // succeeds 
	CHECK_EQUAL(LibCore::is_between(1 , 2 , 2) , TRUE); // succeeds 
	CHECK_EQUAL(LibCore::is_between(1 , 3 , 2) , TRUE); // succeeds 
	CHECK_EQUAL(LibCore::is_between(1.0f , 1.0f , 2.0f) , FALSE); // succeeds 
	CHECK_EQUAL(LibCore::is_between(1.0f , 1.0f , 1.0f) , TRUE); // succeeds 
	CHECK_EQUAL(LibCore::is_between(1.0f , 3.0f , 2.0f) , TRUE); // succeeds 
}

TEST(clamp)
{ 
	CHECK_EQUAL(LibCore::clamp(2 , 1 , 2) , 2); // succeeds 
	CHECK_EQUAL(LibCore::clamp(2 , 1 , 1) , 1); // succeeds  
	CHECK_EQUAL(LibCore::clamp(2.0f , 1.0f , 2.0f) , 2.0f); // succeeds 
	CHECK_EQUAL(LibCore::clamp(12.0f , 1.0f , 1.0f) , 1.0f); // succeeds  
}

TEST(strtobool)
{ 
	CHECK_EQUAL(LibCore::strtobool("True") , 1); // succeeds 
	CHECK_EQUAL(LibCore::strtobool("False") , 0); // succeeds  
	CHECK_EQUAL(LibCore::strtobool("1") , 1); // succeeds 
	CHECK_EQUAL(LibCore::strtobool("0") , 0); // succeeds  
	CHECK_EQUAL(LibCore::strtobool("2") , 1); // succeeds 
	CHECK_EQUAL(LibCore::strtobool("1w") , 1); // succeeds  
}