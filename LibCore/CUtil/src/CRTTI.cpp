#include "CUtil/inc/CRTTI.h"

namespace CUtil
{
	CRTTI::CRTTI(const char * pName , INT32 nGUID , pCreateFunc pFunc , INT32 nClassSize , CRTTI * pP0 /*= NULL */, CRTTI * pP1 /*= NULL */, CRTTI * pP2 /*= NULL */, CRTTI * pP3 /*= NULL*/)
		: m_strClassName(pName)
		, m_pCreateFunc(pFunc)
		, m_nClassGUID(nGUID)
		, m_nClassSize(nClassSize)
	{
		memset(m_pParent , 0 , sizeof(m_pParent));

		m_pParent[0] = pP0;
		m_pParent[1] = pP1;
		m_pParent[2] = pP2;
		m_pParent[3] = pP3;

		InsertRuntimeClass(nGUID , pName , this);
	}

	CRTTI::~CRTTI()
	{

	}

	CRTTI	* CRTTI::GetRuntimeClass(const std::string & strName)
	{
		CollectionRTTIByNameT::iterator iter = m_sRTTIByName.find(strName);
		if (iter != m_sRTTIByName.end())
		{
			return iter->second;
		}

		return NULL;
	}

	CRTTI	* CRTTI::GetRuntimeClass(INT32 nClassGUID)
	{
		CollectionRTTIByGUIDT::iterator iter = m_sRTTIByGUID.find(nClassGUID);
		if (iter != m_sRTTIByGUID.end())
		{
			return iter->second;
		}

		return NULL;
	}

	BOOL CRTTI::InsertRuntimeClass(INT32 nClassGUID , const std::string & strName , CRTTI * pClass)
	{
		MsgAssert_Re0(GetRuntimeClass(nClassGUID) && GetRuntimeClass(strName) , "the same name class insert in RTTI define.");
		m_sRTTIByGUID.insert(std::make_pair(nClassGUID , pClass));
		m_sRTTIByName.insert(std::make_pair(strName , pClass));

		return TRUE;
	}

}

