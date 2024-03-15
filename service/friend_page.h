#ifndef _FRIEND_PAGE_H_
#define _FRIEND_PAGE_H_

#include "service.h"

//表示好友申请的结果
typedef enum{
    APPLY_FAIL = -1,    //申请失败
    APPLY_SUCCESS,      //申请成功
    APPLY_ALREADY,      //已申请过
    APPLY_FULL          //对方申请过多
}FRIEND_APPLY_RESULT;

typedef enum{
    AGREE = 0,
    REFUSE
}APPLY_REPLY_FLAG;

void find_contacts_by_id(client_data *data);
void send_add_friend_apply(client_data *data);

#endif