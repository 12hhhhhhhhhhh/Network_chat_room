#include "function.h"

/*
    功能：检测指定的字符串中是否有除了数字之外的其他字符
    参数：buf--要检测的字符串，len--字符串的长度
    返回值：-1--含有其他字符，0不含除数字外的其他字符
*/
int check_num_char(const char *buf, int len){
    for(int i=0;i<len;i++){
        if(buf[i]<48 || buf[i]>59){
            return -1;
        }
    }
    return 0;
}

void *send_data(void *arg){
    MESSAGE *message = (MESSAGE *)arg;
    int ret = 0;
loop:
    ret = write(message->head.fd, message, sizeof(MESSAGE));
    if(ret < 0){
        perror("write");
        return NULL;
    }
    ret = read(message->head.fd, message, sizeof(MESSAGE));
    if(ret < 0){
        perror("read");
        return NULL;
    }
    if(message->head.flag != WRITE_SUCCESS){
        goto loop;
    }
    printf("write success!\r\n");
    return NULL;
}

int packet_write(int fd,int num, void *buf, int len){
    MESSAGE *message = malloc(sizeof(MESSAGE));
    message->head.fd = fd;
    message->head.num = num;
    message->head.len = len;
    message->head.flag = 0;
    // message->data = buf;
    int ret = 0;
    ret = write(fd, &message, sizeof(MESSAGE));
    if(ret < 0){
        perror("write");
        return -1;
    }
    return 0;
}

int packet_read(int fd, MESSAGE *message, int len){
    int ret = 0;
    ret = read(fd, message, len);
    if(ret < 0){
        perror("read");
        return -1;
    }
    return 0;
}