#ifndef NET_TALKROOM_H
#define NET_TALKROOM_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "arpa/inet.h"
#include "netinet/in.h"

#include "common.h"
#include "gui_guider.h"
#include "custom.h"
//客户端的信息
typedef struct{
    int num;
    int fd;//套接字
    char id[32];//账号
    char name[32];//昵称
    char passwd[32];//密码
}client_data;

extern int flag;
extern client_data client_info;
extern client_data recv_from_server;
extern volatile int socketfd;

int connect_network(void);
void *net_talkroom_run(void *arg);

#endif