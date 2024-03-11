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
    perror("read1");
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
            recv_data.fd = fd;
            link_list_add(&recv_data);
            printf("input success!\r\n");
            send_data.num = ACCOUNT_INPUT_SUCCESS;
            printf("recv_data.id:%s\r\n", recv_data.id);
            USER_INFO teminfo = database_find_user_info_by_id(recv_data.id);
            printf("database_find_user_info_by_id\r\n");
            if(strcmp(teminfo.id, "NULL") != 0) {
                printf("teminfo.id = NULL\r\n");
                strcpy(send_data.id, teminfo.id);
                strcpy(send_data.passwd, teminfo.passwd);
                strcpy(send_data.name, teminfo.name);
                strcpy(send_data.flag, teminfo.flag);
            }

            write(fd,&send_data,sizeof(send_data));
            perror("write1");
        }
        else
        {
            send_data.num = ACCOUNT_INPUT_FAIL;
            write(fd,&send_data,sizeof(send_data));
        }
    }
    else if(recv_data.num == CLIENT_RECVFD)//客户端发送接收套接字,并请求用户信息
    {
        link_list_add_recvfd(recv_data.id, fd);
        //发送客户端相关的如好友信息等信息
        recv_data.recv_fd = fd;
        user_init(&recv_data);
    }
    else if(recv_data.num == CREATE_ACCOUNT)//客户端注册
    {
        ret = database_find_user_by_id(recv_data.id);
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
    else if(recv_data.num == MESSAGE_CLI_TO_SER)
    {
        MESSAGE_PACKET messagePacket;
        CLINODE *temnode = NULL;
        ret = read(fd, &messagePacket, sizeof(MESSAGE_PACKET));
        if(ret < 0) {
            perror("read");
        }
        temnode = link_list_find_node_by_id(messagePacket.id);
        if(temnode != NULL) {
            ret = write(temnode->data.recv_fd, &send_data, sizeof(send_data));
        }

    }
    else if(recv_data.num == DELETE_FRIEND)//删除好友
    {
        //删除数据库好友的相关信息
    }
    else if(recv_data.num == CONTACTS_SEARCH_BY_ID)//通过ID查找好友
    {
        recv_data.fd = fd;
        find_contacts_by_id(&recv_data);
    }
    else if(recv_data.num == CONTACTS_SEARCH_ADD_FRIEND)//发送好友申请
    {
        recv_data.fd = fd;
        send_add_friend_apply(&recv_data);
    }
    return 0;
}
