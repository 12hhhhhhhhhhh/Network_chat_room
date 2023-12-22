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

static lv_obj_t * g_kb_screen_create;
static void kb_screen_create_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_screen_create_event_cb(lv_event_t *e)
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

void setup_scr_screen_create(lv_ui *ui){

	//Write codes screen_create
	ui->screen_create = lv_obj_create(NULL);

	//Create keyboard on screen_create
	g_kb_screen_create = lv_keyboard_create(ui->screen_create);
	lv_obj_add_event_cb(g_kb_screen_create, kb_screen_create_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_screen_create, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_screen_create, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->screen_create, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->screen_create, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_label_7
	ui->screen_create_label_7 = lv_label_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_label_7, 195, 110);
	lv_obj_set_size(ui->screen_create_label_7, 100, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_7, "name:");
	lv_label_set_long_mode(ui->screen_create_label_7, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_7. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_7, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_7, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_7, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_ta_4
	ui->screen_create_ta_4 = lv_textarea_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_ta_4, 300, 110);
	lv_obj_set_size(ui->screen_create_ta_4, 250, 36);
	lv_obj_set_scrollbar_mode(ui->screen_create_ta_4, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_ta_4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_ta_4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_ta_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_ta_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_ta_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_ta_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_ta_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_ta_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_ta_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_ta_4, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_ta_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_ta_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_ta_4, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_ta_4, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_ta_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_ta_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_ta_4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_ta_4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_ta_4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_ta_4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_ta_4. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_4, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_4, lv_color_make(0x21, 0x95, 0xf6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_4, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->screen_create_ta_4,"Hello World");

	//use keyboard on screen_create_ta_4
	lv_obj_add_event_cb(ui->screen_create_ta_4, ta_screen_create_event_cb, LV_EVENT_ALL, g_kb_screen_create);

	//Write codes screen_create_label_8
	ui->screen_create_label_8 = lv_label_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_label_8, 195, 165);
	lv_obj_set_size(ui->screen_create_label_8, 100, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_8, "id:");
	lv_label_set_long_mode(ui->screen_create_label_8, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_8. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_8, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_8, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_8, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_label_9
	ui->screen_create_label_9 = lv_label_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_label_9, 175, 220);
	lv_obj_set_size(ui->screen_create_label_9, 120, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_9, "passwd:");
	lv_label_set_long_mode(ui->screen_create_label_9, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_9. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_9, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_9, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_9, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_ta_5
	ui->screen_create_ta_5 = lv_textarea_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_ta_5, 300, 165);
	lv_obj_set_size(ui->screen_create_ta_5, 250, 36);
	lv_obj_set_scrollbar_mode(ui->screen_create_ta_5, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_ta_5. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_5, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_5, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_ta_5, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_ta_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_ta_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_ta_5, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_ta_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_ta_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_ta_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_ta_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_ta_5, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_ta_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_ta_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_ta_5, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_ta_5, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_ta_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_ta_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_ta_5, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_ta_5, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_ta_5, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_ta_5, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_ta_5. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_5, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_5, lv_color_make(0x21, 0x95, 0xf6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_5, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->screen_create_ta_5,"Hello World");

	//use keyboard on screen_create_ta_5
	lv_obj_add_event_cb(ui->screen_create_ta_5, ta_screen_create_event_cb, LV_EVENT_ALL, g_kb_screen_create);

	//Write codes screen_create_ta_6
	ui->screen_create_ta_6 = lv_textarea_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_ta_6, 300, 220);
	lv_obj_set_size(ui->screen_create_ta_6, 250, 36);
	lv_obj_set_scrollbar_mode(ui->screen_create_ta_6, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_ta_6. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_6, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_6, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_ta_6, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_ta_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_ta_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_ta_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_ta_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_ta_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_ta_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_ta_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_ta_6, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_ta_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_ta_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_ta_6, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_ta_6, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_ta_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_ta_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_ta_6, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_ta_6, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_ta_6, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_ta_6, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_ta_6. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_6, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_6, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->screen_create_ta_6,"Hello World");

	//use keyboard on screen_create_ta_6
	lv_obj_add_event_cb(ui->screen_create_ta_6, ta_screen_create_event_cb, LV_EVENT_ALL, g_kb_screen_create);

	//Write codes screen_create_ta_7
	ui->screen_create_ta_7 = lv_textarea_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_ta_7, 300, 275);
	lv_obj_set_size(ui->screen_create_ta_7, 250, 36);
	lv_obj_set_scrollbar_mode(ui->screen_create_ta_7, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_ta_7. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_7, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_7, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_ta_7, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_ta_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_ta_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_ta_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_ta_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_ta_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_ta_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_ta_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_ta_7, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_ta_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_ta_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_ta_7, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_ta_7, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_ta_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_ta_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_ta_7, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_ta_7, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_ta_7, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_ta_7, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_ta_7. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_ta_7, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_ta_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_ta_7, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_textarea_set_text(ui->screen_create_ta_7,"Hello World");

	//use keyboard on screen_create_ta_7
	lv_obj_add_event_cb(ui->screen_create_ta_7, ta_screen_create_event_cb, LV_EVENT_ALL, g_kb_screen_create);

	//Write codes screen_create_label_10
	ui->screen_create_label_10 = lv_label_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_label_10, 150, 275);
	lv_obj_set_size(ui->screen_create_label_10, 150, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_10, "confirm:");
	lv_label_set_long_mode(ui->screen_create_label_10, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_10. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_10, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_10, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_10, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_10, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_btn_1
	ui->screen_create_btn_1 = lv_btn_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_btn_1, 335, 375);
	lv_obj_set_size(ui->screen_create_btn_1, 100, 50);
	lv_obj_set_scrollbar_mode(ui->screen_create_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_btn_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_btn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_btn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_btn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_btn_1, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_btn_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_btn_1, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_btn_1, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen_create_btn_1_label = lv_label_create(ui->screen_create_btn_1);
	lv_label_set_text(ui->screen_create_btn_1_label, "Create");
	lv_obj_set_style_pad_all(ui->screen_create_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen_create_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen_create_create_account_success_cont_1
	ui->screen_create_create_account_success_cont_1 = lv_obj_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_create_account_success_cont_1, 235, 165);
	lv_obj_set_size(ui->screen_create_create_account_success_cont_1, 250, 100);
	lv_obj_set_scrollbar_mode(ui->screen_create_create_account_success_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_create_account_success_cont_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_create_account_success_cont_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_create_account_success_cont_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_create_account_success_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_create_account_success_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_create_account_success_cont_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_create_account_success_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_create_account_success_cont_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_create_account_success_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_create_account_success_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_create_account_success_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Hidden for widget screen_create_create_account_success_cont_1
	lv_obj_add_flag(ui->screen_create_create_account_success_cont_1, LV_OBJ_FLAG_HIDDEN);


	//Write codes screen_create_img_4
	ui->screen_create_img_4 = lv_img_create(ui->screen_create_create_account_success_cont_1);
	lv_obj_set_pos(ui->screen_create_img_4, 25, 25);
	lv_obj_set_size(ui->screen_create_img_4, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_create_img_4, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_img_4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->screen_create_img_4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_create_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_create_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_create_img_4,&_10_alpha_50x50);
	lv_img_set_pivot(ui->screen_create_img_4, 50,50);
	lv_img_set_angle(ui->screen_create_img_4, 0);

	//Write codes screen_create_label_11
	ui->screen_create_label_11 = lv_label_create(ui->screen_create_create_account_success_cont_1);
	lv_obj_set_pos(ui->screen_create_label_11, 80, 30);
	lv_obj_set_size(ui->screen_create_label_11, 140, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_11, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_11, "Create Success!");
	lv_label_set_long_mode(ui->screen_create_label_11, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_11. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_11, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_11, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_11, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_11, lv_color_make(0xb4, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_11, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_11, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_imgbtn_8
	ui->screen_create_imgbtn_8 = lv_imgbtn_create(ui->screen_create_create_account_success_cont_1);
	lv_obj_set_pos(ui->screen_create_imgbtn_8, 220, 5);
	lv_obj_set_size(ui->screen_create_imgbtn_8, 20, 20);
	lv_obj_set_scrollbar_mode(ui->screen_create_imgbtn_8, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_imgbtn_8. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_8, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_imgbtn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_8, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_imgbtn_8. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_8, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_8, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_create_imgbtn_8. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_8, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_8, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_8, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_8, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_8, LV_IMGBTN_STATE_RELEASED, NULL, &_11_1_alpha_20x20, NULL);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_8, LV_IMGBTN_STATE_PRESSED, NULL, &_11_2_alpha_20x20, NULL);
	lv_obj_add_flag(ui->screen_create_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);

	//Write codes screen_create_create_account_fail_cont_1
	ui->screen_create_create_account_fail_cont_1 = lv_obj_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_create_account_fail_cont_1, 235, 165);
	lv_obj_set_size(ui->screen_create_create_account_fail_cont_1, 250, 100);
	lv_obj_set_scrollbar_mode(ui->screen_create_create_account_fail_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_create_account_fail_cont_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_create_account_fail_cont_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_create_account_fail_cont_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_create_account_fail_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_create_account_fail_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_create_account_fail_cont_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_create_account_fail_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_create_create_account_fail_cont_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_create_create_account_fail_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_create_create_account_fail_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_create_account_fail_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Hidden for widget screen_create_create_account_fail_cont_1
	lv_obj_add_flag(ui->screen_create_create_account_fail_cont_1, LV_OBJ_FLAG_HIDDEN);


	//Write codes screen_create_img_5
	ui->screen_create_img_5 = lv_img_create(ui->screen_create_create_account_fail_cont_1);
	lv_obj_set_pos(ui->screen_create_img_5, 25, 25);
	lv_obj_set_size(ui->screen_create_img_5, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_create_img_5, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_img_5. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->screen_create_img_5, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_create_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_create_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_create_img_5,&_10_1_alpha_50x50);
	lv_img_set_pivot(ui->screen_create_img_5, 50,50);
	lv_img_set_angle(ui->screen_create_img_5, 0);

	//Write codes screen_create_label_12
	ui->screen_create_label_12 = lv_label_create(ui->screen_create_create_account_fail_cont_1);
	lv_obj_set_pos(ui->screen_create_label_12, 80, 30);
	lv_obj_set_size(ui->screen_create_label_12, 150, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_12, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_12, "Fail！");
	lv_label_set_long_mode(ui->screen_create_label_12, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_12. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_12, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_12, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_12, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_12, lv_color_make(0xaa, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_12, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_12, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_imgbtn_9
	ui->screen_create_imgbtn_9 = lv_imgbtn_create(ui->screen_create_create_account_fail_cont_1);
	lv_obj_set_pos(ui->screen_create_imgbtn_9, 220, 5);
	lv_obj_set_size(ui->screen_create_imgbtn_9, 20, 20);
	lv_obj_set_scrollbar_mode(ui->screen_create_imgbtn_9, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_imgbtn_9. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_9, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_imgbtn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_9, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_imgbtn_9. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_9, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_9, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_create_imgbtn_9. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_9, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_9, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_9, LV_IMGBTN_STATE_RELEASED, NULL, &_11_1_alpha_20x20, NULL);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_9, LV_IMGBTN_STATE_PRESSED, NULL, &_11_2_alpha_20x20, NULL);
	lv_obj_add_flag(ui->screen_create_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);

	//Write codes screen_create_label_26
	ui->screen_create_label_26 = lv_label_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_label_26, 290, 320);
	lv_obj_set_size(ui->screen_create_label_26, 200, 32);
	lv_obj_set_scrollbar_mode(ui->screen_create_label_26, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_create_label_26, "Tips:please input!");
	lv_label_set_long_mode(ui->screen_create_label_26, LV_LABEL_LONG_WRAP);

	//Set style for screen_create_label_26. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_create_label_26, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_create_label_26, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_create_label_26, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_create_label_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_label_26, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_label_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_label_26, lv_color_make(0xb4, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_create_label_26, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_label_26, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_create_label_26, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_create_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_create_imgbtn_13
	ui->screen_create_imgbtn_13 = lv_imgbtn_create(ui->screen_create);
	lv_obj_set_pos(ui->screen_create_imgbtn_13, 745, 5);
	lv_obj_set_size(ui->screen_create_imgbtn_13, 50, 50);
	lv_obj_set_scrollbar_mode(ui->screen_create_imgbtn_13, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_create_imgbtn_13. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_13, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_13, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_create_imgbtn_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_13, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for screen_create_imgbtn_13. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_13, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_13, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_13, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_13, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_13, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for screen_create_imgbtn_13. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->screen_create_imgbtn_13, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->screen_create_imgbtn_13, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_create_imgbtn_13, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->screen_create_imgbtn_13, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->screen_create_imgbtn_13, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_create_imgbtn_13, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_13, LV_IMGBTN_STATE_RELEASED, NULL, &_11_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_13, LV_IMGBTN_STATE_PRESSED, NULL, &_11_2_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_13, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_11_1_alpha_50x50, NULL);
	lv_imgbtn_set_src(ui->screen_create_imgbtn_13, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_11_2_alpha_50x50, NULL);
	lv_obj_add_flag(ui->screen_create_imgbtn_13, LV_OBJ_FLAG_CHECKABLE);
}