#ifndef _CLICONNECT_H_
#define _CLICONNECT_H_

#include "service.h"

int client_apply_connect(void);
int receive_from_client(int fd);

int user_info_init(char *id, int fd);

#endif