#ifndef __remote_nodes_0xfffffffff_h__
#define __remote_nodes_0xfffffffff_h__
#include <string>

// ------------------------------------------------

enum ENET_NODES
{
	NETNODE_INVALID ,
	NETNODE_DBSLAVE ,
	NETNODE_DBSERVER ,
	NETNODE_DBMASTER ,

	NETNODE_NUM,
};

//5 这里每个文件都有一份.网络类型节点.需要先宏定义,然后和json中的net_node_name相对应,不然可能不会生效
 static std::string g_netnodes[NETNODE_NUM] = 
{
	"" ,									//5 NETNODE_INVALID
	"dbslave" ,								//5 NETNODE_DBSLAVE  
	"dbserver",								//5 NETNODE_DBSERVER
	"dbmaster",								//5 NETNODE_DBMASTER
};

#endif
