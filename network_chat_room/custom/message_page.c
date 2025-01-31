#include "message_page.h"

MESSAGE_PAGE message_page_object;  //表示消息页面相关的信息

static void screen_main_send_message_event_handler(lv_event_t *e);

/*
    初始化消息页面相关的信息
*/ 
void message_page_init(void)
{
	message_page_object.message_imagebtn = guider_ui.screen_message_imgbtn_1;
	message_page_object.friend_imagebtn  = guider_ui.screen_message_imgbtn_2;
	message_page_object.circle_imagebtn  = guider_ui.screen_message_imgbtn_3;
	message_page_object.owner_imagebtn   = guider_ui.screen_message_imgbtn_4;

	//初始化列表
	message_page_object.list.list = guider_ui.screen_message_friend_list_1;
	message_page_object.list.list_item[0].item = guider_ui.screen_message_friend_list_1_item0;
	message_page_object.list.cell_count = 1;
	message_page_object.list.now_select_item->item = guider_ui.screen_message_friend_list_1_item0;
	//初始化好友申请回复页面
	message_page_object.reply_page.cont = guider_ui.screen_message_friend_apply_reply_cont;
	message_page_object.reply_page.num = 0;
	//初始化消息页面
	message_page_object.message_page.cont = guider_ui.screen_message_message_info_cont;
	message_page_object.message_page.info.cont = guider_ui.screen_message_show_message_cont_2;
	message_page_object.message_page.info.message_num = 0;
	message_page_object.message_page.send.cont = guider_ui.screen_message_send_message_cont;
	message_page_object.message_page.send.textarea = guider_ui.screen_message_ta_1;
	message_page_object.message_page.send.imgbtn_text = guider_ui.screen_message_imgbtn_5;
	message_page_object.message_page.send.imgbtn_emoji = guider_ui.screen_message_imgbtn_24;
	message_page_object.message_page.send.imgbtn_file = guider_ui.screen_message_imgbtn_26;
	message_page_object.message_page.send.imgbtn_tel = guider_ui.screen_message_imgbtn_25;


	lv_obj_add_event_cb(message_page_object.send_message_btn, screen_main_send_message_event_handler\
	, LV_EVENT_ALL, &guider_ui);
}

/*
    消息页面列表中的item事件
*/
static void screen_main_message_item_event_handler(lv_event_t *e)
{
    char buf1[256] = {0};
    char buf2[256] = {0};
    MESSAGE_TYPE messagetype;//临时变量，用来记录消息类型
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_current_target(e);

	switch (code)
	{
		case LV_EVENT_CLICKED:
		{
			strcpy(buf1, lv_list_get_btn_text(message_page_object.list.list, obj));
			if(strcmp(buf1, "notice") == 0)
			{
				//显示好友申请回复页面
				lv_obj_clear_flag(message_page_object.reply_page.cont, LV_OBJ_FLAG_HIDDEN);
				lv_obj_add_flag(message_page_object.message_page.cont, LV_OBJ_FLAG_HIDDEN);
			}
			else
			{
				//切换被点击按钮的颜色，以代表其被选中
				for(int i=0; i<message_page_object.cell_count; i++){
					lv_obj_clear_state((message_page_object.list_item)[i].item, LV_STATE_FOCUSED);
					strcpy(buf2, lv_list_get_btn_text(message_page_object.sender_list, (message_page_object.list_item)[i].item));
					if(strcmp(buf1, buf2) == 0){
						message_page_object.now_select_item = &((message_page_object.list_item)[i]);
					}
				}
				lv_obj_add_state(obj, LV_STATE_FOCUSED);
				message_page_object.message_count = 0;
				//清理原本消息对话框及消息输入框中的内容
				lv_obj_clean(message_page_object.message_cont);
				lv_textarea_set_text(message_page_object.send_message_ta, "");
				//获取被选中按钮的相关信息
				message_cont_fill_friend(buf1);
			}
		}
			break;
		default:
			break;
	}
}

