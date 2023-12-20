#include "function.h"

int packet_write(int fd,int num){
    MESSAGE *message = malloc(sizeof(MESSAGE));
    message->head.fd = fd;
    message->head.num = num;
    message->head.flag = 0;
    int ret = 0;
    ret = write(fd, message, sizeof(MESSAGE));
    if(ret < 0){
        perror("write");
        return -1;
    }
    return 0;
}