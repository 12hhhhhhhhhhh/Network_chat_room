#ifndef _NET_TALKROOM_H
#define _NET_TALKROOM_H

// #include "common.h"
// #include "gui_guider.h"
#include "custom.h"
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

extern volatile int flag;
extern client_data client_info;
extern client_data recv_from_server;
extern volatile int socketfd;
extern volatile int recv_socketfd;

int connect_network(volatile int *fd);
void *net_talkroom_recv(void *arg);
void all_init(void);


#endif