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
    功能：通过账号在数据库中寻找相应的用户信息
    参数：id:要查找的账户id
    返回值：0查无此人，1查询成功
*/
int database_find_user_info_by_id(char *id)
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