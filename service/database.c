#include "database.h"

MYSQL *mysqlfd;//数据库的句柄

/*
    功能：初始化数据库
    参数：无
    返回值：-1失败，0成功
*/
int database_init(void)
{
    mysqlfd = mysql_init(NULL);
    mysqlfd = mysql_real_connect(mysqlfd,"localhost","root","1","network_tall",0,NULL,0);
    if(mysqlfd == NULL)
    {
        printf("mysql_init:mysql open error!\r\n");
        return -1;
    }
    return 0;
}

/*
    功能：向对应的数据库中添加用户信息
    参数：data:要添加的账户信息
    返回值：-1失败，0成功
*/
int database_user_info_add(client_data *data)
{
    static int all_user_num = 0;
    all_user_num++;
    char buf[1024] = {0};
    // 将创建的信息加入user_infor表格中
    memset(buf, 0, 256);
    sprintf(buf,"insert into user_info values('%d','%s','%s','%s')",all_user_num,data->name, data->id, data->passwd);
    int a = mysql_real_query(mysqlfd, buf, strlen(buf));
    if (a != 0){
        return -1;
    }
    //创建该用户的好友数据表格
    sprintf(buf, "create table %s_friend(id char(32),name char(32),remark char(32),news1 char(255),\
    news2 char(255),news3 char(255),news4 char(255),news5 char(255),news6 char(255),news7 char(255),news8 char(255),\
    news9 char(255),news10 char(255),news11 char(255),news12 char(255),news13 char(255),news14 char(255),news15 char(255),\
    news16 char(255),news17 char(255),news18 char(255),news19 char(255),news20 char(255),news21 char(255),news22 char(255),\
    news23 char(255),news24 char(255),news25 char(255))", data->id);
    a = mysql_real_query(mysqlfd, buf, strlen(buf));
    if (a != 0){
        return -1;
    }
    //创建该用户的群聊数据表格
    sprintf(buf, "create table %s_group(id char(32),name char(32),remark char(32),news1 char(255),\
    news2 char(255),news3 char(255),news4 char(255),news5 char(255),news6 char(255),news7 char(255),news8 char(255),\
    news9 char(255),news10 char(255),news11 char(255),news12 char(255),news13 char(255),news14 char(255),news15 char(255),\
    news16 char(255),news17 char(255),news18 char(255),news19 char(255),news20 char(255),news21 char(255),news22 char(255),\
    news23 char(255),news24 char(255),news25 char(255))", data->id);
    a = mysql_real_query(mysqlfd, buf, strlen(buf));
    if (a != 0){
        return -1;
    }
    return 0;
}

