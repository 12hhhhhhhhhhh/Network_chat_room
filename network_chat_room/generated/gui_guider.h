/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen_message;
	bool screen_message_del;
	lv_obj_t *screen_message_top_cont_2;
	lv_obj_t *screen_message_digital_clock_1;
	lv_obj_t *screen_message_option_cont_3;
	lv_obj_t *screen_message_imgbtn_1;
	lv_obj_t *screen_message_imgbtn_1_label;
	lv_obj_t *screen_message_imgbtn_2;
	lv_obj_t *screen_message_imgbtn_2_label;
	lv_obj_t *screen_message_imgbtn_3;
	lv_obj_t *screen_message_imgbtn_3_label;
	lv_obj_t *screen_message_imgbtn_4;
	lv_obj_t *screen_message_imgbtn_4_label;
	lv_obj_t *screen_message_message_cont_4;
	lv_obj_t *screen_message_friend_list_1;
	lv_obj_t *screen_message_friend_list_1_item0;
	lv_obj_t *screen_message_friend_list_1_item1;
	lv_obj_t *screen_message_show_message_cont_2;
	lv_obj_t *screen_message_cont_5;
	lv_obj_t *screen_message_label_2;
	lv_obj_t *screen_message_img_7;
	lv_obj_t *screen_message_label_23;
	lv_obj_t *screen_message_cont_6;
	lv_obj_t *screen_message_label_25;
	lv_obj_t *screen_message_img_8;
	lv_obj_t *screen_message_label_24;
	lv_obj_t *screen_message_send_message_cont_3;
	lv_obj_t *screen_message_ta_1;
	lv_obj_t *screen_message_imgbtn_5;
	lv_obj_t *screen_message_imgbtn_5_label;
	lv_obj_t *screen_input;
	bool screen_input_del;
	lv_obj_t *screen_input_cont_4;
	lv_obj_t *screen_input_ta_2;
	lv_obj_t *screen_input_label_3;
	lv_obj_t *screen_input_img_3;
	lv_obj_t *screen_input_imgbtn_6;
	lv_obj_t *screen_input_imgbtn_6_label;
	lv_obj_t *screen_input_label_4;
	lv_obj_t *screen_input_ta_3;
	lv_obj_t *screen_input_imgbtn_7;
	lv_obj_t *screen_input_imgbtn_7_label;
	lv_obj_t *screen_input_label_5;
	lv_obj_t *screen_input_label_6;
	lv_obj_t *screen_input_datetext_1;
	lv_obj_t *screen_create;
	bool screen_create_del;
	lv_obj_t *screen_create_label_7;
	lv_obj_t *screen_create_ta_4;
	lv_obj_t *screen_create_label_8;
	lv_obj_t *screen_create_label_9;
	lv_obj_t *screen_create_ta_5;
	lv_obj_t *screen_create_ta_6;
	lv_obj_t *screen_create_ta_7;
	lv_obj_t *screen_create_label_10;
	lv_obj_t *screen_create_btn_1;
	lv_obj_t *screen_create_btn_1_label;
	lv_obj_t *screen_create_create_account_success_cont_1;
	lv_obj_t *screen_create_img_4;
	lv_obj_t *screen_create_label_11;
	lv_obj_t *screen_create_imgbtn_8;
	lv_obj_t *screen_create_imgbtn_8_label;
	lv_obj_t *screen_create_create_account_fail_cont_1;
	lv_obj_t *screen_create_img_5;
	lv_obj_t *screen_create_label_12;
	lv_obj_t *screen_create_imgbtn_9;
	lv_obj_t *screen_create_imgbtn_9_label;
	lv_obj_t *screen_create_label_26;
	lv_obj_t *screen_create_imgbtn_13;
	lv_obj_t *screen_create_imgbtn_13_label;
	lv_obj_t *screen_owner;
	bool screen_owner_del;
	lv_obj_t *screen_owner_top_cont_2;
	lv_obj_t *screen_owner_digital_clock_1;
	lv_obj_t *screen_owner_option_cont_3;
	lv_obj_t *screen_owner_imgbtn_1;
	lv_obj_t *screen_owner_imgbtn_1_label;
	lv_obj_t *screen_owner_imgbtn_2;
	lv_obj_t *screen_owner_imgbtn_2_label;
	lv_obj_t *screen_owner_imgbtn_3;
	lv_obj_t *screen_owner_imgbtn_3_label;
	lv_obj_t *screen_owner_imgbtn_4;
	lv_obj_t *screen_owner_imgbtn_4_label;
	lv_obj_t *screen_owner_cont_owner;
	lv_obj_t *screen_owner_img_9;
	lv_obj_t *screen_owner_label_30;
	lv_obj_t *screen_owner_label_29;
	lv_obj_t *screen_owner_label_28;
	lv_obj_t *screen_owner_imgbtn_15;
	lv_obj_t *screen_owner_imgbtn_15_label;
	lv_obj_t *screen_owner_cont_7;
	lv_obj_t *screen_owner_btn_9;
	lv_obj_t *screen_owner_btn_9_label;
	lv_obj_t *screen_owner_btn_8;
	lv_obj_t *screen_owner_btn_8_label;
	lv_obj_t *screen_owner_ta_10;
	lv_obj_t *screen_owner_spangroup_4;
	lv_obj_t *screen_owner_imgbtn_16;
	lv_obj_t *screen_owner_imgbtn_16_label;
	lv_obj_t *screen_friend;
	bool screen_friend_del;
	lv_obj_t *screen_friend_top_cont_2;
	lv_obj_t *screen_friend_digital_clock_1;
	lv_obj_t *screen_friend_option_cont_3;
	lv_obj_t *screen_friend_imgbtn_1;
	lv_obj_t *screen_friend_imgbtn_1_label;
	lv_obj_t *screen_friend_imgbtn_2;
	lv_obj_t *screen_friend_imgbtn_2_label;
	lv_obj_t *screen_friend_imgbtn_3;
	lv_obj_t *screen_friend_imgbtn_3_label;
	lv_obj_t *screen_friend_imgbtn_4;
	lv_obj_t *screen_friend_imgbtn_4_label;
	lv_obj_t *screen_friend_friend_cont_2;
	lv_obj_t *screen_friend_friend_infor_cont_1;
	lv_obj_t *screen_friend_img_6;
	lv_obj_t *screen_friend_label_18;
	lv_obj_t *screen_friend_label_20;
	lv_obj_t *screen_friend_spangroup_2;
	lv_obj_t *screen_friend_imgbtn_11;
	lv_obj_t *screen_friend_imgbtn_11_label;
	lv_obj_t *screen_friend_btn_2;
	lv_obj_t *screen_friend_btn_2_label;
	lv_obj_t *screen_friend_btn_3;
	lv_obj_t *screen_friend_btn_3_label;
	lv_obj_t *screen_friend_label_21;
	lv_obj_t *screen_friend_imgbtn_12;
	lv_obj_t *screen_friend_imgbtn_12_label;
	lv_obj_t *screen_friend_delete_friend_cont_5;
	lv_obj_t *screen_friend_label_22;
	lv_obj_t *screen_friend_btn_4;
	lv_obj_t *screen_friend_btn_4_label;
	lv_obj_t *screen_friend_btn_5;
	lv_obj_t *screen_friend_btn_5_label;
	lv_obj_t *screen_friend_edit_remark_cont_5;
	lv_obj_t *screen_friend_btn_7;
	lv_obj_t *screen_friend_btn_7_label;
	lv_obj_t *screen_friend_btn_6;
	lv_obj_t *screen_friend_btn_6_label;
	lv_obj_t *screen_friend_ta_8;
	lv_obj_t *screen_friend_spangroup_3;
	lv_obj_t *screen_friend_friend_list;
	lv_obj_t *screen_friend_friend_list_item0;
	lv_obj_t *screen_friend_search_cont;
	lv_obj_t *screen_friend_imgbtn_14;
	lv_obj_t *screen_friend_imgbtn_14_label;
	lv_obj_t *screen_friend_ta_9;
	lv_obj_t *screen_circle;
	bool screen_circle_del;
	lv_obj_t *screen_circle_top_cont_2;
	lv_obj_t *screen_circle_digital_clock_1;
	lv_obj_t *screen_circle_option_cont_3;
	lv_obj_t *screen_circle_imgbtn_1;
	lv_obj_t *screen_circle_imgbtn_1_label;
	lv_obj_t *screen_circle_imgbtn_2;
	lv_obj_t *screen_circle_imgbtn_2_label;
	lv_obj_t *screen_circle_imgbtn_3;
	lv_obj_t *screen_circle_imgbtn_3_label;
	lv_obj_t *screen_circle_imgbtn_4;
	lv_obj_t *screen_circle_imgbtn_4_label;
	lv_obj_t *screen_circle_circle_cont_2;
	lv_obj_t *screen_circle_circle_infor_cont_1;
	lv_obj_t *screen_circle_label_31;
	lv_obj_t *screen_circle_img_10;
	lv_obj_t *screen_circle_spangroup_7;
	lv_obj_t *screen_circle_img_11;
	lv_obj_t *screen_circle_imgbtn_17;
	lv_obj_t *screen_circle_imgbtn_17_label;
	lv_obj_t *screen_circle_imgbtn_18;
	lv_obj_t *screen_circle_imgbtn_18_label;
	lv_obj_t *screen_circle_cont_8;
	lv_obj_t *screen_circle_spangroup_5;
	lv_obj_t *screen_circle_cont_9;
	lv_obj_t *screen_circle_spangroup_6;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen_message(lv_ui *ui);
void setup_scr_screen_input(lv_ui *ui);
void setup_scr_screen_create(lv_ui *ui);
void setup_scr_screen_owner(lv_ui *ui);
void setup_scr_screen_friend(lv_ui *ui);
void setup_scr_screen_circle(lv_ui *ui);
LV_IMG_DECLARE(_10_alpha_50x50);
LV_IMG_DECLARE(_1_1_alpha_50x50);
LV_IMG_DECLARE(_4_1_alpha_50x50);
LV_IMG_DECLARE(_11_1_alpha_20x20);
LV_IMG_DECLARE(_10_1_alpha_50x50);
LV_IMG_DECLARE(_2_1_alpha_50x50);
LV_IMG_DECLARE(_11_2_alpha_20x20);

#ifdef __cplusplus
}
#endif
#endif