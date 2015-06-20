#ifndef __Client_rpc_datas_h__
#define __Client_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"

namespace Client
{
	struct UserLogin
	{ 
		SINT8 userid1;
		UINT8 localid2;
		INT16 userid3;
		UINT16 localid4;
		INT32 localid6;
		UINT32 userid7;
		INT64 localid8;
		UINT64 userid9;
		double localid10;
		float localid11;
		std_string localid12;
		LibCore_Chunk localid13;

		UserLogin()
			: userid1( 0 ) 
			, localid2( 0 ) 
			, userid3( 0 ) 
			, localid4( 0 ) 
			, localid6( 0 ) 
			, userid7( 0 ) 
			, localid8( 0 ) 
			, userid9( 0 ) 
			, localid10( 1.0f ) 
			, localid11( 1.0f ) 
			, localid12( std::string() ) 
			, localid13( LibCore::Chunk() ) 
			{}
	}; 
 
}

#endif
