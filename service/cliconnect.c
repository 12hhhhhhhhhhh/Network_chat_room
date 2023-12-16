#include "cliconect.h"

/*
    功能：客户端连接服务器
    参数：无
    返回值：-1失败，0成功
*/
int client_apply_connect(void)
{
    int client_fd = 0;
    struct sockaddr_in client_info = {0};
    int socketlen = sizeof(client_info);
    client_fd = accept(socketfd,(struct sockaddr*)&client_info,&socketlen);
    if(client_fd < 0)
    {
        perror("accept");
        return -1;
    }
    printf("%d connect!\r\n",client_fd);
    epoll_info.data.fd = client_fd;
    epoll_info.events = EPOLLIN;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,client_fd,&epoll_info);
    client_count++;
    // client_data teminfo = {0};
    // teminfo.fd = client_fd;
    // //将相关客户端的信息存入链表中
    // link_list_add(&teminfo);
    return 0;
}

/*
    功能：接收来自客户端的信息,并进行处理
    参数：fd 客户端的套接字
    返回值：-1失败，0成功
*/
int receive_from_client(int fd)
{
    int ret = 0;
    client_data recv_data = {0};
    client_data send_data = {0};
    ret = read(fd, &recv_data, sizeof(recv_data));
    perror("read");
    if(ret == 0)//客户端下线
    {
        epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,NULL);
        link_list_del_by_fd(fd);
        client_count--;
        printf("%d下线,当前在线人数%d\r\n",fd,client_count);
    }
    else if(recv_data.num == INPUT_ACCOUNT)//客户端登陆
    {
        printf("passwd:%s-%s\r\n",recv_data.id, recv_data.passwd);
        ret = database_check_user_info_by_id_passwd(recv_data.id,recv_data.passwd);
        if(ret == 1)
        {
            link_list_add(&recv_data);
            printf("input success!\r\n");
            send_data.num = ACCOUNT_INPUT_SUCCESS;
            write(fd,&send_data,sizeof(send_data));
            user_info_init(&recv_data);
        }
        else
        {
            send_data.num = ACCOUNT_INPUT_FAIL;
            write(fd,&send_data,sizeof(send_data));
        }
    }
    else if(recv_data.num == CREATE_ACCOUNT)//客户端注册
    {
        ret = database_find_user_info_by_id(recv_data.id);
        if(ret == 1)
        {
            send_data.num = ID_EXIST;
            write(fd,&send_data,sizeof(send_data));
            return -1;
        }
        ret = database_user_info_add(&recv_data);
        if(ret == 0)
        {
            send_data.num = ACCOUNT_CREAT_SUCCESS;
        }
        else
        {
            send_data.num = ACCOUNT_CREAT_FAIL;
        }
        ret = write(fd,&send_data,sizeof(send_data));
        perror("write");
    }
    else if(recv_data.num == DELETE_FRIEND)//删除好友
    {
        //删除数据库好友的相关信息
    }
    return 0;
}

/*
    当用户成功登陆后将用户的好友信息发送给用户
*/
int user_info_init(client_data *info){
    char buf[256] = {0};
    int i = 0;
    //打开用户的好友信息表
    sprintf(buf, "select * from %s_friend", info->id);
    mysql_real_query(mysqlfd, buf, strlen(buf));
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    char **ch;
    FRIEND_INFO tem_friend_info = {0};
    while (ch = mysql_fetch_row(res)){
        memset(&tem_friend_info, 0, sizeof(tem_friend_info));
        strcpy(tem_friend_info.id, ch[0]); 
        strcpy(tem_friend_info.name, ch[1]); 
        strcpy(tem_friend_info.remark, ch[2]);
        i = 0;
        while((ch[3+i] != NULL) && (i < 25)){
            strcpy(tem_friend_info.news[i], ch[3+i]);
            i++;
        }
        //寻找好友的个签
        strcpy(buf, "select * from user_info");
        mysql_real_query(mysqlfd, buf, strlen(buf));
        MYSQL_RES *res1 = mysql_store_result(mysqlfd);
        while (ch = mysql_fetch_row(res)){
            if(strcmp(ch[1], tem_friend_info.id) == 0){
                strcpy(tem_friend_info.flag, ch[4]);
                break;
            }
        }
        packet_write(info->recv_fd, SERVICE_SEND_FRIEND_INFO, &tem_friend_info, sizeof(tem_friend_info));
        
    }
    return 0;
}