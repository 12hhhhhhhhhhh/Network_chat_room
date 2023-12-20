// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

pthread_t connectid;

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    setup_scr_screen_input(ui);
    setup_scr_screen_create(ui);
    setup_scr_screen_main(ui);
    lv_scr_load(guider_ui.screen_input);
    
    custom_events_init(&guider_ui);
    /* Add your codes here */
    message_page_init();
    printf("hello world\r\n");
    connect_network(&socketfd);
    printf("socketfd0:%d\r\n",socketfd);
    connect_network(&recv_socketfd);
    printf("socketfd1:%d\r\n",recv_socketfd);
    printf("4\r\n");

    pthread_create(&connectid,NULL,net_talkroom_recv,NULL);
    pthread_detach(connectid);
    // pthread_join(connectid,NULL);
}

