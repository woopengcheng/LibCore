#include "CUtil/inc/CRTTI.h"
#include "CUtil/inc/CObject.h"
#include "UnitTest++/UnitTestPP.h"
 
TEST(CRTTI)
{
	const INT32 nA = 1;
	const INT32 nB = 2;
	const INT32 nC = 3;
	const INT32 nD = 4;
	class A : virtual public CUtil::CObject
	{
		RTTI(A , 1 , BASE(CObject));
	}; 
	class B : virtual public A
	{
		RTTI(B , 2 , BASE(A));
	}; 
	class C : virtual public A
	{
		RTTI(C , 3 , BASE(A));
	}; 
	class D : virtual public C , virtual public B
	{
		RTTI(D , 4 , BASE(C) , BASE(B));
	}; 
	class E : virtual public D
	{
		RTTI(E , 5 , BASE(D));
	}; 
	class F : virtual public CUtil::CObject
	{
		RTTI(F , 6 , BASE(CUtil::CObject));
	}; 
	class G : virtual public E , virtual public F
	{
		RTTI(G , 7 , BASE(E) , BASE(F));
	}; 
	class H : public C , public B , public F 
	{
		RTTI(G , 8 , BASE(C) , BASE(B) , BASE(F));
	}; 

	A a; 
	CHECK_EQUAL(a.GetRTTI()->GetClassGUID() , 1);
	CHECK_EQUAL(a.GetRTTI()->GetClassName() , "A");
	CHECK_EQUAL(a.GetRTTI()->GetClassSize() , sizeof(A));

	CHECK_EQUAL(a.GetRTTI()->IsDerivedFrom(BASE(CUtil::CObject)) , TRUE);
	CHECK_EQUAL(B::GetClass()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(C::GetClass()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(D::GetClass()->IsDerivedFrom(BASE(CUtil::CObject)) , TRUE);
	CHECK_EQUAL(D::GetClass()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(D::GetClass()->IsDerivedFrom(BASE(B)) , TRUE);
	CHECK_EQUAL(D::GetClass()->IsDerivedFrom(BASE(C)) , TRUE);
	CHECK_EQUAL(E::GetClass()->IsDerivedFrom(BASE(CUtil::CObject)) , TRUE);
	CHECK_EQUAL(E::GetClass()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(E::GetClass()->IsDerivedFrom(BASE(B)) , TRUE);
	CHECK_EQUAL(E::GetClass()->IsDerivedFrom(BASE(C)) , TRUE);
	CHECK_EQUAL(E::GetClass()->IsDerivedFrom(BASE(D)) , TRUE);
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(CUtil::CObject)) , TRUE); 
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(B)) , TRUE);
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(C)) , TRUE);
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(D)) , TRUE);
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(E)) , TRUE);
	CHECK_EQUAL(G::GetClass()->IsDerivedFrom(BASE(F)) , TRUE);
	CHECK_EQUAL(H::GetClass()->IsDerivedFrom(BASE(CUtil::CObject)) , TRUE); 
	CHECK_EQUAL(H::GetClass()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(H::GetClass()->IsDerivedFrom(BASE(B)) , TRUE);
	CHECK_EQUAL(H::GetClass()->IsDerivedFrom(BASE(C)) , TRUE); 
	CHECK_EQUAL(H::GetClass()->IsDerivedFrom(BASE(F)) , TRUE);

	CUtil::CObject * pCObject = H::CreateObject();
	CHECK_EQUAL(pCObject->GetRTTI()->IsDerivedFrom(BASE(CUtil::CObject)) , TRUE); 
	CHECK_EQUAL(pCObject->GetRTTI()->IsDerivedFrom(BASE(A)) , TRUE);
	CHECK_EQUAL(pCObject->GetRTTI()->IsDerivedFrom(BASE(B)) , TRUE);
	CHECK_EQUAL(pCObject->GetRTTI()->IsDerivedFrom(BASE(C)) , TRUE); 
	CHECK_EQUAL(pCObject->GetRTTI()->IsDerivedFrom(BASE(F)) , TRUE);

	SAFE_DELETE(pCObject);
}