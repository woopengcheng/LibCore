#ifndef __libcore_random_h__
#define __libcore_random_h__
#include "Common/Common.h"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wincrypt.h>
#endif

namespace LibCore
{ 
#ifdef WIN32
	class Random
	{
	public:
		Random();
		~Random();
		INT64  Generator();

	private:
		HCRYPTPROV m_hProv; 
	};

#else
	class Random
	{
	public:
		Random();
		~Random();
		INT64  Generator();

	private: 
		FILE* m_pFile; 
	};
#endif

	extern Random g_objRandomGenerator;
}



#endif