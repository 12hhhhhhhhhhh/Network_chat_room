#include "custom_event.h"

/*
    登陆页面：登陆按钮事件
*/
static void screen_input_imgbtn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        if(strlen(lv_textarea_get_text(guider_ui.screen_input_ta_2)) == 0){
            printf("id can't empty!\r\n");
            break;
        }
        if(strlen(lv_textarea_get_text(guider_ui.screen_input_ta_3)) == 0){
            printf("passwd can't empty!\r\n");
            break;
        }
        client_data input_date = {0};
        int ret = 0;
		strcpy(input_date.id, lv_textarea_get_text(guider_ui.screen_input_ta_2));
        strcpy(input_date.passwd, lv_textarea_get_text(guider_ui.screen_input_ta_3));
        input_date.num = INPUT_ACCOUNT;
        input_date.fd = socketfd;
        input_date.recv_fd = recv_socketfd;
        ret = write(socketfd, &input_date, sizeof(client_data));
        if(ret < 0){
            perror("write");
            close(recv_socketfd);
            break;
        }
        memset(&input_date, 0, sizeof(client_data));
        ret = read(socketfd, &input_date, sizeof(input_date));
        if(ret < 0){
            perror("read");
            break;
        }
        if(input_date.num == ACCOUNT_INPUT_SUCCESS){
            printf("input success!\r\n");
            memset(&input_date, 0, sizeof(input_date));
            input_date.num = CLIENT_RECVFD;
            strcpy(input_date.id, lv_textarea_get_text(guider_ui.screen_input_ta_2));
            ret = write(recv_socketfd, &input_date, sizeof(client_data));
            if(ret < 0){
                perror("write");
                break;
            }
            all_init();
            sleep(5);
            //初始化消息页面
            lv_event_send(guider_ui.screen_message_imgbtn_1, LV_EVENT_CLICKED, NULL);
        }
        else if(input_date.num == ACCOUNT_INPUT_FAIL){
            printf("id or passwd error!\r\n");
        }
	}
		break;
	default:
		break;
	}
}

/*
    登陆页面：注册按钮事件
*/
static void screen_input_imgbtn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_scr_load(guider_ui.screen_create);
	}
		break;
	default:
		break;
	}
}

/*
    注册页面：注册按钮事件
*/
static void screen_create_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        if(strlen(lv_textarea_get_text(guider_ui.screen_create_ta_4)) == 0){
            printf("name is empty!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "name is empty!");
            break;
        }
        else if(strlen(lv_textarea_get_text(guider_ui.screen_create_ta_5)) == 0){
            printf("id is empty!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "id is empty!");
            break;
        }
        else if(check_num_char(lv_textarea_get_text(guider_ui.screen_create_ta_5), \
        strlen(lv_textarea_get_text(guider_ui.screen_create_ta_5))) != 0){
            printf("id only include num char!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "id only include num char!");
            break;
        }
        else if(strlen(lv_textarea_get_text(guider_ui.screen_create_ta_6)) == 0){
            printf("passwd is empty!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "passwd is empty!");
            break;
        }
        else if(check_num_char(lv_textarea_get_text(guider_ui.screen_create_ta_6), \
        strlen(lv_textarea_get_text(guider_ui.screen_create_ta_6))) != 0){
            printf("passwd only include num char!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "passwd only include num char!");
            break;
        }
        else if(strlen(lv_textarea_get_text(guider_ui.screen_create_ta_7)) == 0){
            printf("confirm passwd is empty!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "confirm passwd is empty!");
            break;
        }
        else if(strcmp(lv_textarea_get_text(guider_ui.screen_create_ta_6), lv_textarea_get_text(guider_ui.screen_create_ta_7)) != 0){
            printf("confirm passwd is error!\r\n");
            lv_label_set_text(guider_ui.screen_create_label_26, "confirm passwd is error!");
            break;
        }
        client_data create_account_info = {0};
        int ret = 0;
        strcpy(create_account_info.name, lv_textarea_get_text(guider_ui.screen_create_ta_4));
        strcpy(create_account_info.id, lv_textarea_get_text(guider_ui.screen_create_ta_5));
        strcpy(create_account_info.passwd, lv_textarea_get_text(guider_ui.screen_create_ta_6));
        create_account_info.num = CREATE_ACCOUNT;
        ret = write(socketfd, &create_account_info, sizeof(client_data));
        // if(ret < 0){
            perror("write");
        // }
        memset(&create_account_info, 0, sizeof(client_data));
        ret = read(socketfd, &create_account_info, sizeof(client_data));
        if(ret < 0){
            perror("read");
        }
        if(create_account_info.num == ACCOUNT_CREAT_SUCCESS){
            lv_obj_set_pos(guider_ui.screen_create_create_account_success_cont_1, 235, 165);
            lv_obj_clear_flag(guider_ui.screen_create_create_account_success_cont_1, LV_OBJ_FLAG_HIDDEN); 
        }
        else{
            if(create_account_info.num == ID_EXIST){
                lv_label_set_text(guider_ui.screen_create_label_12, "ID EXIT");
            }
            else{
                lv_label_set_text(guider_ui.screen_create_label_12, "Create Fail");
            }
            lv_obj_set_pos(guider_ui.screen_create_create_account_fail_cont_1, 235, 165);
		    lv_obj_clear_flag(guider_ui.screen_create_create_account_fail_cont_1, LV_OBJ_FLAG_HIDDEN);
        }
	}
		break;
	default:
		break;
	}
}

/*
    注册页面：注册成功提示框中的叉按钮事件
*/
static void screen_create_imgbtn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        lv_scr_load(guider_ui.screen_input);
	}
		break;
	default:
		break;
	}
}