/*
    消息页面对话框中的发送按钮事件
*/
static void screen_main_send_message_event_handler(lv_event_t *e)
{
    char buf1[256] = {0};
	lv_event_code_t code = lv_event_get_code(e);
	client_data senddata = {0};
	MESSAGE_PACKET messagedata = {0};
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		int ret = 0;
		strcpy(buf1, lv_textarea_get_text(message_page_object.send_message_ta));
		senddata.num = MESSAGE_CLI_TO_SER;
		messagedata.data_type = STRING_DATA;
		strcpy(messagedata.message, buf1);
		messagedata.datalen = strlen(buf1);

		// ret = write(socketfd, &senddata, sizeof(senddata));
		// if(ret < 0){
		// 	perror("write");
		// 	printf("发送消息失败!\r\n");
		// 	break;
		// }

		FRIEND_INFO *info = (FRIEND_INFO *)((message_page_object.now_select_item)->info);
		strcpy(messagedata.id, info->id);
		ret = write(socketfd, &messagedata, sizeof(MESSAGE_PACKET));
		if(ret < 0){
			perror("write");
			printf("发送消息失败!\r\n");
			break;
		}
		//向对话框中添加自己发送的消息
		add_friend_message_into_cont(buf1, &(message_page_object.message_cell[message_page_object.message_count]), MYSELF_MESSAGE);
	}
		break;
	default:
		break;
	}
}

/*
    填充消息对话框(好友消息)
*/
int message_cont_fill_friend(char *name){
    FRIEND_NODE *temnode = NULL;
    temnode = head_friend_node;
    //遍历好友列表找到对应的好友
    while(temnode){
        if((strcmp(name, temnode->info.name) == 0) || (strcmp(name, temnode->info.remark) == 0)){
			break;
        }
		temnode = temnode->next;
    }
	if(temnode == NULL){
		return -1;
	};
	//添加消息
	int i = 0;
	while((temnode->info.news[i][0]) != '\0') {
		printf("news:%s\r\n", temnode->info.news[i]);
		add_friend_message_into_cont(temnode->info.news[i], &(message_page_object.message_cell[i]), FRIEND_MESSAGE);
		i++;
	}
	temnode = NULL;
	return 0;
}

/*
    初始化消息页面
*/
void message_page_config(void){
    char buf[256] = {0};
    FRIEND_NODE *temnode = NULL;
    //遍历好友信息链表,如果有好友发送消息，则将发送人添加至消息页面
    temnode = head_friend_node;
    while(temnode->next){
        temnode = temnode->next;
        if(temnode->info.news[0] != NULL){
            //如果有备注则显示备注，没有备注则显示昵称
            if(temnode->info.remark != NULL){
                sprintf(buf, "%s", temnode->info.remark); 
            }
            else{
                sprintf(buf, "%s", temnode->info.name);
            }
            (message_page_object.list_item)[message_page_object.cell_count].item = lv_list_add_btn(message_page_object.sender_list, &_4_2_alpha_25x25, buf);
			(message_page_object.list_item)[message_page_object.cell_count].info = (void *)(&(temnode->info));
            //绑定对应的点击事件
            lv_obj_add_event_cb((message_page_object.list_item)[message_page_object.cell_count].item, screen_main_message_item_event_handler, LV_EVENT_CLICKED, &guider_ui);
            message_page_object.cell_count++;
        }
    }
}

