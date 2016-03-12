#include "UnitTest++/UnitTestPP.h"
#include "XMLLib/inc/xml.h"
#include "LogLib/inc/Log.h"
#include "CUtil/inc/CUtil.h" 

static std::string g_strStream = R"(<?xml version="1.0"?>
<RemoteRPC>
	<RPCServer>
		<ListenType>tcp</ListenType>
		<ListenAddress>127.0.0.1</ListenAddress>
		<ListenPort>8003</ListenPort>
	</RPCServer>
</RemoteRPC>
)";

TEST(XML_Test)
{
	XML::XML xml;
	xml.LoadFromString(g_strStream);

	CHECK_EQUAL(xml.GetXMLValue("/RemoteRPC/RPCServer/ListenType"), "tcp");
	CHECK_EQUAL(xml.GetXMLValue("/RemoteRPC/RPCServer/ListenAddress"), "127.0.0.1");
	CHECK_EQUAL(xml.GetXMLValue("/RemoteRPC/RPCServer/ListenPort"), "8003");

}
