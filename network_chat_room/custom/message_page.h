#ifndef _MESSAGE_PAGE_H_
#define _MESSAGE_PAGE_H_

#include "custom.h"

//表示消息的类别（群聊消息、好友消息）
typedef enum{
    FRIEND_MESSAGE,
    MYSELF_MESSAGE
}MESSAGE_TYPE;

typedef enum{
    STRING_DATA,
    PHOTO_DATA,
    FILE_DATA
}DATA_TYPE;

//表示消息包
typedef struct message_packet{
    DATA_TYPE data_type;    //表示消息内容的类型：字符串、图片、文件等
    char id[32];            //表示接收者的id
    char message[256];      //表示消息的内容
    int datalen;            //表示消息内容的长度
}MESSAGE_PACKET;

//表示消息对话框中的一条消息
typedef struct message_cont_cell{
    lv_obj_t *cell_cont;            //表示容纳一条消息相关信息的容器
    lv_obj_t *cell_message_label;   //表示容纳消息内容的标签
    lv_obj_t *cell_time_label;      //表示消息发送时间的标签
    lv_obj_t *cell_head_image;      //表示头像的图片
}MESSAGE_CONT_CELL;

typedef struct message_info_cont{
    lv_obj_t * cont;
    int message_num;
    MESSAGE_CONT_CELL message_cell[100];
}MESSAGE_INFO_CONT;

typedef struct message_send_cont{
    lv_obj_t * textarea;
    lv_obj_t * imgbtn_text;
    lv_obj_t * imgbtn_emoji;
    lv_obj_t * imgbtn_file;
    lv_obj_t * imgbtn_tel;
}MESSAGE_SEND_CONT;

typedef struct message_emoji_cont{
    (lv_obj_t *) emoji1;
} 

//表示消息页面列表中元素及其相关信息
typedef struct message_list_item{
    lv_obj_t    *item;                 //表示列表中元素
    MESSAGE_TYPE messagetype;          //表示群聊消息或好友消息的标志
    void *      info;                  //表示当前item代表的好友或群聊的相关信息
}MESSAGE_LIST_ITEM;

//表示消息页面相关的信息
typedef struct message_page{
    lv_obj_t *sender_list;              //表示发送人的列表
    lv_obj_t *send_message_ta;          //表示输入消息的输入框
    lv_obj_t *send_message_btn;         //表示发送消息的按钮
    MESSAGE_LIST_ITEM list_item[255];   //表示列表中元素
    int cell_count;                     //表示消息页面发送者的数量

    MESSAGE_LIST_ITEM * now_select_item;//表示当前选中的item
    lv_obj_t *  message_imagebtn;       //“消息”按钮
    lv_obj_t *  friend_imagebtn;        //“朋友”按钮
    lv_obj_t *  circle_imagebtn;        //“朋友圈”按钮
    lv_obj_t *  owner_imagebtn;         //“我的”按钮
}MESSAGE_PAGE;

extern MESSAGE_PAGE message_page_object;  //表示消息页面相关的信息

void    message_page_init(void);
int     message_cont_fill_friend(char *name);
void    message_page_config(void);
int     add_friend_message_into_cont(char *news, MESSAGE_CONT_CELL *obj, MESSAGE_TYPE type);

#endif