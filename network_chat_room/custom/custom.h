// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "sqlite3.h"
#include "sys/prctl.h"

#include "common.h"
#include "gui_guider.h"
#include "net_talkromm.h"
#include "custom_event.h"
#include "function.h"
#include "link_list.h"
#include "contacts_page.h"
#include "message_page.h"
#include "owner_page.h"
#include "database.h"
#include "print_ext.h"

void custom_init(lv_ui *ui);

#endif /* EVENT_CB_H_ */
