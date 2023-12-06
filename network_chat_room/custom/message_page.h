#ifndef _MESSAGE_PAGE_H_
#define _MESSAGE_PAGE_H_

#include "custom.h"

typedef struct{
    FRIEND_INFO info;       //元素相关的信息
    lv_obj_t *list_item;    //元素在列表中的对象结构体
}MESSAGE_PAGE_CELL;         //代表消息界面的一个元素

MESSAGE_PAGE_CELL message_page_cell[255]; //代表消息界面所有元素的数组
int cell_count;             //代表消息界面的元素数量

#endif