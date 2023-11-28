#include "net_talkromm.h"

#define IP "192.168.10.12"
#define PORT 12356

volatile int flag = 0;
client_data client_info = {0};
client_data recv_from_server = {0};
volatile int socketfd = 0;

/*
    功能：创建套接字文件，连接服务器
    参数：无
    返回值：-1失败，0成功
*/
int connect_network(void)
{
    int ret = 0;
    //创建通信套接字
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(socketfd < 0)
    {
        printf("socket error");
        return -1;
    }
    //连接服务器
    struct sockaddr_in service_info = {0};
    service_info.sin_family = AF_INET;
    service_info.sin_addr.s_addr = inet_addr(IP);
    service_info.sin_port = htons(PORT);
    ret = connect(socketfd,(const struct sockaddr*)&service_info,sizeof(service_info));
    if(ret < 0)
    {
        printf("connect_network:connect error!\r\n");
        return -1;
    }
    printf("connect success!\r\n");
    return 0;
}

void *net_talkroom_run(void *arg)
{
    int ret = 0;
    while(1)
    {
        // usleep(100000);
        // if(flag == 1)
        // {
        //     lv_scr_load(guider_ui.screen_input);
        //     flag = 0;
        // }
    }
}