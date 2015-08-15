#include "CUtil/inc/UnitTest.h"
#include "UnitTest++/UnitTestPP.h" 

namespace CUtil
{ 
	TEST(UnitTestTestCHECK)
	{
		int i = 4;
		CHECK_EQUAL(5, ++i); // succeeds
		CHECK_EQUAL(5, i); // succeeds
		CHECK_CLOSE(3.14, 3.1415, 0.01); // succeeds浮点数检查
		CHECK(std::strstr("zaza", "az") != 0); // succeeds
//		CHECK_EQUAL("foo", "bar"); // fails
	}

	SUITE(UnitTestTestCHECKSuite)
	{
		TEST(UnitTestTestCHECK)
		{
			{
				UNITTEST_TIME_CONSTRAINT(50);  //5 在50毫秒内未完成下面的事就fail.需用大括号括起,这里只是测试局部的函数.

				const float oned[2] = { 10, 20 };
				CHECK_ARRAY_EQUAL(oned, oned, 2); // succeeds
				CHECK_ARRAY_CLOSE(oned, oned, 2, 0.00); // succeeds

				const float twod[2][3] = { {0, 1, 2}, {2, 3, 4} };
				CHECK_ARRAY2D_CLOSE(twod, twod, 2, 3, 0.00); // succeeds
			}
		}
		 
	}
	void UnitTestStart( void )
	{
		std::cout << "******************************** Unit test Beg ********************************" << std::endl;
		UnitTest::RunAllTests();
		std::cout << "******************************** Unit test End ********************************" << std::endl;
		 
	} 

}