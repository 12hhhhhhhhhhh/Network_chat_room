#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include "custom.h"

//存储好友信息的链表
typedef struct friend_node{
    FRIEND_INFO info;
    struct friend_node *front;
    struct friend_node *next;
}FRIEND_NODE;

extern FRIEND_NODE *head_friend_node;      //好友信息链表的头节点

int friend_list_init(void);
int add_friend_info_node(FRIEND_INFO *info);
int del_friend_info_node(char *id);
FRIEND_INFO * find_friend_info_by_name(char *name);
int modify_remark_by_id(char *id, char *remark);

#endif