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
	lv_obj_t *screen_main;
	bool screen_main_del;
	lv_obj_t *screen_main_top_cont_2;
	lv_obj_t *screen_main_digital_clock_1;
	lv_obj_t *screen_main_option_cont_3;
	lv_obj_t *screen_main_imgbtn_1;
	lv_obj_t *screen_main_imgbtn_1_label;
	lv_obj_t *screen_main_imgbtn_2;
	lv_obj_t *screen_main_imgbtn_2_label;
	lv_obj_t *screen_main_imgbtn_3;
	lv_obj_t *screen_main_imgbtn_3_label;
	lv_obj_t *screen_main_imgbtn_4;
	lv_obj_t *screen_main_imgbtn_4_label;
	lv_obj_t *screen_main_message_cont_4;
	lv_obj_t *screen_main_friend_list_1;
	lv_obj_t *screen_main_friend_list_1_item0;
	lv_obj_t *screen_main_friend_list_1_item1;
	lv_obj_t *screen_main_show_message_cont_2;
	lv_obj_t *screen_main_cont_5;
	lv_obj_t *screen_main_label_2;
	lv_obj_t *screen_main_img_7;
	lv_obj_t *screen_main_label_23;
	lv_obj_t *screen_main_cont_6;
	lv_obj_t *screen_main_label_25;
	lv_obj_t *screen_main_img_8;
	lv_obj_t *screen_main_label_24;
	lv_obj_t *screen_main_send_message_cont_3;
	lv_obj_t *screen_main_ta_1;
	lv_obj_t *screen_main_imgbtn_5;
	lv_obj_t *screen_main_imgbtn_5_label;
	lv_obj_t *screen_main_friend_cont_2;
	lv_obj_t *screen_main_imgbtn_manage_31;
	lv_obj_t *screen_main_imgbtn_manage_31_label;
	lv_obj_t *screen_main_imgbtn_friend_2;
	lv_obj_t *screen_main_imgbtn_friend_2_label;
	lv_obj_t *screen_main_imgbtn_group_12;
	lv_obj_t *screen_main_imgbtn_group_12_label;
	lv_obj_t *screen_main_label_13;
	lv_obj_t *screen_main_label_14;
	lv_obj_t *screen_main_label_15;
	lv_obj_t *screen_main_friend_infor_cont_1;
	lv_obj_t *screen_main_list_1;
	lv_obj_t *screen_main_list_1_item0;
	lv_obj_t *screen_main_img_6;
	lv_obj_t *screen_main_label_18;
	lv_obj_t *screen_main_label_20;
	lv_obj_t *screen_main_spangroup_2;
	lv_obj_t *screen_main_imgbtn_11;
	lv_obj_t *screen_main_imgbtn_11_label;
	lv_obj_t *screen_main_btn_2;
	lv_obj_t *screen_main_btn_2_label;
	lv_obj_t *screen_main_btn_3;
	lv_obj_t *screen_main_btn_3_label;
	lv_obj_t *screen_main_label_21;
	lv_obj_t *screen_main_imgbtn_12;
	lv_obj_t *screen_main_imgbtn_12_label;
	lv_obj_t *screen_main_delete_friend_cont_5;
	lv_obj_t *screen_main_label_22;
	lv_obj_t *screen_main_btn_4;
	lv_obj_t *screen_main_btn_4_label;
	lv_obj_t *screen_main_btn_5;
	lv_obj_t *screen_main_btn_5_label;
	lv_obj_t *screen_main_edit_remark_cont_5;
	lv_obj_t *screen_main_btn_7;
	lv_obj_t *screen_main_btn_7_label;
	lv_obj_t *screen_main_btn_6;
	lv_obj_t *screen_main_btn_6_label;
	lv_obj_t *screen_main_ta_8;
	lv_obj_t *screen_main_spangroup_3;
	lv_obj_t *screen_main_group_infor_cont_1;
	lv_obj_t *screen_main_list_2;
	lv_obj_t *screen_main_list_2_item0;
	lv_obj_t *screen_main_manage_fri_group_cont_1;
	lv_obj_t *screen_main_friend_apply_cont;
	lv_obj_t *screen_main_cont_7;
	lv_obj_t *screen_main_line_1;
	lv_obj_t *screen_main_line_2;
	lv_obj_t *screen_main_friend_info_label;
	lv_obj_t *screen_main_btnm_1;
	lv_obj_t *screen_main_label_27;
	lv_obj_t *screen_main_verify_message_cont;
	lv_obj_t *screen_main_label_28;
	lv_obj_t *screen_main_cont_8;
	lv_obj_t *screen_main_line_4;
	lv_obj_t *screen_main_line_3;
	lv_obj_t *screen_main_label_29;
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
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen_main(lv_ui *ui);
void setup_scr_screen_input(lv_ui *ui);
void setup_scr_screen_create(lv_ui *ui);
LV_IMG_DECLARE(_14_1_alpha_60x60);
LV_IMG_DECLARE(_14_2_alpha_60x60);
LV_IMG_DECLARE(_9_alpha_50x40);
LV_IMG_DECLARE(_1_1_alpha_50x50);
LV_IMG_DECLARE(_11_1_alpha_50x50);
LV_IMG_DECLARE(_11_2_alpha_50x50);
LV_IMG_DECLARE(_11_1_alpha_20x20);
LV_IMG_DECLARE(_11_2_alpha_20x20);
LV_IMG_DECLARE(_2_alpha_50x50);
LV_IMG_DECLARE(_3_1_alpha_50x50);
LV_IMG_DECLARE(_3_alpha_50x50);
LV_IMG_DECLARE(_12_2_alpha_60x60);
LV_IMG_DECLARE(_4_alpha_20x20);
LV_IMG_DECLARE(_1_alpha_50x50);
LV_IMG_DECLARE(_12_1_alpha_60x60);
LV_IMG_DECLARE(_8_alpha_50x40);
LV_IMG_DECLARE(_6_1_alpha_50x40);
LV_IMG_DECLARE(_15_1_alpha_40x30);
LV_IMG_DECLARE(_4_alpha_80x80);
LV_IMG_DECLARE(_2_1_alpha_50x50);
LV_IMG_DECLARE(_4_alpha_50x50);
LV_IMG_DECLARE(_17_alpha_40x30);
LV_IMG_DECLARE(_10_alpha_50x50);
LV_IMG_DECLARE(_17_1_alpha_40x30);
LV_IMG_DECLARE(_4_alpha_25x25);
LV_IMG_DECLARE(_15_alpha_40x30);
LV_IMG_DECLARE(_4_1_alpha_50x50);
LV_IMG_DECLARE(_9_1_alpha_50x40);
LV_IMG_DECLARE(_5_1_alpha_40x40);
LV_IMG_DECLARE(_13_2_alpha_60x60);
LV_IMG_DECLARE(_10_1_alpha_50x50);
LV_IMG_DECLARE(_13_1_alpha_60x60);
LV_IMG_DECLARE(_5_alpha_40x40);

#ifdef __cplusplus
}
#endif
#endif