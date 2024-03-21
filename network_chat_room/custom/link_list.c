#include "link_list.h"

FRIEND_NODE *head_friend_node;      //好友信息链表的头节点

/*
    初始化好友信息链表的头节点
*/
int friend_list_init(void){
    head_friend_node = NULL;
    head_friend_node = (FRIEND_NODE *)malloc(sizeof(FRIEND_NODE));
    perror("malloc");
    printf("malloc1\r\n");
    if(head_friend_node == NULL){
        printf("malloc2\r\n");
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
    FRIEND_NODE *newnode = (FRIEND_NODE *)malloc(sizeof(FRIEND_NODE));
    if(newnode == NULL){
        perror("malloc");
        DEBUG("malloc error!\r\n");
        return -1;
    }
    memcpy(&(newnode->info), info, sizeof(FRIEND_INFO));
    while(temnode->next){
        temnode = temnode->next;
    }
    DEBUG("newnode:%s\r\n", newnode->info.news[0]);
    newnode->front = temnode;
    newnode->next = NULL;
    temnode->next = newnode;
    temnode = NULL;
    return 0;
}

/*
    删除好友信息节点
*/
int del_friend_info_node(char *id) {
    FRIEND_NODE *temnode = NULL;
    temnode = head_friend_node;
    while(temnode->next){
        temnode = temnode->next;
        if(strcmp(id, temnode->info.id) == 0) {
            break;
        }
    }
    temnode->front->next = temnode->next;
    temnode->next->front = temnode->front;
    free(temnode);
    temnode = NULL;
    return 0;
}

/*
    通过昵称或备注在好友链表中查找好友信息
*/
FRIEND_INFO * find_friend_info_by_name(char *name) {
    FRIEND_NODE *temnode = NULL;
    temnode = head_friend_node;
    while(temnode->next){
        temnode = temnode->next;
        if((strcmp(temnode->info.name, name) == 0) || (strcmp(temnode->info.remark, name) == 0)){
            return &(temnode->info);
        }
    }
    return NULL;
}

/*
    通过id查找好友信息
*/
FRIEND_INFO * find_friend_info_by_id(char *id) {
    FRIEND_NODE *temnode = NULL;
    temnode = head_friend_node;
    while(temnode->next){
        temnode = temnode->next;
        if(strcmp(temnode->info.id, id) == 0){
            return &(temnode->info);
        }
    }
    return NULL;
}

/*
    通过id修改好友的备注信息
*/
int modify_remark_by_id(char *id, char *remark) {
    FRIEND_NODE *temnode = NULL;
    temnode = head_friend_node;
    while(temnode->next){
        temnode = temnode->next;
        if((strcmp(temnode->info.id, id) == 0)){
            strcpy(temnode->info.remark, remark);
            break;
        }
    }
    return 0;
}