#ifndef __msg_object_h__
#define __msg_object_h__ 
#include "MsgLib/inc/MsgCommon.h" 
#include "Marshal/Marshal.h"
namespace Msg
{ 
	class DLL_EXPORT  Object : public LibCore::Marshal
	{ 
	public:
		Object()
			: m_llObjID(0)
		{
		}

		explicit Object(INT64 llObjectID)
			: m_llObjID(llObjectID)
		{
		}


		bool operator != (const Object & obj) const
		{
			if (m_llObjID == obj.m_llObjID)
			{
				return false;
			}

			return true;
		}

		bool operator == (const Object & obj) const
		{
			if (m_llObjID != obj.m_llObjID)
			{
				return false;
			}

			return true;
		}

		bool operator < (const Object & obj) const
		{
			if (m_llObjID >= obj.m_llObjID)
			{
				return false;
			}

			return true;
		}

		bool operator > (const Object & obj) const
		{
			if (m_llObjID <= obj.m_llObjID)
			{
				return false;
			}

			return true;
		}

	public: 
		virtual LibCore::CStream & marshal(LibCore::CStream & cs);
		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs);

	public:
		INT64   m_llObjID;
	};

	//map的比较函数
	struct DLL_EXPORT  ObjectCmpFunc
	{
		bool operator()(const Object &k1, const Object &k2)const
		{
			return k1 < k2;
		}
	};

	//map的Hash函数
	struct DLL_EXPORT  ObjectHashFunc
	{
		size_t operator()(const Object & _Keyval) const
		{ 
			return ((size_t)_Keyval.m_llObjID);
		}
	};
}
#endif