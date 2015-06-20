#ifndef __Server_rpc_datas_h__
#define __Server_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"

namespace Server
{
	struct UserLogin
	{ 
		INT16 userid3;
		LibCore_Chunk localid13;
		float localid11;
		UINT16 localid4;
		INT32 localid6;
		std_string localid12;
		double localid10;
		UINT32 userid7;
		SINT8 userid1;
		INT64 localid8;
		UINT8 localid2;
		UINT64 userid9;

		UserLogin()
			: userid3( 0 ) 
			, localid13( LibCore::Chunk() ) 
			, localid11( 1.0f ) 
			, localid4( 0 ) 
			, localid6( 0 ) 
			, localid12( std::string() ) 
			, localid10( 1.0f ) 
			, userid7( 0 ) 
			, userid1( 0 ) 
			, localid8( 0 ) 
			, localid2( 0 ) 
			, userid9( 0 ) 
			{}
	}; 
 
}

#endif
