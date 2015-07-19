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

//5 ����ÿ���ļ�����һ��.�������ͽڵ�.��Ҫ�Ⱥ궨��,Ȼ���json�е�net_node_name���Ӧ,��Ȼ���ܲ�����Ч
 static std::string g_netnodes[NETNODE_NUM] = 
{
	"" ,									//5 NETNODE_INVALID
	"dbslave" ,								//5 NETNODE_DBSLAVE  
	"dbserver",								//5 NETNODE_DBSERVER
	"dbmaster",								//5 NETNODE_DBMASTER
};

#endif
