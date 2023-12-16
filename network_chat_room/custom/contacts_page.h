#ifndef _CONTACTS_PAGE_H_
#define _CONTACTS_PAGE_H_

#include "custom.h"

//表示好友信息页面修改备注的弹窗相关的信息
typedef struct {
    lv_obj_t * cont;            //整个修改备注的弹窗的容器
    lv_obj_t * yes_btn;         //确定按钮
    lv_obj_t * no_btn;          //取消按钮
    lv_obj_t * remark_textarea; //输入备注的输入框
}MODIFY_REMARK_CONT;

//表示是否确认删除好友的弹窗
typedef struct {
    lv_obj_t * cont;            //弹窗容器
    lv_obj_t * yes_btn;         //确认按钮
    lv_obj_t * no_btn;          //取消按钮
}CONFIRM_DELETE_CONT;

//表示好友信息列表的元素
typedef struct {
    char name[64];      //表示列表中对象上的文本
    lv_obj_t *item;     //表示列表中的标签
}FRIEND_ITEM;

//表示好友信息页面的相关信息
typedef struct {
    int friend_count;               //表示好友的数量
    lv_obj_t * list;                //表示好友信息页面的列表
    lv_obj_t * modify_btn;          //表示修改好友备注的按钮
    lv_obj_t * delete_btn;          //表示删除好友的按钮
    lv_obj_t * message_btn;         //表示发送消息的按钮
    lv_obj_t * telphone_btn;        //表示拨打电话的按钮
    FRIEND_ITEM friend_item[100];   //表示列表上对象信息的数组
    lv_obj_t * head_image;          //表示好友的头像
    lv_obj_t * name_label;          //表示好友名字的标签
    lv_obj_t * remark_label;        //表示好友备注的标签
    lv_obj_t * id_label;            //表示好友ID的标签
    lv_obj_t * flag_spangroup;      //表示好友个签的文本组
    MODIFY_REMARK_CONT modify_cont; //表示修改好友备注的弹窗
    CONFIRM_DELETE_CONT delete_cont;//表示是否确定删除好友的弹窗
}FRIEND_CONT;

//表示联系人页面的元素
typedef struct {
    lv_obj_t * manage_btn;
    lv_obj_t * friend_btn;
    lv_obj_t * group_btn;
    lv_obj_t * manage_cont;
    lv_obj_t * friend_cont;
    lv_obj_t * group_cont;
    FRIEND_CONT friend_info;
}CONTACTS_PAGE;

CONTACTS_PAGE contacts_page;

#endif