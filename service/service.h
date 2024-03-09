#ifndef SERVICE_H
#define SERVICE_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "netinet/ip.h"
#include "sys/epoll.h"
#include "mysql/mysql.h"
#include "pthread.h"

//客户端的信息
typedef struct{
    int num;        //序号
    int fd;         //套接字
    int recv_fd;    //接收消息的套接字
    char id[32];    //账号
    char name[32];  //昵称
    char passwd[32];//密码
    char flag[128]; //个性签名
}client_data;


typedef struct{
    char name[32];      //昵称
    char id[32];        //账号
    char passwd[32];    //密码
    char flag[255];     //个性签名
}USER_INFO;

typedef struct node{
    client_data data;
    struct node *next;
}CLINODE;


extern int socketfd;
extern int epollfd;
struct epoll_event epoll_info;
extern CLINODE *client_headnode;
extern int client_count;
extern int iuput_count;

#include "common.h"
#include "cliconect.h"
#include "link_list.h"
#include "database.h"
#include "function.h"
#include "friend_page.h"

#endif