/*
    功能：通过ID判断该用户是否存在
    参数：id:要查找的账户id
    返回值：0查无此人，1查询成功
*/
int database_find_user_by_id(char *id)
{
    char buf[300] = {0};
    // 确保每个人的ID各不相同
    strcpy(buf, "select id from user_info");
    mysql_real_query(mysqlfd, buf, strlen(buf));
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    char **ch;
    while (ch = mysql_fetch_row(res))
    {
        if (strcmp(ch[0],id) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/*
    功能：通过账号在数据库中核对相应的用户信息
    参数：要核对账户的id和passwd
    返回值：0用户不存在，1核对成功，-1密码错误
*/
int database_check_user_info_by_id_passwd(char *id,char *passwd)
{
    char buf[300] = {0};
    // 确保每个人的ID各不相同
    strcpy(buf, "select * from user_info");
    mysql_real_query(mysqlfd, buf, strlen(buf));
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    char **ch;
    while (ch = mysql_fetch_row(res))
    {
        if (strcmp(ch[2],id) == 0){
            if(strcmp(ch[3],passwd) == 0){
                return 1;
            }
            else{
               return -1; 
            }
        }
    }
    return 0;
}

/*
    功能：通过账号在数据库中寻找相应的用户信息
    参数：id:要查找的账户id
    返回值：查询到的用户信息
*/
USER_INFO database_find_user_info_by_id(char *id)
{
    USER_INFO user_info = {0};
    char buf[300] = {0};
    int flag = 0;
    // 确保每个人的ID各不相同
    strcpy(buf, "select * from user_info");
    mysql_real_query(mysqlfd, buf, strlen(buf));
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    char **ch;
    while (ch = mysql_fetch_row(res))
    {
        if (strcmp(ch[2],id) == 0)
        {
            flag = 1;
            strcpy(user_info.name, ch[1]);
            strcpy(user_info.id, ch[2]);
            strcpy(user_info.passwd, ch[3]);
            if(ch[4] == NULL) {
                strcpy(user_info.flag, "NULL");
            }
            else {
                strcpy(user_info.flag, ch[4]);
            }
            printf("user_info.name:%s\r\n", user_info.name);
            break;
        }
    }
    printf("4\r\n");
    if(flag == 0) {
        strcpy(user_info.id, "NULL"); //表示没有查询到该人
    }
    return user_info;
}

/*
    功能：向数据库中的friend_apply表格添加数据
    参数：id1：申请人的ID，id2：被申请人的id
    返回值：结果
*/
FRIEND_APPLY_RESULT database_add_friend_apply_info(char *id1, char *id2)
{
    char buf[300] = {0};
    int ret = 0;
    // 确保每个人的ID各不相同
    printf("1\r\n");
    sprintf(buf, "select * from friend_apply where id = %s",id2);
    mysql_real_query(mysqlfd, buf, strlen(buf));
    printf("2\r\n");
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    int num = mysql_num_rows(res);
    printf("3\r\n");
    if(num == 0) {
        printf("4\r\n");
        memset(buf, 0, 300);
        sprintf(buf, "insert into friend_apply(id,apply1) values(%s,%s)",id2,id1);
        printf("5:%s\r\n", buf);
        ret = mysql_real_query(mysqlfd, buf, strlen(buf));
        if(ret < 0) {
            goto error;
        }
        printf("6\r\n");
    }
    else {
        printf("7\r\n");
        char **ch;
        int i = 0;
        ch = mysql_fetch_row(res);
        printf("7-1\r\n");
        for(i = 0;i < 10;i++) {
            if(strcmp(ch[i+1], id1) == 0) {
                return APPLY_ALREADY;   //表示已经发送过好友申请
            }
            if(ch[i+1] == NULL) {
                memset(buf, 0, 300);
                sprintf(buf, "update friend_apply set apply%d=%s where id=%s", (i+1), id1, id2);
                ret = mysql_real_query(mysqlfd, buf, strlen(buf));
                if(ret < 0) {
                    goto error;
                }
                break;  
            }
        }
        if(i == 10) {
            return APPLY_FULL;   //表示对方好友申请已满
        }
    }
    printf("8\r\n");
    return APPLY_SUCCESS;

error:
    return APPLY_FAIL;
}

/*
    向好友申请列表中添加消息
    reply_id:被申请者的ID
    apply_id:申请者的ID
    flag:是否同意的标志,0--同意，1--拒绝
*/
FRIEND_APPLY_RESULT database_add_friend_apply_reply(char *reply_id, char *apply_id, APPLY_REPLY_FLAG flag)
{
    char buf[300] = {0};
    char buf1[255] = {0};
    int ret = 0;
    spritnf(buf1, "<%s>,<%d>,<%s>", reply_id, flag, get_local_time());
    sprintf(buf, "select * from friend_apply_reply where id = %s", apply_id);
    mysql_real_query(mysqlfd, buf, strlen(buf));
    MYSQL_RES *res = mysql_store_result(mysqlfd);
    int num = mysql_num_rows(res);;
    if(num == 0) {
        memset(buf, 0, 300);
        sprintf(buf, "insert into friend_apply(id,info1) values(%s,%s)", apply_id, buf1);
        ret = mysql_real_query(mysqlfd, buf, strlen(buf));
        if(ret < 0) {
            goto error;
        }
    }
    else {
        char **ch;
        int i = 0;
        ch = mysql_fetch_row(res);
        while(ch[i] != NULL)
        {
            i++;
        }
        if(i < 27)
        {
            memset(buf, 0, 300);
            sprintf(buf, "update friend_apply set info%d=%s where id=%s", i, buf1, apply_id);
        }
        else {
            
        }
        
        // for(i = 0;i < 10;i++) {
        //     if(strcmp(ch[i+1], id1) == 0) {
        //         return APPLY_ALREADY;   //表示已经发送过好友申请
        //     }
        //     if(ch[i+1] == NULL) {
        //         memset(buf, 0, 300);
        //         sprintf(buf, "update friend_apply set apply%d=%s where id=%s", (i+1), id1, id2);
        //         ret = mysql_real_query(mysqlfd, buf, strlen(buf));
        //         if(ret < 0) {
        //             goto error;
        //         }
        //         break;  
        //     }
        // }
        if(i == 10) {
            return APPLY_FULL;   //表示对方好友申请已满
        }
    }
    printf("8\r\n");
    return APPLY_SUCCESS;

error:
    return APPLY_FAIL;
}