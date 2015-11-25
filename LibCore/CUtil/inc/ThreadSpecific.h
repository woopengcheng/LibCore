#ifndef __cutil_thead_specific_h__
#define __cutil_thead_specific_h__

#include "CUtil/inc/Common.h"
#include "pthread.h"  
#include "semaphore.h"
#include <fcntl.h>

namespace CUtil
{
	template<typename T> 
	class ThreadSpecific
	{
	public:
		ThreadSpecific()
		{
			pthread_key_create(&mKey, ThreadSpecific<T>::destructor);
		}

		~ThreadSpecific()
		{
			pthread_key_delete(mKey);
		}
	public:
		void set(T* value)
		{
			pthread_setspecific(mKey, value);
		}

		T* get()
		{
			return (T*)pthread_getspecific(mKey);
		}
	private:
		static void destructor(void*)
		{

		}
	private:
		pthread_key_t mKey;
	};

}


#endif // _cutil_thead_specific_h__
