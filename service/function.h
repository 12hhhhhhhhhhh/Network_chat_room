#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "service.h"

typedef enum{
    WRITE_FAIL = 0,
    WRITE_SUCCESS
}WRITE_RESULT;

typedef struct{
    int num;    //消息类型
    int len;    //消息体的长度
}MESSAGEHEAD;

typedef struct{
    MESSAGEHEAD   head;   //消息头
    char payload[9600];   //消息体
}MESSAGE;

int packet_write(int fd,int num);

#endif