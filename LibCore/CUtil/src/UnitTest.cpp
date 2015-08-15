#include "CUtil/inc/UnitTest.h"
#include "UnitTest++/UnitTestPP.h" 

namespace CUtil
{ 
	TEST(UnitTestTestCHECK)
	{
		int i = 4;
		CHECK_EQUAL(5, ++i); // succeeds
		CHECK_EQUAL(5, i); // succeeds
		CHECK_CLOSE(3.14, 3.1415, 0.01); // succeeds���������
		CHECK(std::strstr("zaza", "az") != 0); // succeeds
//		CHECK_EQUAL("foo", "bar"); // fails
	}

	SUITE(UnitTestTestCHECKSuite)
	{
		TEST(UnitTestTestCHECK)
		{
			{
				UNITTEST_TIME_CONSTRAINT(50);  //5 ��50������δ���������¾�fail.���ô���������,����ֻ�ǲ��Ծֲ��ĺ���.

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