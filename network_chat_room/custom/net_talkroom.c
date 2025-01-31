#include "net_talkromm.h"

#define IP "192.168.10.16"
#define PORT 12356

client_data client_info = {0};
client_data recv_from_server = {0};
volatile int socketfd = 0;          //发送指令的套接字
volatile int recv_socketfd = 0;     //接收消息的套接字


/*
    功能：创建套接字文件，连接服务器
    参数：无
    返回值：-1失败，0成功
*/
int connect_network(volatile int *fd)
{
    int ret = 0;
    //创建通信套接字
    *fd = socket(AF_INET,SOCK_STREAM,0);
    if(*fd < 0)
    {
        printf("socket error");
        return -1;
    }
    //连接服务器
    struct sockaddr_in service_info = {0};
    service_info.sin_family = AF_INET;
    service_info.sin_addr.s_addr = inet_addr(IP);
    service_info.sin_port = htons(PORT);
    ret = connect(*fd,(const struct sockaddr*)&service_info,sizeof(service_info));
    if(ret < 0)
    {
        printf("connect_network:connect error!\r\n");
        return -1;
    }
    printf("connect success!\r\n");
    return 0;
}

/*
    专门用于接收消息的线程
*/
void *net_talkroom_recv(void *arg)
{
    int ret = 0;
    char recvdata[9600] = {0};
    while(1)
    {
        DEBUG("packet_read\r\n");
        ret = read(recv_socketfd, &recvdata, sizeof(recvdata));
        if(ret < 0){
            ERROR("packet_read\r\n");
            continue;
        }
        MESSAGEHEAD *head = (MESSAGEHEAD *)recvdata;
        DEBUG("head->num:%d\r\n", head->num);
        if(head->num == SERVICE_SEND_FRIEND_INFO){
            //接收好友相关的信息
            FRIEND_INFO *frined_info =  (FRIEND_INFO *)(recvdata + sizeof(MESSAGEHEAD));
            DEBUG("recv:name-%s\r\n", frined_info->news[0]);
            add_friend_info_node(frined_info);
            DEBUG("add_friend_info_node\r\n");
        }
        if(head->num == SERVICE_SEND_FRIEND_APPLY){
            USER_INFO *info = (USER_INFO *)(recvdata + sizeof(MESSAGEHEAD));
            DEBUG("apply name:%s, id:%s!\r\n", info->name, info->id);
            //将好友申请信息添加到对应的好友申请页面
            add_one_to_list(contacts_page.friend_apply_cont.friend_apply[contacts_page.friend_apply_cont.apply_num], \
            info);
        }
        if(head->num == SERVICE_SEND_FRIEND_APPLY_REPLY){
            char *info_reply = (char *)(recvdata + sizeof(MESSAGEHEAD));
            DEBUG("info_reply:%s!\r\n", info_reply);
            //将好友申请信息添加到对应的好友申请页面
            add_one_to_apply_reply_page(&message_page_object.reply_page.cell[message_page_object.reply_page.num], \
            info_reply);
        }
    }
}

/*
    登陆成功后进行消息、好友、群聊等的初始化
*/
void all_init(void){
    friend_list_init();
    sleep(1);
    message_page_config();
}



