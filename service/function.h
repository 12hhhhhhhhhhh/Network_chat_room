#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "service.h"

typedef enum{
    WRITE_FAIL = 0,
    WRITE_SUCCESS
}WRITE_RESULT;

typedef struct{
    int num;    //消息类型
    int fd;     //套接字
    int len;    //消息体的长度
    WRITE_RESULT flag;   //是否发送成功的标志
}MESSAGEHEAD;

typedef struct{
    MESSAGEHEAD head;   //消息头
    // void *data;         //消息体
}MESSAGE;

int packet_write(int fd,int num);

#endif