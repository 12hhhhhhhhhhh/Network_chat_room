#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include "service.h"

int link_list_init(void);
int link_list_add(client_data *buf);
int link_list_add_recvfd(char *id,int recv_fd);
int link_list_find(int fd);
int link_list_del_by_fd(int fd);

#endif