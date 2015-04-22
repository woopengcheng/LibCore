#include "GameDB/inc/DBCommandHandler.h"

namespace GameDB
{ 

	BOOL DBCommandHandler::InitCommandMaps()
	{
// 		m_mapCommandHandlers[CMD_AUTHENTICATION] = &ServerConnection::HandleAuthentication;
// 
// 		m_mapCommandHandlers[CMD_SELECT_DATABASE] = &ServerConnection::HandleSelectDatabase;
// 		m_mapCommandHandlers[CMD_CREATE_DATABASE] = &ServerConnection::HandleCreateDatabase;
// 		m_mapCommandHandlers[CMD_DELETE_DATABASE] = &ServerConnection::HandleDeleteDatabase;
// 
// 		m_mapCommandHandlers[CMD_LIST_DATABASES] = &ServerConnection::HandleListDatabases;
// 
// 		// ***************************************************************************
// 
// 		m_mapCommandHandlers[CMD_SYS_ADDUSER] = &ServerConnection::HandleAddUser;
// 		m_mapCommandHandlers[CMD_SYS_DELUSER] = &ServerConnection::HandleDelUser;
// 		m_mapCommandHandlers[CMD_SYS_MODUSER] = &ServerConnection::HandleModUser;
// 
// 		// ***************************************************************************
// 
// 		m_mapCommandHandlers[CMD_RAWDEL] = &ServerConnection::HandleRawdel;
// 		m_mapCommandHandlers[CMD_REMOVE_ALL] = &ServerConnection::HandleRemoveAll;
// 		m_mapCommandHandlers[CMD_DUMP] = &ServerConnection::HandleDump;
// 
// 		m_mapCommandHandlers[CMD_HSET] = &ServerConnection::HandleHSet;
// 		m_mapCommandHandlers[CMD_HGET] = &ServerConnection::HandleHGet;
// 		m_mapCommandHandlers[CMD_HSETNX] = &ServerConnection::HandleHSetNX;
// 		m_mapCommandHandlers[CMD_HSETOW] = &ServerConnection::HandleHSetOW;
// 		m_mapCommandHandlers[CMD_HDEL] = &ServerConnection::HandleHDel;
// 		m_mapCommandHandlers[CMD_HMULTISET] = &ServerConnection::HandleHMultiSet;
// 		m_mapCommandHandlers[CMD_HMULTIGET] = &ServerConnection::HandleHMultiGet;
// 		m_mapCommandHandlers[CMD_HMULTIDEL] = &ServerConnection::HandleHMultiDel;
// 		m_mapCommandHandlers[CMD_HINCR] = &ServerConnection::HandleHIncr;
// 		m_mapCommandHandlers[CMD_HINCR_FLOAT] = &ServerConnection::HandleHIncrFloat;
// 		m_mapCommandHandlers[CMD_HKEYS] = &ServerConnection::HandleHKeys;
// 		m_mapCommandHandlers[CMD_HVALS] = &ServerConnection::HandleHVals;
// 		m_mapCommandHandlers[CMD_HKEYVALS] = &ServerConnection::HandleHKeyVals;
// 		m_mapCommandHandlers[CMD_HSCAN] = &ServerConnection::HandleHScan;
// 		m_mapCommandHandlers[CMD_HSIZE] = &ServerConnection::HandleHSize;
// 		m_mapCommandHandlers[CMD_HDROP] = &ServerConnection::HandleHDrop;
// 		m_mapCommandHandlers[CMD_HLIST] = &ServerConnection::HandleHList;
// 
// 		m_mapCommandHandlers[CMD_HCROSS_KEYS] = &ServerConnection::HandleHCrossKeys;
// 		m_mapCommandHandlers[CMD_HCROSS_VALS] = &ServerConnection::HandleHCrossVals;
// 		m_mapCommandHandlers[CMD_HCROSS_KEYVALS] = &ServerConnection::HandleHCrossKeyVals;
// 
// 		m_mapCommandHandlers[CMD_ZSET] = &ServerConnection::HandleZSet;
// 		m_mapCommandHandlers[CMD_ZDEL] = &ServerConnection::HandleZDel;
// 		m_mapCommandHandlers[CMD_ZGET] = &ServerConnection::HandleZGet;
// 		m_mapCommandHandlers[CMD_ZTOP] = &ServerConnection::HandleZTop;
// 		m_mapCommandHandlers[CMD_ZRTOP] = &ServerConnection::HandleZRtop;
// 		m_mapCommandHandlers[CMD_ZDROP] = &ServerConnection::HandleZDrop;
// 		m_mapCommandHandlers[CMD_ZSIZE] = &ServerConnection::HandleZSize;
// 		m_mapCommandHandlers[CMD_ZLIST] = &ServerConnection::HandleZList;
	
		return TRUE;
	}

}