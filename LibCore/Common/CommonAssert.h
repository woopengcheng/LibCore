#ifndef __common_assert_h__
#define __common_assert_h__

#include <assert.h>
#include <iostream>
 
extern inline int * ASSERT_FAIL(){return NULL; }

#ifdef  _DEBUG
#define ASSERT (*ASSERT_FAIL() = 0)
#else
#define ASSERT 1

#endif
 
#define Assert(_Expression){ if(!(_Expression)){ std::cout << "Assert! " << __FILE__ << ":" << __LINE__ << ", " << #_Expression; ASSERT; return ;} }
#define Assert_Re0(_Expression){ if(!(_Expression)){ std::cout << "Assert! " << __FILE__ << ":" << __LINE__ << ", " << #_Expression; ASSERT; return 0;} } 
#define Assert_ReF1(_Expression){ if(!(_Expression)){ std::cout << "Assert " << __FILE__ << ":" << __LINE__ << ", " << #_Expression; ASSERT; return -1;} } 
#define Assert_Re(_Expression , _ReturnValue){ if(!(_Expression)){ std::cout << "Assert! " << __FILE__ << ":" << __LINE__ << ", " << #_Expression; ASSERT; return _ReturnValue;} }

#define PAssert(_Expression , Error){ if(!(_Expression)){ std::cout << "Assert! " << __FILE__ << ":" << __LINE__ << ", " << #_Expression << " : " << Error; ASSERT; return ;} }
#define PAssert_Re0(_Expression , Error){ if(!(_Expression)){ std::cout << "Assert! " << __FILE__ << ":" << __LINE__ << ", " << #_Expression << " : " << Error; ASSERT; return 0;} } 
#define PAssert_ReF1(_Expression , Error){ if(!(_Expression)){ std::cout << "Assert " << __FILE__ << ":" << __LINE__ << ", " << #_Expression << " : " << Error; ASSERT; return -1;} } 
#define PAssert_Re(_Expression , _ReturnValue , Error){ if(!(_Expression)){ std::cout << "Assert! " << __FILE__ << ":" << __LINE__ << ", " << #_Expression << " : " << Error; ASSERT; return _ReturnValue;} }

#endif