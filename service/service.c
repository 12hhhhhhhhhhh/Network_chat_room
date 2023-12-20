#include "service.h"
#define SERVICE_IP "192.168.10.13"
#define SERVICE_PORT 12356

int socketfd = 0;//连接套接字
int epollfd = 0;//监测集合的句柄
struct epoll_event epoll_info = {0};//监测的事件
CLINODE *client_headnode = NULL;//头节点
int client_count = 0;//在线客户端的数量
int iuput_count = 0;//登陆的客户端的数量

/*
    函数：创建TCP通信的服务器端
    参数：无
    返回值：-1失败，0成功
*/
int service_create(void)
{
    int ret = 0;
    //创建连接套接字
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(socketfd < 0)
    {
        perror("socket");
        return -1;
    }
    //绑定IP和端口
    struct sockaddr_in serviceinfo = {0};
    serviceinfo.sin_addr.s_addr = inet_addr(SERVICE_IP);
    serviceinfo.sin_family = AF_INET;
    serviceinfo.sin_port = htons(SERVICE_PORT);
    ret = bind(socketfd,(struct sockaddr*)&serviceinfo,sizeof(serviceinfo));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }
    //开始监听
    listen(socketfd,10);
    perror("listen");
    return 0;
}

/*
    功能：服务器运行监测客户端连接或客户端发送数据
    参数：无
    返回值：-1失败，0成功
*/
int service_run(void)
{
    int ret = 0;
    //创建epoll句柄
    epollfd = epoll_create(1);
    if(epollfd < 0)
    {
        perror("epoll_create");
        return -1;
    }
    //将连接的套接字加入要检测的集合中
    epoll_info.data.fd = socketfd;
    epoll_info.events = EPOLLIN;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,socketfd,&epoll_info);
    //创建存储返回事件的结构体
    struct epoll_event epoll_recvive_all[50] = {0};
    //开始监测
    while(1)
    {
        ret = epoll_wait(epollfd,epoll_recvive_all,50,-1);
        for(int i = 0;i < ret;i++)
        {
            if(epoll_recvive_all[i].events & EPOLLIN)
            {
                if(epoll_recvive_all[i].data.fd == socketfd)//客户端申请连接服务器
                {
                    client_apply_connect();
                }
                else//客户端发送的消息
                {
                    receive_from_client(epoll_recvive_all[i].data.fd);
                }
            }
            
        }
    }
    return 0;
}

int main(void)
{
    service_create();
    database_init();
    link_list_init();
    service_run();
    return 0;
}