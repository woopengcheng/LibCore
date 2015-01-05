#ifndef __msg_i_msg_callable_object_h__
#define __msg_i_msg_callable_object_h__ 
#include "ICallableObject.h" 
#include "InnerMsg.h"

namespace Msg
{   
	class DLL_EXPORT IMsgCallableObject : public ICallableObject
	{
		public:
			IMsgCallableObject(InnerMsg * pInnerMsg , Object id)
				:ICallableObject(id)
			{
				pInnerMsg->AddCallableObject(this);
			}
	};

}
#endif