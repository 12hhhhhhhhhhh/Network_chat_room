#ifndef _OWNER_PAGE_H_
#define _OWNER_PAGE_H_

#include "custom.h"

//表示用户信息的结构体
typedef struct{
    char name[32];
    char passwd[32];
    char id[32];
    char flag[256];
}USER_INFO;

USER_INFO owner_info; //表示用户自己的信息

#endif