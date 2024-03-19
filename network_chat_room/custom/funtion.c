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

// void *send_data(void *arg){
// //     MESSAGE *message = (MESSAGE *)arg;
// //     int ret = 0;
// // loop:
// //     ret = write(message->head.fd, message, sizeof(MESSAGE));
// //     if(ret < 0){
// //         perror("write");
// //         return NULL;
// //     }
// //     ret = read(message->head.fd, message, sizeof(MESSAGE));
// //     if(ret < 0){
// //         perror("read");
// //         return NULL;
// //     }
// //     if(message->head.flag != WRITE_SUCCESS){
// //         goto loop;
// //     }
// //     printf("write success!\r\n");
// //     return NULL;
// }

// int packet_write(int fd,int num, void *buf, int len){
//     MESSAGE *message = malloc(sizeof(MESSAGE));
//     message->head.fd = fd;
//     message->head.num = num;
//     message->head.len = len;
//     message->head.flag = 0;
//     // message->data = buf;
//     int ret = 0;
//     ret = write(fd, &message, sizeof(MESSAGE));
//     if(ret < 0){
//         perror("write");
//         return -1;
//     }
//     return 0;
// }

int packet_read(int fd, MESSAGE *message, int len){
    int ret = 0;
    ret = read(fd, message, len);
    if(ret < 0){
        perror("read");
        return -1;
    }
    return 0;
}

/*
    判断指定字符串中是否含有除数字字符外的其他字符
*/
int judge_id_format(char *buf) {
    for(int i = 0;i < strlen(buf);i++) {
        if(buf[i] >= '0' && buf[i] <= '9') {
            continue;
        }
        else {
            return -1;
        }
    }
    return 0;
}

/*
    设置当前页面的位置
*/
int set_current_page_location(PAGE_LOCATION page)
{
    pthread_rwlock_wrlock(page_location_rwlock);
    int ret = page_location = page;
    pthread_rwlock_unlock(page_location_rwlock);
    return ret;
}

/*
    获取当前页面的位置
*/
PAGE_LOCATION get_current_page_location(void)
{
    pthread_rwlock_rdlock(page_location_rwlock);
    PAGE_LOCATION page = page_location;
    pthread_rwlock_unlock(page_location_rwlock);
    return page;
}