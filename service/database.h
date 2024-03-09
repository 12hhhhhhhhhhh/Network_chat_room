#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "service.h"

extern MYSQL *mysqlfd;

//表示好友申请的结果
typedef enum{
    APPLY_FAIL = -1,    //申请失败
    APPLY_SUCCESS,      //申请成功
    APPLY_ALREADY,      //已申请过
    APPLY_FULL          //对方申请过多
}FRIEND_APPLY_RESULT;

int database_init(void);
int database_find_user_by_id(char *id);
int database_user_info_add(client_data *data);
USER_INFO database_find_user_info_by_id(char *id);
int database_check_user_info_by_id_passwd(char *id,char *passwd);
FRIEND_APPLY_RESULT database_add_friend_apply_info(char *id1, char *id2);

#endif