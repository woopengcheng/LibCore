#ifndef __Server_rpc_datas_h__
#define __Server_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"

namespace Server
{
	struct UserLogin
	{ 
		float localid11;
		LibCore_Chunk localid13;
		UINT64 userid9;
		UINT32 userid7;
		std_string localid12;
		INT16 userid3;
		INT32 localid6;
		UINT16 localid4;
		double localid10;
		SINT8 userid1;
		UINT8 localid2;
		INT64 localid8;

		UserLogin()
			: localid11( 1.0f ) 
			, localid13( LibCore::Chunk() ) 
			, userid9( 0 ) 
			, userid7( 0 ) 
			, localid12( std::string() ) 
			, userid3( 0 ) 
			, localid6( 0 ) 
			, localid4( 0 ) 
			, localid10( 1.0f ) 
			, userid1( 0 ) 
			, localid2( 0 ) 
			, localid8( 0 ) 
			{}
	}; 
 
}

#endif
