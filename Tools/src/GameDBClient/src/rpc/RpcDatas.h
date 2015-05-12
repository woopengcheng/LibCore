#ifndef __Client_rpc_datas_h__
#define __Client_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"

namespace Client
{
	struct UserLogin
	{ 
		INT32 localid6;
		INT16 userid3;
		UINT16 localid4;
		INT64 localid8;
		UINT32 userid7;
		std_string localid12;
		float localid11;
		LibCore_Chunk localid13;
		UINT8 localid2;
		UINT64 userid9;
		double localid10;
		SINT8 userid1;

		UserLogin()
			: localid6( 0 ) 
			, userid3( 0 ) 
			, localid4( 0 ) 
			, localid8( 0 ) 
			, userid7( 0 ) 
			, localid12( std::string() ) 
			, localid11( 1.0f ) 
			, localid13( LibCore::Chunk() ) 
			, localid2( 0 ) 
			, userid9( 0 ) 
			, localid10( 1.0f ) 
			, userid1( 0 ) 
			{}
	}; 
 
}

#endif
