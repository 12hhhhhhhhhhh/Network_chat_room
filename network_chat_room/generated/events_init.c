/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

void events_init(lv_ui *ui)
{
}

static void screen_main_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_message_cont_4, 0, 50);
		lv_obj_clear_flag(guider_ui.screen_main_message_cont_4, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_friend_cont_2, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_imgbtn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_friend_cont_2, 0, 50);
		lv_obj_clear_flag(guider_ui.screen_main_friend_cont_2, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_message_cont_4, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_imgbtn_manage_31_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_manage_fri_group_cont_1, 120, 0);
		lv_obj_clear_flag(guider_ui.screen_main_manage_fri_group_cont_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_group_infor_cont_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_friend_infor_cont_1, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_imgbtn_friend_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_friend_infor_cont_1, 120, 0);
		lv_obj_clear_flag(guider_ui.screen_main_friend_infor_cont_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_group_infor_cont_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_manage_fri_group_cont_1, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_imgbtn_group_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_group_infor_cont_1, 120, 0);
		lv_obj_clear_flag(guider_ui.screen_main_group_infor_cont_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_friend_infor_cont_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_main_manage_fri_group_cont_1, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_imgbtn_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_delete_friend_cont_5, 230, 100);
		lv_obj_clear_flag(guider_ui.screen_main_delete_friend_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_imgbtn_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_pos(guider_ui.screen_main_edit_remark_cont_5, 230, 100);
		lv_obj_clear_flag(guider_ui.screen_main_edit_remark_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_main_delete_friend_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_main_delete_friend_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_main_edit_remark_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

static void screen_main_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_main_edit_remark_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

void events_init_screen_main(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_main_imgbtn_1, screen_main_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_imgbtn_2, screen_main_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_imgbtn_manage_31, screen_main_imgbtn_manage_31_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_imgbtn_friend_2, screen_main_imgbtn_friend_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_imgbtn_group_12, screen_main_imgbtn_group_12_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_imgbtn_11, screen_main_imgbtn_11_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_imgbtn_12, screen_main_imgbtn_12_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_4, screen_main_btn_4_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_5, screen_main_btn_5_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_7, screen_main_btn_7_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_6, screen_main_btn_6_event_handler, LV_EVENT_ALL, ui);
}