/*
    注册页面：注册失败提示框中的叉按钮事件
*/
static void screen_create_imgbtn_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.screen_create_create_account_fail_cont_1, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    注册页面：退出注册页面的叉按钮事件
*/
static void screen_create_imgbtn_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_scr_load(guider_ui.screen_input);
	}
		break;
	default:
		break;
	}
}

/*
    主页面：切换至消息页面的按钮事件
*/
static void screen_message_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        lv_scr_load(guider_ui.screen_message);
	}
		break;
	default:
		break;
	}
}

/*
    主页面：切换至好友页面的按钮事件
*/
static void screen_friend_imgbtn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        lv_scr_load(guider_ui.screen_friend);
	}
		break;
	default:
		break;
	}
}

static void screen_circle_imgbtn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        lv_scr_load(guider_ui.screen_circle);
	}
		break;
	default:
		break;
	}
}

static void screen_owner_imgbtn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        lv_scr_load(guider_ui.screen_owner);
	}
		break;
	default:
		break;
	}
}

/*
    绑定所有事件
*/
void custom_events_init(lv_ui *ui)
{
    //登陆页面事件
	lv_obj_add_event_cb(ui->screen_input_imgbtn_6, screen_input_imgbtn_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_input_imgbtn_7, screen_input_imgbtn_7_event_handler, LV_EVENT_ALL, ui);
    //注册页面事件
    lv_obj_add_event_cb(ui->screen_create_btn_1, screen_create_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_create_imgbtn_8, screen_create_imgbtn_8_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_create_imgbtn_9, screen_create_imgbtn_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_create_imgbtn_13, screen_create_imgbtn_13_event_handler, LV_EVENT_ALL, ui);
    //主页面事件(进入消息页面的按钮事件)
    lv_obj_add_event_cb(ui->screen_message_imgbtn_1, screen_message_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_friend_imgbtn_1,  screen_message_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_circle_imgbtn_1,  screen_message_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_owner_imgbtn_1,   screen_message_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
	//进入好友页面的按钮事件
    lv_obj_add_event_cb(ui->screen_message_imgbtn_2, screen_friend_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_friend_imgbtn_2,  screen_friend_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_circle_imgbtn_2,  screen_friend_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_owner_imgbtn_2,   screen_friend_imgbtn_2_event_handler, LV_EVENT_ALL, ui);
	//进入朋友圈页面的按钮事件
    lv_obj_add_event_cb(ui->screen_message_imgbtn_3, screen_circle_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_friend_imgbtn_3,  screen_circle_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_circle_imgbtn_3,  screen_circle_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_owner_imgbtn_3,   screen_circle_imgbtn_3_event_handler, LV_EVENT_ALL, ui);
	//进入“我的”页面的按钮事件
    lv_obj_add_event_cb(ui->screen_message_imgbtn_4, screen_owner_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_friend_imgbtn_4,  screen_owner_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_circle_imgbtn_4,  screen_owner_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_owner_imgbtn_4,   screen_owner_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
	
}
