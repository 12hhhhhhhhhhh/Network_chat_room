#include "custom_event.h"

/*
    登陆按钮事件
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
		strcpy(input_date.id, lv_textarea_get_text(guider_ui.screen_input_ta_2));
        strcpy(input_date.passwd, lv_textarea_get_text(guider_ui.screen_input_ta_3));
        input_date.num = INPUT_ACCOUNT;
        input_date.fd = socketfd;
        // write(socketfd, &input_date, sizeof(input_date));
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
	lv_obj_add_event_cb(ui->screen_input_imgbtn_6, screen_input_imgbtn_6_event_handler, LV_EVENT_ALL, ui);
}
