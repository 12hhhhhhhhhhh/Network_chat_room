#include "friend_page.h"

/*
    通过ID查找联系人，主要用于search按钮功能
*/
void find_contacts_by_id(client_data *data)
{
    USER_INFO user_info = {0};
    client_data send_data = {0};
    int ret = 0;
    if(data->id == NULL) {
        send_data.num = CONTACTS_SEARCH_UNKNOW;
        ret = write(data->fd, &send_data, sizeof(client_data));
        if(ret < 0) {
            printf("find_contacts_by_id:write1 error!\r\n");
        }
        return;
    }
    
    user_info = database_find_user_info_by_id(data->id);
    if(strcmp(user_info.id, "NULL") == 0) {
        printf("user_info == NULL\r\n");
        send_data.num = CONTACTS_SEARCH_NO_FIND;
        ret = write(data->fd, &send_data, sizeof(client_data));
        if(ret < 0) {
            printf("find_contacts_by_id:write2 error!\r\n");
        }
        return;
    }

    send_data.num = CONTACTS_SEARCH_SUCCESS;
    strcpy(send_data.id, user_info.id);
    strcpy(send_data.name, user_info.name);
    strcpy(send_data.flag, user_info.flag);
    ret = write(data->fd, &send_data, sizeof(client_data));
    if(ret < 0) {
        printf("find_contacts_by_id:write3 error!\r\n");
    }
    return;
}

/*
    发送好友申请
*/
void send_add_friend_apply(client_data *data)
{
    FRIEND_APPLY_RESULT res;
    client_data send_data = {0};
    printf("send_add_friend_apply begin\r\n");
    printf("data->name:%s\r\n",data->name);
    res = database_add_friend_apply_info(data->name, data->id);
    if(res == APPLY_SUCCESS) {
        send_data.num = CONTACTS_SEARCH_ADD_FRIEND_SUCCESS;
    }
    else if(res == APPLY_FAIL) {
        send_data.num = CONTACTS_SEARCH_ADD_FRIEND_FAIL;
    }
    else if(res == APPLY_ALREADY) {
        send_data.num = CONTACTS_SEARCH_ADD_FRIEND_ALREADY;
    }
    else if(res == APPLY_FULL) {
        send_data.num = CONTACTS_SEARCH_ADD_FRIEND_FULL;
    }

    res = write(data->fd, &send_data, sizeof(client_data));
    if(res < 0) {
        printf("send_add_friend_apply:write1 error!\r\n");
    }

    if(link_list_find_node_by_id(data->id) != NULL) {
        printf("被申请添加好友者在线！\r\n");
    }
    printf("send_add_friend_apply over\r\n");
}

/*
    同意好友申请
*/
void agree_friend_apply(client_data *data)
{
    
}