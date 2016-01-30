#ifndef __game_db_db_port_h__
#define __game_db_db_port_h__

#define USE_LEVELDB
#ifdef USE_ROCKDB
#elif defined USE_LEVELDB
#include "GameDB/inc/LevelDB.h"
#endif


#endif // __game_db_db_port_h__
