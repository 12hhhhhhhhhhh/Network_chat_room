#include "time.h"

/*
    获取当前的时间
*/
char *get_local_time(void)
{
    time_t t = time(NULL);
    struct tm *local_tm = localtime(&t);
    char time_buf[255] = {0};
    sprintf(time_buf, "%d-%d-%d %d:%d:%d", local_tm->tm_year + 1900, local_tm->tm_mon + 1, local_tm->tm_mday, \
    local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
    
    return time_buf;
}
