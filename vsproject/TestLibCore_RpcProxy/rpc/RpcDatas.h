#ifndef __Proxy_rpc_datas_h__
#define __Proxy_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"

namespace Proxy
{
	struct UserLogin
	{ 
		std_string localid12;
		UINT8 localid2;
		UINT32 userid7;
		SINT8 userid1;
		UINT64 userid9;
		INT32 localid6;
		UINT16 localid4;
		double localid10;
		LibCore_Chunk localid13;
		float localid11;
		INT16 userid3;
		INT64 localid8;

		UserLogin()
			: localid12( std::string() ) 
			, localid2( 0 ) 
			, userid7( 0 ) 
			, userid1( 0 ) 
			, userid9( 0 ) 
			, localid6( 0 ) 
			, localid4( 0 ) 
			, localid10( 1.0f ) 
			, localid13( LibCore::Chunk() ) 
			, localid11( 1.0f ) 
			, userid3( 0 ) 
			, localid8( 0 ) 
			{}
	}; 
 
}

#endif
