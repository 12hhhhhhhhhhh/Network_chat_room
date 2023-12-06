#include "function.h"

int packet_write(int fd,int num, void *buf, int len){
    MESSAGE *message = malloc(sizeof(MESSAGE));
    message->head.fd = fd;
    message->head.num = num;
    message->head.len = len;
    message->head.flag = 0;
    message->data = buf;
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
    MESSAGE read_result = {0};
    if(strlen((char *)(message->data)) != message->head.len){
        read_result.head.flag = WRITE_FAIL;
    }
    else{
        read_result.head.flag = WRITE_SUCCESS;
    }
    ret = write(fd, &read_result, sizeof(MESSAGE));
    if(ret < 0){
        perror("write");
        return -1;
    }
    return 0;
}