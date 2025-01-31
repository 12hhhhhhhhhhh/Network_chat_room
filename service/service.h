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
#include "sys/prctl.h"
#include "time.h"

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

typedef enum{
    AGREE = 0,
    REFUSE
}APPLY_REPLY_FLAG;

//表示好友申请的结果
typedef enum{
    APPLY_FAIL = -1,    //申请失败
    APPLY_SUCCESS,      //申请成功
    APPLY_ALREADY,      //已申请过
    APPLY_FULL          //对方申请过多
}FRIEND_APPLY_RESULT;

extern int socketfd;
extern int epollfd;
struct epoll_event epoll_info;
extern CLINODE *client_headnode;
extern int client_count;
extern int iuput_count;

#include "common.h"
#include "print_ext.h"
#include "cliconect.h"
#include "link_list.h"
#include "database.h"
#include "function.h"
#include "friend_page.h"
#include "initialize.h"

#endif