#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include "custom.h"

extern FRIEND_NODE *head_friend_node;      //好友信息链表的头节点

int friend_list_init(void);
int add_friend_info_node(FRIEND_INFO *info);

#endif