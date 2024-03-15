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

//表示发送好友申请结果的弹窗
typedef struct{
    lv_obj_t * cont;    //表示弹窗容器
    lv_obj_t * label;   //表示显示结果信息的标签
    lv_obj_t * btn;     //表示确认结果的按钮
}SEND_ADD_RES;

//表示搜索到的信息页面
typedef struct {
    lv_obj_t * head_image;      //表示头像的图片
    lv_obj_t * name_label;      //表示昵称的标签
    lv_obj_t * id_label;        //表示ID的标签
    lv_obj_t * flag_spangroup;  //表示个签的文本组
    lv_obj_t * add_btn;         //表示添加好友的按钮
    SEND_ADD_RES send_add_res;  
}SEARCH_CONT;

//表示搜索结果的弹窗
typedef struct {
    lv_obj_t * cont;        //表示搜索结果的弹窗容器
    lv_obj_t * label;       //表示搜索的结果
    lv_obj_t * btn;         //表示确认按钮
}SEARCH_RES_CONT;

//表示好友申请信息的详细信息
typedef struct {
    lv_obj_t * cont;            //表示显示好友详细申请信息的容器
    lv_obj_t * head_image;      //表示好友的头像
    lv_obj_t * name_label;      //表示显示申请人昵称的标签
    lv_obj_t * id_label;        //表示显示申请人ID的标签
    lv_obj_t * flag_label;      //表示显示申请人个签的标签
    lv_obj_t * agree_imagebtn;  //表示同意按钮
    lv_obj_t * refuse_imagebtn; //表示拒绝按钮
    lv_obj_t * quit_imagebtn;   //表示退出当前页面的按钮
}DETAIL_APPLY_INFOR;

//表示一条好友申请信息
typedef struct {
    char id[32];                //表示当前这条好友申请信息申请者的ID
    lv_obj_t * cont;            //表示一条好友信息的容器
    lv_obj_t * top_line;        //表示容器中顶层的线
    lv_obj_t * buttom_line;     //表示容器中底层的线
    lv_obj_t * btn;             //表示显示好友申请信息的按钮
    lv_obj_t * btn_label;       //表示显示好友申请信息的按钮标签
    lv_obj_t * agree_imagebtn;  //表示同意按钮
    lv_obj_t * refuse_imagebtn; //表示拒绝按钮
}ONE_FEREND_APPLY;

//表示好友申请信息的页面
typedef struct {
    lv_obj_t * cont;                    //表示好友申请信息页面的容器
    int apply_num;                      //表示好友申请的数量
    ONE_FEREND_APPLY friend_apply[10];  //表示好友申请列表
    DETAIL_APPLY_INFOR apply_infor;     //表示详细的好友申请信息页面
}FRIEND_APPLY_CONT;

//表示联系人页面的元素
typedef struct {
    FRIEND_APPLY_CONT friend_apply_cont;//好友申请列表页面 
    lv_obj_t *  friend_cont;            //好友信息框的容器
    FRIEND_CONT friend_info;            //好友信息框
    lv_obj_t *  search_cont;            //好友信息框的容器
    SEARCH_CONT search_info;            //搜索信息框
    lv_obj_t *  search_ta;              //搜索输入框
    lv_obj_t *  search_imagebtn;        //搜索按钮
    SEARCH_RES_CONT search_res_cont;    //搜索结果弹窗
    lv_obj_t *  message_imagebtn;       //“消息”按钮
    lv_obj_t *  friend_imagebtn;        //“朋友”按钮
    lv_obj_t *  circle_imagebtn;        //“朋友圈”按钮
    lv_obj_t *  owner_imagebtn;         //“我的”按钮
}CONTACTS_PAGE;

extern CONTACTS_PAGE contacts_page;

void contacts_page_init(void);
void add_one_to_list(ONE_FEREND_APPLY *apply, USER_INFO *data);

#endif