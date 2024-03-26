#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "service.h"

extern MYSQL *mysqlfd;



int database_init(void);
int database_find_user_by_id(char *id);
int database_user_info_add(client_data *data);
USER_INFO database_find_user_info_by_id(char *id);
int database_check_user_info_by_id_passwd(char *id,char *passwd);
FRIEND_APPLY_RESULT database_add_friend_apply_info(char *id1, char *id2);
int database_add_friend_apply_reply(char *reply_id, char *apply_id, APPLY_REPLY_FLAG flag);
int database_add_friend(USER_INFO *info, char *id);
int database_add_friend_news(char *send_id, char *recv_id, char *news);
int database_add_friend_record_news(char *send_id, char *recv_id, char *news);

#endif