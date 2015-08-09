/************************************
FileName	:	RpcDatas.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-08-09 23:30:44
Description	:	网络消息的数据域.
************************************/
#ifndef __Client_rpc_datas_h__
#define __Client_rpc_datas_h__
#include "Common/Common.h"
#include "Common/Chunk.h"
#include "MsgLib/inc/Parameter.h"
#include "MsgLib/inc/ParameterHelper.h"

namespace Client
{
	class TestRpcData: public LibCore::Marshal
	{ 
		public:
		int p1;
		unsigned int p2;
		char p3;
		unsigned char p4;
		std::vector<INT32> p5;
		long p6;
		time_t p7;
		short p8;
		unsigned short p9;
		double p10;
		float p11;
		std_string p12;
		LibCore_Chunk p13;

		TestRpcData()
			: p1( 111 ) 
			, p2( 21 ) 
			, p3( 0 ) 
			, p4( 0 ) 
			, p5( std::vector<INT32>(1) ) 
			, p6( 0 ) 
			, p7( 0 ) 
			, p8( 0 ) 
			, p9( 0 ) 
			, p10( 1.0f ) 
			, p11( 1.0f ) 
			, p12( std::string() ) 
			, p13( LibCore::Chunk() ) 
			{}
		TestRpcData(const TestRpcData & val)
		{ 
			p1 = val.p1;
			p2 = val.p2;
			p3 = val.p3;
			p4 = val.p4;
			p5 = val.p5;
			p6 = val.p6;
			p7 = val.p7;
			p8 = val.p8;
			p9 = val.p9;
			p10 = val.p10;
			p11 = val.p11;
			p12 = val.p12;
			p13 = val.p13;
		} 

		virtual LibCore::CStream & marshal(LibCore::CStream & cs)
		{ 
			cs << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << p9 << p10 << p11 << p12 << p13;
			return cs; 
		} 

		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs)
		{ 
			cs >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8 >> p9 >> p10 >> p11 >> p12 >> p13;
			return cs; 
		} 

	}; 
 
	class TestRpcData2: public LibCore::Marshal
	{ 
		public:
		SINT8 p1;
		UINT8 p2;
		INT16 p3;
		UINT16 p4;
		INT32 p6;
		UINT32 p7;
		INT64 p8;
		UINT64 p9;

		TestRpcData2()
			: p1( 0 ) 
			, p2( 0 ) 
			, p3( 0 ) 
			, p4( 0 ) 
			, p6( 0 ) 
			, p7( 0 ) 
			, p8( 0 ) 
			, p9( 0 ) 
			{}
		TestRpcData2(const TestRpcData2 & val)
		{ 
			p1 = val.p1;
			p2 = val.p2;
			p3 = val.p3;
			p4 = val.p4;
			p6 = val.p6;
			p7 = val.p7;
			p8 = val.p8;
			p9 = val.p9;
		} 

		virtual LibCore::CStream & marshal(LibCore::CStream & cs)
		{ 
			cs << p1 << p2 << p3 << p4 << p6 << p7 << p8 << p9;
			return cs; 
		} 

		virtual LibCore::CStream & unMarshal(LibCore::CStream & cs)
		{ 
			cs >> p1 >> p2 >> p3 >> p4 >> p6 >> p7 >> p8 >> p9;
			return cs; 
		} 

	}; 
 
}//Client

namespace Msg
{ 
	enum PARAMETER_TYPE_USER_DEFINES 
	{ 
		PARAMETER_TYPE_USER_DEFINE_FIRST = Msg::PARAMETER_TYPE_USER_DEFINE  ,
		PARAMETER_TYPE_USER_DEFINE_TestRpcData,
		PARAMETER_TYPE_USER_DEFINE_TestRpcData2,
	}; 
 
	GEN_PARAMTER_HELPER(Client::TestRpcData , PARAMETER_TYPE_USER_DEFINE_TestRpcData);
	GEN_PARAMTER_HELPER(Client::TestRpcData2 , PARAMETER_TYPE_USER_DEFINE_TestRpcData2);
}

#endif
