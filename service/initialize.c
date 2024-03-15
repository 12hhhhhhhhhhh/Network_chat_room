#include "initialize.h"

/*
    当用户成功登陆后将用户的好友信息发送给用户
*/
static void *user_info_init(void *arg){
    char buf[256] = {0};
    char sendData[9600] = {0};
    MESSAGEHEAD head = {0};
    client_data *data = (client_data *)arg;
    int i = 0;
    //查找并发送好友相关的信息
    sprintf(buf, "select * from %s_friend", data->id);
    mysql_real_query(mysqlfd, buf, strlen(buf));
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    char **ch = NULL;
    if(res == NULL){
        printf("1\r\n");
    }
    FRIEND_INFO tem_friend_info = {0};
    head.num = SERVICE_SEND_FRIEND_INFO;
    while (ch = mysql_fetch_row(res)){
        memset(&tem_friend_info, 0, sizeof(tem_friend_info));
        strcpy(tem_friend_info.id, ch[0]); 
        strcpy(tem_friend_info.name, ch[2]); 
        strcpy(tem_friend_info.remark, ch[3]);
        i = 0;
        while((ch[4+i] != NULL) && (i < 25)){
            strcpy(tem_friend_info.news[i], ch[4+i]);
            i++;
        }
        //寻找好友的个签
        strcpy(buf, "select * from user_info");
        mysql_real_query(mysqlfd, buf, strlen(buf));
        MYSQL_RES *res1 = mysql_store_result(mysqlfd);
        while (ch = mysql_fetch_row(res1)){
            if(strcmp(ch[2], tem_friend_info.id) == 0){
                strcpy(tem_friend_info.flag, ch[4]);
                break;
            }
        }
        head.len = sizeof(tem_friend_info);

        memcpy(sendData, &head, sizeof(MESSAGEHEAD));
        memcpy((sendData+sizeof(MESSAGEHEAD)), &tem_friend_info, sizeof(FRIEND_INFO));
        DEBUG("recv_fd:%d\r\n", data->recv_fd);
        DEBUG("%s-%s-%s-%s\r\n", tem_friend_info.id, tem_friend_info.name, tem_friend_info.remark, tem_friend_info.flag);
        DEBUG("%s-%s\r\n", tem_friend_info.news[0], tem_friend_info.news[1]);
        int ret = write(data->recv_fd, sendData, sizeof(sendData));
        if(ret < 0){
            perror("write");
            ERROR("write fail!");
        }
        usleep(30);
    }

    //查找并发送好友申请相关的信息
    memset(buf, 0, sizeof(buf));
    memset(sendData, 0, sizeof(sendData));
    sprintf(buf, "select * from friend_apply where id = %s", data->id);
    mysql_real_query(mysqlfd, buf, strlen(buf));
    res = mysql_store_result(mysqlfd);
    ch = mysql_fetch_row(res);
    i = 1;
    head.num = SERVICE_SEND_FRIEND_APPLY;
    DEBUG("3-3\r\n");
    if(ch == NULL) {
        return 0;
    }
    while(ch[i] != NULL) {
        USER_INFO info = database_find_user_info_by_id(ch[i]);
        head.len = sizeof(USER_INFO);
        memcpy(sendData, &head, sizeof(MESSAGEHEAD));
        memcpy((sendData+sizeof(MESSAGEHEAD)), &info, sizeof(USER_INFO));
        int ret = write(data->fd, sendData, sizeof(sendData));
        if(ret < 0) {
            ERROR("write fail!");
        }
        usleep(30);
    }
    return 0;
}

/*
    初始化客户端
*/
void user_init(client_data *data)
{
    pthread_t id1;
    pthread_create(&id1, NULL, user_info_init, (void *)data);
    pthread_detach(id1);
}