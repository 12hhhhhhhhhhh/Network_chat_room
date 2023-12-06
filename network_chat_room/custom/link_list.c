#include "link_list.h"

FRIEND_NODE *head_friend_node;      //好友信息链表的头节点

/*
    初始化好友信息链表的头节点
*/
int friend_list_init(void){
    head_friend_node = NULL;
    head_friend_node = malloc(sizeof(FRIEND_NODE));
    if(head_friend_node == NULL){
        perror("malloc");
        return -1;
    }
    memset(head_friend_node, 0, sizeof(FRIEND_NODE));
    return 0;
}

/*
    添加好友信息节点
*/
int add_friend_info_node(FRIEND_INFO *info){
    FRIEND_NODE *temnode = NULL;
    temnode = head_friend_node;
    FRIEND_NODE *newnode = malloc(sizeof(FRIEND_NODE));
    if(newnode == NULL){
        perror("malloc");
        return -1;
    }
    memcpy(&(newnode->info), info, sizeof(FRIEND_INFO));
    while(temnode->next){
        temnode = temnode->next;
    }
    newnode->front = temnode;
    newnode->next = NULL;
    temnode->next = newnode;
    temnode = NULL;
    return 0;
}