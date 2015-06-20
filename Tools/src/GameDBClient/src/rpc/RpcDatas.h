#ifndef __Client_rpc_datas_h__
#define __Client_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"

namespace Client
{
	struct UserLogin
	{ 
		std_string localid12;
		UINT16 localid4;
		UINT8 localid2;
		SINT8 userid1;
		INT16 userid3;
		UINT32 userid7;
		LibCore_Chunk localid13;
		INT64 localid8;
		UINT64 userid9;
		double localid10;
		float localid11;
		INT32 localid6;

		UserLogin()
			: localid12( std::string() ) 
			, localid4( 0 ) 
			, localid2( 0 ) 
			, userid1( 0 ) 
			, userid3( 0 ) 
			, userid7( 0 ) 
			, localid13( LibCore::Chunk() ) 
			, localid8( 0 ) 
			, userid9( 0 ) 
			, localid10( 1.0f ) 
			, localid11( 1.0f ) 
			, localid6( 0 ) 
			{}
	}; 
 
}

#endif
