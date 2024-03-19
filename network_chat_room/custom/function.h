#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "custom.h"

typedef enum{
    WRITE_FAIL = 0,
    WRITE_SUCCESS
}WRITE_RESULT;

typedef struct{
    int num;    //消息类型
    int len;    //消息体的长度
}MESSAGEHEAD;

typedef struct{
    MESSAGEHEAD head;   //消息头
    // void *data;         //消息体
}MESSAGE;

typedef enum{
    INPUT_ACCOUNT_PAGEMARK = 0,
    CREATE_ACCOUNT_PAGEMARK,
    MESSAGE_PAGEMARK,
    FRIEND_PAGEMARK,
    CIRCLE_PAGEMARK,
    OWNER_PAGEMARK
}PAGE_LOCATION;

pthread_rwlock_t* page_location_rwlock;
PAGE_LOCATION page_location;

int packet_write(int fd,int num, void *buf, int len);
int packet_read(int fd, MESSAGE *message, int len);
int check_num_char(const char *buf, int len);

int judge_id_format(char *buf);

#endif