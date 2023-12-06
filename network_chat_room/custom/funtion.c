#include "function.h"

/*
    功能：检测指定的字符串中是否有除了数字之外的其他字符
    参数：buf--要检测的字符串，len--字符串的长度
    返回值：-1--含有其他字符，0不含除数字外的其他字符
*/
int check_num_char(const char *buf, int len){
    for(int i=0;i<len;i++){
        if(buf[i]<48 || buf[i]>59){
            return -1;
        }
    }
    return 0;
}

void *send_data(void *arg){
    MESSAGE *message = (MESSAGE *)arg;
    int ret = 0;
loop:
    ret = write(message->head.fd, message, sizeof(MESSAGE));
    if(ret < 0){
        perror("write");
        return NULL;
    }
    ret = read(message->head.fd, message, sizeof(MESSAGE));
    if(ret < 0){
        perror("read");
        return NULL;
    }
    if(message->head.flag != WRITE_SUCCESS){
        goto loop;
    }
    printf("write success!\r\n");
    return NULL;
}

int packet_write(int fd,int num, void *buf, int len){
    MESSAGE *message = malloc(sizeof(MESSAGE));
    message->head.fd = fd;
    message->head.num = num;
    message->head.len = len;
    message->head.flag = 0;
    message->data = buf;
    int ret = 0;
    ret = write(fd, &message, sizeof(MESSAGE));
    if(ret < 0){
        perror("write");
        return -1;
    }
    return 0;
}

int packet_read(int fd, MESSAGE *message, int len){
    int ret = 0;
    ret = read(fd, message, len);
    if(ret < 0){
        perror("read");
        return -1;
    }
    return 0;
}

int add_other_message_into_cont(char *news)
{
 
    //Write codes screen_main_cont_5
	ui->screen_main_cont_5 = lv_obj_create(ui->screen_main_show_message_cont_2);
	lv_obj_set_pos(ui->screen_main_cont_5, 5, 5);
	lv_obj_set_size(ui->screen_main_cont_5, 590, 30);
	lv_obj_set_scrollbar_mode(ui->screen_main_cont_5, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_main_cont_5. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_cont_5, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_main_cont_5, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_cont_5, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_main_cont_5, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_main_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_label_2
	ui->screen_main_label_2 = lv_label_create(ui->screen_main_cont_5);
	lv_obj_set_pos(ui->screen_main_label_2, 40, 0);
	lv_obj_set_size(ui->screen_main_label_2, 400, 24);
	lv_obj_set_scrollbar_mode(ui->screen_main_label_2, LV_SCROLLBAR_MODE_ON);
	lv_label_set_text(ui->screen_main_label_2, "hello");
	lv_label_set_long_mode(ui->screen_main_label_2, LV_LABEL_LONG_WRAP);
	//Set style for screen_main_label_2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_label_2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_main_label_2, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_label_2, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_label_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_label_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_label_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_2, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_2, &lv_font_arial_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_img_7
	ui->screen_main_img_7 = lv_img_create(ui->screen_main_cont_5);
	lv_obj_set_pos(ui->screen_main_img_7, 0, 0);
	lv_obj_set_size(ui->screen_main_img_7, 25, 25);
	lv_obj_set_scrollbar_mode(ui->screen_main_img_7, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_main_img_7. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->screen_main_img_7, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->screen_main_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_main_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_main_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_main_img_7,&_4_alpha_25x25);
	lv_img_set_pivot(ui->screen_main_img_7, 50,50);
	lv_img_set_angle(ui->screen_main_img_7, 0);

	//Write codes screen_main_label_23
	ui->screen_main_label_23 = lv_label_create(ui->screen_main_cont_5);
	lv_obj_set_pos(ui->screen_main_label_23, 450, 15);
	lv_obj_set_size(ui->screen_main_label_23, 30, 10);
	lv_obj_set_scrollbar_mode(ui->screen_main_label_23, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_main_label_23, "16:23");
	lv_label_set_long_mode(ui->screen_main_label_23, LV_LABEL_LONG_WRAP);
	//Set style for screen_main_label_23. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_label_23, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_main_label_23, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_label_23, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_label_23, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_label_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_23, lv_color_make(0x3c, 0x3c, 0x3c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_23, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_23, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
}