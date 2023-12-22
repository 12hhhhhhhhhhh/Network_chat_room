/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static int screen_owner_digital_clock_1_hour_value = 11;
static int screen_owner_digital_clock_1_min_value = 25;
static int screen_owner_digital_clock_1_sec_value = 50;
static char screen_owner_digital_clock_1_meridiem[] = "AM";
void screen_owner_digital_clock_1_timer(lv_timer_t *timer)
{	clock_count_12(&screen_owner_digital_clock_1_hour_value, &screen_owner_digital_clock_1_min_value, &screen_owner_digital_clock_1_sec_value, screen_owner_digital_clock_1_meridiem);
	if (lv_obj_is_valid(guider_ui.screen_owner_digital_clock_1))
	{
		lv_dclock_set_text_fmt(guider_ui.screen_owner_digital_clock_1, "%02d:%02d:%02d %s", screen_owner_digital_clock_1_hour_value, screen_owner_digital_clock_1_min_value, screen_owner_digital_clock_1_sec_value, screen_owner_digital_clock_1_meridiem);
	}
}
static lv_obj_t * g_kb_screen_owner;
static void kb_screen_owner_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_screen_owner_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void setup_scr_screen_owner(lv_ui *ui){

	//Write codes screen_owner
	ui->screen_owner = lv_obj_create(NULL);

	//Create keyboard on screen_owner
	g_kb_screen_owner = lv_keyboard_create(ui->screen_owner);
	lv_obj_add_event_cb(g_kb_screen_owner, kb_screen_owner_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_screen_owner, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_screen_owner, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->screen_owner, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->screen_owner, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_top_cont_2
	ui->screen_owner_top_cont_2 = lv_obj_create(ui->screen_owner);
	lv_obj_set_pos(ui->screen_owner_top_cont_2, 0, 0);
	lv_obj_set_size(ui->screen_owner_top_cont_2, 800, 50);
	lv_obj_set_scrollbar_mode(ui->screen_owner_top_cont_2, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_top_cont_2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_top_cont_2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_top_cont_2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_top_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_top_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_top_cont_2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_top_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_top_cont_2, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_top_cont_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_top_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_top_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	static bool screen_owner_digital_clock_1_timer_enabled = false;

	//Write codes screen_owner_digital_clock_1
	ui->screen_owner_digital_clock_1 = lv_dclock_create(ui->screen_owner_top_cont_2,"11:25:50 AM");
	lv_obj_set_style_text_align(ui->screen_owner_digital_clock_1, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_pos(ui->screen_owner_digital_clock_1, 650, 0);
	lv_obj_set_size(ui->screen_owner_digital_clock_1, 150, 50);

	//create timer
	if (!screen_owner_digital_clock_1_timer_enabled) {
		lv_timer_create(screen_owner_digital_clock_1_timer, 1000, NULL);
		screen_owner_digital_clock_1_timer_enabled = true;
	}
	//Set style for screen_owner_digital_clock_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_digital_clock_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_digital_clock_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_digital_clock_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_digital_clock_1, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_digital_clock_1, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_option_cont_3
	ui->screen_owner_option_cont_3 = lv_obj_create(ui->screen_owner);
	lv_obj_set_pos(ui->screen_owner_option_cont_3, 0, 430);
	lv_obj_set_size(ui->screen_owner_option_cont_3, 800, 50);
	lv_obj_set_scrollbar_mode(ui->screen_owner_option_cont_3, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_option_cont_3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_option_cont_3, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_option_cont_3, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_option_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_option_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_option_cont_3, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_option_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_option_cont_3, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_option_cont_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_option_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_option_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_imgbtn_1
	ui->screen_owner_imgbtn_1 = lv_imgbtn_create(ui->screen_owner_option_cont_3);
	lv_obj_set_pos(ui->screen_owner_imgbtn_1, 75, 0);
	lv_obj_set_size(ui->screen_owner_imgbtn_1, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_owner_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_imgbtn_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_1, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_imgbtn_1. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_1, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_1, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_owner_imgbtn_1. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_1, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_1, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_1_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_1_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_1_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_1, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_1_1_alpha_50x50, NULL);

	//Write codes screen_owner_imgbtn_2
	ui->screen_owner_imgbtn_2 = lv_imgbtn_create(ui->screen_owner_option_cont_3);
	lv_obj_set_pos(ui->screen_owner_imgbtn_2, 275, 0);
	lv_obj_set_size(ui->screen_owner_imgbtn_2, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_owner_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_imgbtn_2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_2, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_imgbtn_2. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_2, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_2, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_owner_imgbtn_2. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_2, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_2, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_2_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_2, LV_IMGBTN_STATE_PRESSED, NULL, &_2_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_2, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_2_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_2, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_2_1_alpha_50x50, NULL);

	//Write codes screen_owner_imgbtn_3
	ui->screen_owner_imgbtn_3 = lv_imgbtn_create(ui->screen_owner_option_cont_3);
	lv_obj_set_pos(ui->screen_owner_imgbtn_3, 475, 0);
	lv_obj_set_size(ui->screen_owner_imgbtn_3, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_owner_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_imgbtn_3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_3, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_3, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_3, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_imgbtn_3. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_3, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_3, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_3, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_owner_imgbtn_3. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_3, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_3, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_3, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_3_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_3, LV_IMGBTN_STATE_PRESSED, NULL, &_3_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_3, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_3_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_3, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_3_1_alpha_50x50, NULL);

	//Write codes screen_owner_imgbtn_4
	ui->screen_owner_imgbtn_4 = lv_imgbtn_create(ui->screen_owner_option_cont_3);
	lv_obj_set_pos(ui->screen_owner_imgbtn_4, 675, 0);
	lv_obj_set_size(ui->screen_owner_imgbtn_4, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_owner_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_imgbtn_4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_imgbtn_4. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_4, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_owner_imgbtn_4. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_4, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_23_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_4, LV_IMGBTN_STATE_PRESSED, NULL, &_24_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_4, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_23_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_4, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_24_2_alpha_50x50, NULL);

	//Write codes screen_owner_cont_owner
	ui->screen_owner_cont_owner = lv_obj_create(ui->screen_owner);
	lv_obj_set_pos(ui->screen_owner_cont_owner, 0, 50);
	lv_obj_set_size(ui->screen_owner_cont_owner, 800, 380);
	lv_obj_set_scrollbar_mode(ui->screen_owner_cont_owner, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_cont_owner. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_cont_owner, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_cont_owner, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_cont_owner, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_cont_owner, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_cont_owner, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_cont_owner, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_cont_owner, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_cont_owner, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_cont_owner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_img_9
	ui->screen_owner_img_9 = lv_img_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_img_9, 360, 50);
	lv_obj_set_size(ui->screen_owner_img_9, 80, 80);
	lv_obj_set_scrollbar_mode(ui->screen_owner_img_9, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_img_9. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->screen_owner_img_9, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_owner_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_owner_img_9,&_4_2_alpha_80x80);
	lv_img_set_pivot(ui->screen_owner_img_9, 50,50);
	lv_img_set_angle(ui->screen_owner_img_9, 0);

	//Write codes screen_owner_label_30
	ui->screen_owner_label_30 = lv_label_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_label_30, 300, 135);
	lv_obj_set_size(ui->screen_owner_label_30, 200, 24);
	lv_obj_set_scrollbar_mode(ui->screen_owner_label_30, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_owner_label_30, "the best boy");
	lv_label_set_long_mode(ui->screen_owner_label_30, LV_LABEL_LONG_WRAP);

	//Set style for screen_owner_label_30. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_label_30, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_label_30, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_label_30, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_label_30, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_label_30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_label_30, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_label_30, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_label_30, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_label_29
	ui->screen_owner_label_29 = lv_label_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_label_29, 300, 175);
	lv_obj_set_size(ui->screen_owner_label_29, 200, 24);
	lv_obj_set_scrollbar_mode(ui->screen_owner_label_29, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_owner_label_29, "id:1355692441");
	lv_label_set_long_mode(ui->screen_owner_label_29, LV_LABEL_LONG_WRAP);

	//Set style for screen_owner_label_29. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_label_29, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_label_29, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_label_29, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_label_29, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_label_29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_label_29, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_label_29, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_label_29, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_label_28
	ui->screen_owner_label_28 = lv_label_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_label_28, 250, 215);
	lv_obj_set_size(ui->screen_owner_label_28, 300, 24);
	lv_obj_set_scrollbar_mode(ui->screen_owner_label_28, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_owner_label_28, "flag:the world is best world!");
	lv_label_set_long_mode(ui->screen_owner_label_28, LV_LABEL_LONG_WRAP);

	//Set style for screen_owner_label_28. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_label_28, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_label_28, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_label_28, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_label_28, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_label_28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_label_28, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_label_28, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_label_28, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_owner_imgbtn_15
	ui->screen_owner_imgbtn_15 = lv_imgbtn_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_imgbtn_15, 690, 10);
	lv_obj_set_size(ui->screen_owner_imgbtn_15, 30, 30);
	lv_obj_set_scrollbar_mode(ui->screen_owner_imgbtn_15, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_imgbtn_15. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_15, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_15, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_imgbtn_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_15, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_imgbtn_15. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_15, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_15, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_15, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_owner_imgbtn_15. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_15, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_15, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_15, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_15, LV_IMGBTN_STATE_RELEASED, NULL, &_17_alpha_30x30, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_15, LV_IMGBTN_STATE_PRESSED, NULL, &_17_1_alpha_30x30, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_15, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_17_alpha_30x30, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_15, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_17_1_alpha_30x30, NULL);
	lv_obj_add_flag(ui->screen_owner_imgbtn_15, LV_OBJ_FLAG_CHECKABLE);

	//Write codes screen_owner_cont_7
	ui->screen_owner_cont_7 = lv_obj_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_cont_7, 300, 132);
	lv_obj_set_size(ui->screen_owner_cont_7, 300, 150);
	lv_obj_set_scrollbar_mode(ui->screen_owner_cont_7, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_cont_7. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_cont_7, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_cont_7, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_cont_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_cont_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_cont_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_cont_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_cont_7, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_cont_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_cont_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Hidden for widget screen_owner_cont_7
	lv_obj_add_flag(ui->screen_owner_cont_7, LV_OBJ_FLAG_HIDDEN);


	//Write codes screen_owner_btn_9
	ui->screen_owner_btn_9 = lv_btn_create(ui->screen_owner_cont_7);
	lv_obj_set_pos(ui->screen_owner_btn_9, 50, 105);
	lv_obj_set_size(ui->screen_owner_btn_9, 80, 35);
	lv_obj_set_scrollbar_mode(ui->screen_owner_btn_9, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_btn_9. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_btn_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_btn_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_btn_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_btn_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_btn_9, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_btn_9, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_btn_9, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_btn_9, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_btn_9, &lv_font_arial_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_btn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_owner_btn_9_label = lv_label_create(ui->screen_owner_btn_9);
	lv_label_set_text(ui->screen_owner_btn_9_label, "YES");
	lv_obj_set_style_pad_all(ui->screen_owner_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_owner_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_owner_btn_8
	ui->screen_owner_btn_8 = lv_btn_create(ui->screen_owner_cont_7);
	lv_obj_set_pos(ui->screen_owner_btn_8, 160, 105);
	lv_obj_set_size(ui->screen_owner_btn_8, 80, 35);
	lv_obj_set_scrollbar_mode(ui->screen_owner_btn_8, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_btn_8. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_btn_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_btn_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_btn_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_btn_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_btn_8, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_btn_8, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_btn_8, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_btn_8, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_btn_8, &lv_font_arial_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_owner_btn_8_label = lv_label_create(ui->screen_owner_btn_8);
	lv_label_set_text(ui->screen_owner_btn_8_label, "NO");
	lv_obj_set_style_pad_all(ui->screen_owner_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_owner_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_owner_ta_10
	ui->screen_owner_ta_10 = lv_textarea_create(ui->screen_owner_cont_7);
	lv_obj_set_pos(ui->screen_owner_ta_10, 30, 25);
	lv_obj_set_size(ui->screen_owner_ta_10, 250, 40);
	lv_obj_set_scrollbar_mode(ui->screen_owner_ta_10, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_ta_10. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_ta_10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_ta_10, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_ta_10, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_ta_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_ta_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_ta_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_ta_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_ta_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_ta_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_ta_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_ta_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_ta_10, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_ta_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_ta_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_ta_10, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_owner_ta_10, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_owner_ta_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_ta_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_ta_10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_ta_10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_ta_10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_ta_10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_ta_10. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_ta_10, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_ta_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_ta_10, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->screen_owner_ta_10,"Hello World");

	//use keyboard on screen_owner_ta_10
	lv_obj_add_event_cb(ui->screen_owner_ta_10, ta_screen_owner_event_cb, LV_EVENT_ALL, g_kb_screen_owner);

	//Write codes screen_owner_spangroup_4
	ui->screen_owner_spangroup_4 = lv_spangroup_create(ui->screen_owner_cont_7);
	lv_obj_set_pos(ui->screen_owner_spangroup_4, 40, 75);
	lv_obj_set_size(ui->screen_owner_spangroup_4, 250, 24);
	lv_obj_set_scrollbar_mode(ui->screen_owner_spangroup_4, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->screen_owner_spangroup_4, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_owner_spangroup_4, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_owner_spangroup_4, LV_SPAN_MODE_BREAK);

	//Set style for screen_owner_spangroup_4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_owner_spangroup_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_owner_spangroup_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_owner_spangroup_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_spangroup_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_spangroup_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_owner_spangroup_4, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_owner_spangroup_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_owner_spangroup_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *screen_owner_spangroup_4_span;

	//create a new span
	screen_owner_spangroup_4_span = lv_spangroup_new_span(ui->screen_owner_spangroup_4);
	lv_span_set_text(screen_owner_spangroup_4_span, "please input the friend's remark!");
	lv_style_set_text_color(&screen_owner_spangroup_4_span->style, lv_color_make(0x3c, 0x3c, 0x3c));
	lv_style_set_text_decor(&screen_owner_spangroup_4_span->style, LV_TEXT_DECOR_UNDERLINE);
	lv_style_set_text_font(&screen_owner_spangroup_4_span->style, &lv_font_arial_16);
	lv_spangroup_refr_mode(ui->screen_owner_spangroup_4);

	//Write codes screen_owner_imgbtn_16
	ui->screen_owner_imgbtn_16 = lv_imgbtn_create(ui->screen_owner_cont_owner);
	lv_obj_set_pos(ui->screen_owner_imgbtn_16, 740, 10);
	lv_obj_set_size(ui->screen_owner_imgbtn_16, 30, 30);
	lv_obj_set_scrollbar_mode(ui->screen_owner_imgbtn_16, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_owner_imgbtn_16. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_16, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_owner_imgbtn_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_16, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_owner_imgbtn_16. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_16, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_16, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_owner_imgbtn_16. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_owner_imgbtn_16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_owner_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_owner_imgbtn_16, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_owner_imgbtn_16, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_owner_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_owner_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_16, LV_IMGBTN_STATE_RELEASED, NULL, &_20_2_alpha_30x30, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_16, LV_IMGBTN_STATE_PRESSED, NULL, &_20_1_alpha_30x30, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_16, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_20_2_alpha_30x30, NULL);
	lv_imgbtn_set_src(ui->screen_owner_imgbtn_16, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_20_1_alpha_30x30, NULL);
	lv_obj_add_flag(ui->screen_owner_imgbtn_16, LV_OBJ_FLAG_CHECKABLE);

	//Init events for screen
	events_init_screen_owner(ui);
}