/************************************
FileName	:	MsgNameDefine.h
Author		:	generate by tools
HostName	:	woopengcheng
IP			:	192.168.1.107
Version		:	0.0.1
Date		:	2015-09-16 00:04:34
Description	:	用于定义消息的全局唯一名字
************************************/
#ifndef __msg_Client_msg_name_define_h__
#define __msg_Client_msg_name_define_h__
#include "MsgLib/inc/MsgCommon.h" 

namespace Msg
{
	//5 testMulitServerNode declare here
	RPC_DEFINE(testMulitServerNode);

	//5 testParamsAndRpcDatas declare here
	RPC_DEFINE(testParamsAndRpcDatas);

	//5 HandleUserAuth declare here
	RPC_DEFINE(HandleUserAuth);

	//5 HandleSelectDatabase declare here
	RPC_DEFINE(HandleSelectDatabase);

	//5 HandleCreateDatabase declare here
	RPC_DEFINE(HandleCreateDatabase);

	//5 HandleDeleteDatabase declare here
	RPC_DEFINE(HandleDeleteDatabase);

	//5 HandleShowDatabases declare here
	RPC_DEFINE(HandleShowDatabases);

	//5 HandleCreateUser declare here
	RPC_DEFINE(HandleCreateUser);

	//5 HandleDeleteUser declare here
	RPC_DEFINE(HandleDeleteUser);

	//5 HandleModifyUser declare here
	RPC_DEFINE(HandleModifyUser);

	//5 HandleHSet declare here
	RPC_DEFINE(HandleHSet);

	//5 HandleHSetNX declare here
	RPC_DEFINE(HandleHSetNX);

	//5 HandleHSetOW declare here
	RPC_DEFINE(HandleHSetOW);

	//5 HandleHGet declare here
	RPC_DEFINE(HandleHGet);

	//5 HandleHDel declare here
	RPC_DEFINE(HandleHDel);

	//5 HandleHSetIncr declare here
	RPC_DEFINE(HandleHSetIncr);

	//5 HandleHSetIncrFloat declare here
	RPC_DEFINE(HandleHSetIncrFloat);

	//5 HandleHGetKeys declare here
	RPC_DEFINE(HandleHGetKeys);

	//5 HandleHGetVals declare here
	RPC_DEFINE(HandleHGetVals);

	//5 HandleHGetKeyVals declare here
	RPC_DEFINE(HandleHGetKeyVals);

	//5 HandleHScan declare here
	RPC_DEFINE(HandleHScan);

	//5 HandleHCount declare here
	RPC_DEFINE(HandleHCount);

	//5 HandleHDrop declare here
	RPC_DEFINE(HandleHDrop);

	//5 HandleHList declare here
	RPC_DEFINE(HandleHList);

	//5 HandleHMultiSet declare here
	RPC_DEFINE(HandleHMultiSet);

	//5 HandleHMultiGet declare here
	RPC_DEFINE(HandleHMultiGet);

	//5 HandleHMultiDel declare here
	RPC_DEFINE(HandleHMultiDel);

	//5 HandleZSet declare here
	RPC_DEFINE(HandleZSet);

	//5 HandleZGet declare here
	RPC_DEFINE(HandleZGet);

	//5 HandleZDel declare here
	RPC_DEFINE(HandleZDel);

	//5 HandleZTop declare here
	RPC_DEFINE(HandleZTop);

	//5 HandleZRTop declare here
	RPC_DEFINE(HandleZRTop);

	//5 HandleZDrop declare here
	RPC_DEFINE(HandleZDrop);

	//5 HandleZCount declare here
	RPC_DEFINE(HandleZCount);

	//5 HandleZList declare here
	RPC_DEFINE(HandleZList);

	//5 HandleDump declare here
	RPC_DEFINE(HandleDump);

	//5 SyncMasterHandler declare here
	RPC_DEFINE(SyncMasterHandler);

	//5 SlaveStartAuth declare here
	RPC_DEFINE(SlaveStartAuth);

	//5 SlaveSelectDB declare here
	RPC_DEFINE(SlaveSelectDB);

	//5 SlaveRequestSync declare here
	RPC_DEFINE(SlaveRequestSync);

	//5 MasterStartSync declare here
	RPC_DEFINE(MasterStartSync);

	//5 SyncDataToSlave declare here
	RPC_DEFINE(SyncDataToSlave);

}

#endif