/*
	向消息对话框中添加好友消息
*/
int add_friend_message_into_cont(char *news, MESSAGE_CONT_CELL *obj, MESSAGE_TYPE type)
{
    int cont_x, cont_y, label_x, label_y, time_x, time_y, image_x, image_y;
    cont_x = 5;
    cont_y = 5 + message_page_object.message_count*35;
    if(type == FRIEND_MESSAGE){
        label_x = 40;
        label_y = 0;

        time_x = 450;
        time_y = 0;

        image_x = 0;
        image_y = 0;
    }
    else if(type == MYSELF_MESSAGE){
        label_x = 150;
        label_y = 0;

        time_x = 120;
        time_y = 15;

        image_x = 560;
        image_y = 0;
    }

    //消息容器
	obj->cell_cont = lv_obj_create(message_page_object.message_cont);
	lv_obj_set_pos(obj->cell_cont, cont_x, cont_y);
	lv_obj_set_size(obj->cell_cont, 590, 30);
	lv_obj_set_scrollbar_mode(obj->cell_cont, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_main_cont_5. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(obj->cell_cont, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(obj->cell_cont, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(obj->cell_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(obj->cell_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(obj->cell_cont, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(obj->cell_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(obj->cell_cont, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(obj->cell_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(obj->cell_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//消息内容
	obj->cell_message_label = lv_label_create(obj->cell_cont);
	lv_obj_set_pos(obj->cell_message_label, label_x, label_y);
	lv_obj_set_size(obj->cell_message_label, 400, 24);
	lv_obj_set_scrollbar_mode(obj->cell_message_label, LV_SCROLLBAR_MODE_ON);
	lv_label_set_text(obj->cell_message_label, news);
	lv_label_set_long_mode(obj->cell_message_label, LV_LABEL_LONG_WRAP);
	//Set style for screen_main_label_2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(obj->cell_message_label, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(obj->cell_message_label, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(obj->cell_message_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(obj->cell_message_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(obj->cell_message_label, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(obj->cell_message_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(obj->cell_message_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(obj->cell_message_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(obj->cell_message_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(obj->cell_message_label, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(obj->cell_message_label, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(obj->cell_message_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(obj->cell_message_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//发送者的头像
	obj->cell_head_image = lv_img_create(obj->cell_cont);
	lv_obj_set_pos(obj->cell_head_image, image_x, image_y);
	lv_obj_set_size(obj->cell_head_image, 25, 25);
	lv_obj_set_scrollbar_mode(obj->cell_head_image, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_main_img_7. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(obj->cell_head_image, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(obj->cell_head_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(obj->cell_head_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(obj->cell_head_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(obj->cell_head_image,&_4_2_alpha_25x25);
	lv_img_set_pivot(obj->cell_head_image, 50,50);
	lv_img_set_angle(obj->cell_head_image, 0);

	//发送时间
	obj->cell_time_label = lv_label_create(obj->cell_cont);
	lv_obj_set_pos(obj->cell_time_label, time_x, time_y);
	lv_obj_set_size(obj->cell_time_label, 30, 10);
	lv_obj_set_scrollbar_mode(obj->cell_time_label, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(obj->cell_time_label, "16:23");
	lv_label_set_long_mode(obj->cell_time_label, LV_LABEL_LONG_WRAP);
	//Set style for screen_main_label_23. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(obj->cell_time_label, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(obj->cell_time_label, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(obj->cell_time_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(obj->cell_time_label, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(obj->cell_time_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(obj->cell_time_label, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(obj->cell_time_label, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(obj->cell_time_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(obj->cell_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	message_page_object.message_count++;

	return 0;
}

/*
	向好友申请列表添加一个元素
*/
static void add_one_cell_to_apply_reply_page(FRIEND_REPLY_CELL *cell, char * buf)
{
	cell->cont = lv_obj_create(guider.screen_message_friend_apply_reply_cont);
	lv_obj_set_pos(cell->cont, 0, 5);
	lv_obj_set_size(cell->cont, 590, 50);
	lv_obj_set_scrollbar_mode(cell->cont, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_message_cont_13. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(cell->cont, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(cell->cont, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(cell->cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(cell->cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(cell->cont, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(cell->cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(cell->cont, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(cell->cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(cell->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	// //Write codes screen_message_line_4
	// ui->screen_message_line_4 = lv_line_create(cell->cont);
	// lv_obj_set_pos(ui->screen_message_line_4, 5, 1);
	// lv_obj_set_size(ui->screen_message_line_4, 580, 10);
	// lv_obj_set_scrollbar_mode(ui->screen_message_line_4, LV_SCROLLBAR_MODE_OFF);

	// //Set style for screen_message_line_4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	// lv_obj_set_style_line_color(ui->screen_message_line_4, lv_color_make(0x75, 0x75, 0x75), LV_PART_MAIN|LV_STATE_DEFAULT);
	// lv_obj_set_style_line_width(ui->screen_message_line_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	// lv_obj_set_style_line_rounded(ui->screen_message_line_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	// static lv_point_t screen_message_line_4[] ={{0, 0},{590, 0},};
	// lv_line_set_points(ui->screen_message_line_4,screen_message_line_4,2);

	//Write codes screen_message_line_3
	cell->buttom_line = lv_line_create(cell->cont);
	lv_obj_set_pos(cell->buttom_line, 5, 49);
	lv_obj_set_size(cell->buttom_line, 580, 1);
	lv_obj_set_scrollbar_mode(cell->buttom_line, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_message_line_3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_line_color(cell->buttom_line, lv_color_make(0x75, 0x75, 0x75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(cell->buttom_line, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(cell->buttom_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t screen_message_line_3[] ={{0, 0},{590, 0},};
	lv_line_set_points(cell->buttom_line,screen_message_line_3,2);

	//Write codes screen_message_btn_18
	cell->btn = lv_btn_create(cell->cont);
	lv_obj_set_pos(cell->btn, 1, 1);
	lv_obj_set_size(cell->btn, 450, 45);
	lv_obj_set_scrollbar_mode(cell->btn, LV_SCROLLBAR_MODE_OFF);

	//Set style for screen_message_btn_18. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(cell->btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(cell->btn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(cell->btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(cell->btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(cell->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(cell->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(cell->btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(cell->btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(cell->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(cell->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(cell->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(cell->btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(cell->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(cell->btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(cell->btn, lv_color_make(0x1c, 0x19, 0x19), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(cell->btn, &lv_font_arial_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(cell->btn, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	cell->btn_label = lv_label_create(cell->btn);
	lv_label_set_text(cell->btn_label, buf);
	lv_obj_set_style_pad_all(cell->btn, 0, LV_STATE_DEFAULT);
	lv_obj_align(cell->btn_label, LV_ALIGN_LEFT_MID, 0, 0);

	lv_obj_add_flag(cell->cont, LV_OBJ_FLAG_HIDDEN);
	message_page_object.reply_page.num++;
}

/*
	向好友申请回复列表中添加一条消息，并按照时间先后顺序进行排序
*/
void add_one_to_apply_reply_page(FRIEND_REPLY_CELL *cell, char * info)
{
	//解析字符串中的数据
	char name[32] = {0};
	char id[32] = {0};
	char time[32] = {0};
	char buf[256] = {0};
	int i, flag, flag1;
	while(info[i] != 0)
	{
		int j = 0;
		if(info[i-1] == '<')
		{
			j = 0;
			while(info[i+j] != '>')
			{
				if(flag == 0)
				{
					name[j] = info[i+j];
				}
				else if(flag == 1)
				{
					id[j] = info[i+j];
				}
				else if(flag == 2)
				{
					flag1 = info[i+j];
				}
				else
				{
					time[j] = info[i+j];
				}
				j++;
			}
			flag++;
		}
		i++;
	}
	if(flag1 == '0')
	{
		sprintf(buf, "    %s(%s) agreed to your friend request!		%s", name, id, time);
	}
	else
	{
		sprintf(buf, "    %s(%s) refuse to your friend request!		%s", name, id, time);
	}
	//向好友回复列表中添加元素
	add_one_cell_to_apply_reply_page(message_page_object.reply_page.cell[message_page_object.reply_page.num], buf);
	//计算并设置每个元素的位置
	for(i = 0; i < message_page_object.reply_page.num; i++)
	{
		int location = ((message_page_object.reply_page.num -1) - i) * 50 + 5;
		lv_obj_set_pos(message_page_object.reply_page.cell[i].cont, location);
		lv_obj_clear_flag(message_page_object.reply_page.cell[i].cont, LV_OBJ_FLAG_HIDDEN);
	}
}