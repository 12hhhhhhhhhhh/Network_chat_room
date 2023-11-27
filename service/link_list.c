#include "link_list.h"


/*
    功能：创建并初始化一个存储客户端信息的链表
    参数：无
    返回值：-1失败，0成功
*/
int link_list_init(void)
{
    client_headnode = (CLINODE *)malloc(sizeof(CLINODE));
    if(client_headnode == NULL)
    {
        printf("link_list error!\r\n");
        return -1;
    }
    memset(client_headnode,0,sizeof(client_headnode));
    client_headnode->next = NULL;
    return 0;
}

/*
    功能：链表查询(通过账号)
    参数：要查询的套接字
    返回值：1查询成功，有此人；0查询失败，无此人；
*/
int link_list_find(int fd)
{
    CLINODE *temnode = client_headnode;
    while(temnode)
    {
        if(temnode->data.fd == fd)
        {
            return 1;
        }
        temnode = temnode->next;
    }
    return 0;
}

/*
    功能：链表添加
    参数：
    返回值：
*/
int link_list_add(client_data *buf)
{
    CLINODE *temnode = NULL;
    temnode = client_headnode;
    CLINODE *newnode = (CLINODE *)malloc(sizeof(CLINODE));
    if(newnode == NULL)
    {
        printf("link_list_add:malloc error!\r\n");
        return -1;
    }
    memset(newnode,0,sizeof(CLINODE));
    newnode->data.num = buf->num;
    newnode->data.fd = buf->fd;
    strcpy(newnode->data.id,buf->id);
    strcpy(newnode->data.name,buf->name);
    strcpy(newnode->data.passwd,buf->passwd);
    newnode->next = NULL;
    while(temnode->next)
    {
        temnode = temnode->next;
    }
    temnode ->next = newnode;
    return 0;
}

/*
    功能：链表删除
    参数：fd，要删除节点的fd
    返回值：-1查无此人，0删除成功
*/
int link_list_del_by_fd(int fd)
{
    CLINODE *temnode = client_headnode;
    int flag = 0;
    while(temnode->next)
    {
        if(temnode->next->data.fd == fd)
        {
            flag = 1;
            break;
        }
        temnode = temnode->next;
    }
    if(flag == 0)
    {
        return -1;
    }
    CLINODE *newnode = temnode->next;
    temnode->next = newnode->next;
    free(newnode);
    newnode = NULL;
    return 0;
}
