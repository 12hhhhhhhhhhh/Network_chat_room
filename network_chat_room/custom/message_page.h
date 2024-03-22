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

//表示对话框
typedef struct message_info_cont{
    lv_obj_t * cont;                        //表示对话框容器
    int message_num;                        //表示对话框中的消息数量，至多100条
    MESSAGE_CONT_CELL message_cell[100];    //表示对话框中的每一条消息
}MESSAGE_INFO_CONT;

//表示发送框
typedef struct message_send_cont{
    lv_obj_t * cont;                //表示发送框容器
    lv_obj_t * textarea;            //表示输入发送消息的文本框
    lv_obj_t * imgbtn_text;         //发送文本消息的按钮
    lv_obj_t * imgbtn_emoji;        //表示发送表情的按钮
    lv_obj_t * imgbtn_file;         //表示发送文件的按钮
    lv_obj_t * imgbtn_tel;          //表示打电话的按钮
}MESSAGE_SEND_CONT;

//表示表情框
typedef struct message_emoji_cont{
    lv_obj_t * cont;        //表示表情框容器
    (lv_obj_t *) emoji[20]; //表示20个表情
}MESSAGE_EMOJI_CONT;

//表示文件选择框
typedef struct message_file_cont{
    
}MESSAGE_FILE_CONT;

//表示消息发送页面
typedef struct message_cont_page{
    lv_onj_t * cont;            //表示页面容器
    MESSAGE_INFO_CONT info;     //表示对话框
    MESSAGE_SEND_CONT send;     //表示发送框
    MESSAGE_EMOJI_CONT emoji;   //表示表情框
}MESSAGE_CONT_PAGE;

//表示好友申请回复页面的一条消息
typedef struct friend_reply_cell{
    lv_obj_t * cont;        //表示消息框容器
    lv_obj_t * buttom_line; //表示底部的线（用于和下一条消息作区分）
    lv_obj_t * btn;         //表示信息按钮
    lv_obj_t * btn_label;   //表示信息标签
}FRIEND_REPLY_CELL;

//表示好友申请回复页面
typedef struct friend_reply_page{
    int num;                    //表示页面中消息的数量
    FRIEND_REPLY_CELL cell[30]; //表示每一条消息
    lv_obj_t * cont;            //表示页面容器
}FRIEND_REPLY_PAGE;

//表示消息页面列表中元素及其相关信息
typedef struct message_list_cell{
    lv_obj_t    *item;                 //表示列表中元素
    void *      info;                  //表示当前item代表的好友或群聊的相关信息
}MESSAGE_LIST_CELL;

//表示消息页面的列表
typedef struct message_list{
    lv_obj_t *list;                     //表示发送人的列表
    MESSAGE_LIST_CELL list_item[255];   //表示列表中元素
    MESSAGE_LIST_CELL * now_select_item;//表示当前选中的item
    int cell_count;                     //表示消息页面发送者的数量
}MESSAGE_LIST;

//表示消息页面相关的信息
typedef struct message_page{
    MESSAGE_LIST list;                  //表示消息页面的列表
    FRIEND_REPLY_PAGE reply_page;       //表示好友申请回复页面
    MESSAGE_CONT_PAGE message_page;     //表示消息页面
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
void    add_one_to_apply_reply_page(FRIEND_REPLY_CELL *cell, char * info);
#endif