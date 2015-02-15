#ifndef __libcore_string_ex_h__
#define __libcore_string_ex_h__
#include "Common/Common.h"
#include "Common/LibCore.h"
 
namespace LibCore
{
	class StringExBase 
	{
	public:
		virtual void  Init(const char * pStr , UINT32 unLength) = 0;
		virtual const char * c_str() = 0;
	};

	template<UINT32 L>
	class StringEx : public StringExBase
	{
	public:
		StringEx(const char * pStr , UINT32 unLength)
		{
			Init(pStr , unLength);
		}
		StringEx(const char * pStr)
		{
			Init(pStr , strlen(pStr)); //5 故意少拷贝一个.结尾时自动加上.
		}

		virtual void  Init(const char * pStr , UINT32 unLength)
		{
			INT32 nSize = __min(unLength , L);
			strncpy(m_szString , nSize , pStr);
			m_szString[nSize] = 0;
		}

		StringEx<L> & operator = (const char * pStr)
		{
			Init(pStr);

			return * this;
		}

		operator const char * () const
		{
			return m_szString;
		}

		operator char * () const
		{
			return m_szString;
		}

		const char * c_str() const
		{
			return m_szString;
		}

		bool operator==(const char* val) const
		{
			return LibCore::strcmp(val,m_szString) == 0;
		}

		bool operator!=(const char* val) const
		{
			return LibCore::strcmp(val,m_szString) != 0;
		}
		
		UINT32 length()
		{
			return strlen(m_szString);
		}
	protected:
		char m_szString[L];
	};
}


#endif