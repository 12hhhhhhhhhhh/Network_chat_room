#include "contacts_page.h"

static void screen_main_contacts_friend_item_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_modify_remark_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_modify_remark_yes_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_modify_remark_no_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_delete_friend_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_delete_friend_no_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_delete_friend_yes_event_handler(lv_event_t *e);
static void screen_main_contacts_search_imagebtn_event_handler(lv_event_t *e);
static void screen_main_contacts_search_res_btn_event_handler(lv_event_t *e);
static void screen_main_contacts_search_info_addbtn_event_handler(lv_event_t *e);
static void screen_main_contacts_add_res_btn_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_look_apply_detail_info_handler(lv_event_t *e);
static void screen_main_contacts_quit_apply_detail_info_event_handler(lv_event_t *e);
static void screen_main_contacts_agree_apply_friend_event_handler(lv_event_t *e);
static void screen_main_contacts_refuse_apply_friend_event_handler(lv_event_t *e);

CONTACTS_PAGE contacts_page;

/*
    初始化联系人(好友)页面的相关信息
*/
void contacts_page_init(void){
    contacts_page.friend_cont      = guider_ui.screen_friend_friend_infor_cont_1;
    contacts_page.search_ta        = guider_ui.screen_friend_ta_9;
    contacts_page.search_imagebtn  = guider_ui.screen_friend_imgbtn_14;
    contacts_page.message_imagebtn = guider_ui.screen_friend_imgbtn_1;
    contacts_page.friend_imagebtn  = guider_ui.screen_friend_imgbtn_2;
    contacts_page.circle_imagebtn  = guider_ui.screen_friend_imgbtn_3;
    contacts_page.owner_imagebtn   = guider_ui.screen_friend_imgbtn_4;
    //初始化好友页面
    contacts_page.friend_info.delete_btn = guider_ui.screen_friend_imgbtn_12;
    contacts_page.friend_info.flag_spangroup = guider_ui.screen_friend_spangroup_2;
    contacts_page.friend_info.head_image = guider_ui.screen_friend_img_6;
    contacts_page.friend_info.id_label = guider_ui.screen_friend_label_20;
    contacts_page.friend_info.list = guider_ui.screen_friend_friend_list;
    contacts_page.friend_info.message_btn = guider_ui.screen_friend_imgbtn_2;
    contacts_page.friend_info.modify_btn = guider_ui.screen_friend_imgbtn_12;
    contacts_page.friend_info.name_label = guider_ui.screen_friend_label_18;
    contacts_page.friend_info.remark_label = guider_ui.screen_friend_label_21;
    contacts_page.friend_info.telphone_btn = guider_ui.screen_friend_imgbtn_3;
    //删除好友弹窗
    contacts_page.friend_info.delete_cont.cont = guider_ui.screen_friend_delete_friend_cont_5;
    contacts_page.friend_info.delete_cont.yes_btn = guider_ui.screen_friend_btn_4;
    contacts_page.friend_info.delete_cont.no_btn = guider_ui.screen_friend_btn_5;
    //修改好友备注弹窗
    contacts_page.friend_info.modify_cont.cont = guider_ui.screen_friend_edit_remark_cont_5;
    contacts_page.friend_info.modify_cont.remark_textarea = guider_ui.screen_friend_ta_8;
    contacts_page.friend_info.modify_cont.yes_btn = guider_ui.screen_friend_btn_7;
    contacts_page.friend_info.modify_cont.no_btn = guider_ui.screen_friend_btn_6;
    //搜索信息框
    contacts_page.search_cont = guider_ui.screen_friend_search_info_cont;
    contacts_page.search_info.head_image = guider_ui.screen_friend_img_12;
    contacts_page.search_info.name_label = guider_ui.screen_friend_label_35;
    contacts_page.search_info.id_label = guider_ui.screen_friend_label_34;
    contacts_page.search_info.flag_spangroup = guider_ui.screen_friend_spangroup_9;
    contacts_page.search_info.add_btn = guider_ui.screen_friend_btn_12;
    contacts_page.search_info.send_add_res.cont = guider_ui.screen_friend_cont_10;
    contacts_page.search_info.send_add_res.label = guider_ui.screen_friend_label_37;
    contacts_page.search_info.send_add_res.btn = guider_ui.screen_friend_btn_15;
    //搜索结果弹窗
    contacts_page.search_res_cont.cont = guider_ui.screen_friend_search_result_cont;
    contacts_page.search_res_cont.label = guider_ui.screen_friend_label_36;
    contacts_page.search_res_cont.btn = guider_ui.screen_friend_btn_14;
    //好友信息列表页面
    contacts_page.friend_apply_cont.apply_num = 0;
    contacts_page.friend_apply_cont.cont = guider_ui.screen_friend_friend_apply_cont;
    contacts_page.friend_apply_cont.apply_infor.cont = guider_ui.screen_friend_applicant_info_cont;
    contacts_page.friend_apply_cont.apply_infor.head_image = guider_ui.screen_friend_img_13;
    contacts_page.friend_apply_cont.apply_infor.name_label = guider_ui.screen_friend_label_38;
    contacts_page.friend_apply_cont.apply_infor.id_label = guider_ui.screen_friend_label_39;
    contacts_page.friend_apply_cont.apply_infor.flag_label = guider_ui.screen_friend_label_40;
    contacts_page.friend_apply_cont.apply_infor.agree_imagebtn = guider_ui.screen_friend_imgbtn_21;
    contacts_page.friend_apply_cont.apply_infor.refuse_imagebtn = guider_ui.screen_friend_imgbtn_22;
    contacts_page.friend_apply_cont.apply_infor.quit_imagebtn = guider_ui.screen_friend_imgbtn_23;

    lv_obj_add_event_cb(contacts_page.friend_info.modify_btn, screen_main_contacts_friend_modify_remark_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.friend_info.modify_cont.yes_btn, screen_main_contacts_friend_modify_remark_yes_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.friend_info.modify_cont.no_btn, screen_main_contacts_friend_modify_remark_no_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.friend_info.delete_btn, screen_main_contacts_friend_delete_friend_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.friend_info.delete_cont.yes_btn, screen_main_contacts_friend_delete_friend_yes_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.friend_info.delete_cont.no_btn, screen_main_contacts_friend_delete_friend_no_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.search_imagebtn, screen_main_contacts_search_imagebtn_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.search_res_cont.btn, screen_main_contacts_search_res_btn_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.search_info.add_btn, screen_main_contacts_search_info_addbtn_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.search_info.send_add_res.btn, screen_main_contacts_add_res_btn_event_handler\
	, LV_EVENT_ALL, &guider_ui);
    lv_obj_add_event_cb(contacts_page.friend_apply_cont.apply_infor.quit_imagebtn, screen_main_contacts_quit_apply_detail_info_event_handler\
	, LV_EVENT_ALL, &guider_ui);
}

/*
    登录成功后对联系人页面进行初始化
*/
void contacts_page_config(void){
    FRIEND_NODE *temnode = NULL;
    int i = 0;
    //初始化好友列表
    temnode = head_friend_node;
    while(temnode->next != NULL){
        temnode = temnode->next;
        strcpy(contacts_page.friend_info.friend_item[i].name, temnode->info.name);
        //在列表中创建相应的item并绑定对应的样式和事件
        contacts_page.friend_info.friend_item[i].item = lv_list_add_btn(contacts_page.friend_info.list, &_4_2_alpha_20x20, temnode->info.name);

        // lv_obj_add_style(contacts_page.friend_info.friend_item[i].item, &(guider_ui.style_screen_main_friend_list_1_extra_btns_main_default), LV_PART_MAIN|LV_STATE_DEFAULT);
	    // lv_obj_add_style(contacts_page.friend_info.friend_item[i].item, &(guider_ui.style_screen_main_friend_list_1_extra_btns_main_focused), LV_PART_MAIN|LV_STATE_FOCUSED);

        lv_obj_add_event_cb(contacts_page.friend_info.friend_item[i].item, screen_main_contacts_friend_item_event_handler, LV_EVENT_CLICKED, &guider_ui);
        contacts_page.friend_info.friend_count++;
        i++;
    }
    temnode = NULL;
}


/*
    联系人页面搜索信息框中的添加好友按钮事件
*/
static void screen_main_contacts_search_info_addbtn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    client_data send_data = {0};
    int ret = 0;
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            strcpy(send_data.id, lv_label_get_text(contacts_page.search_info.id_label));
            strcpy(send_data.name, owner_info.id);    //暂时使用结构体中的name变量来存储申请者的ID
            send_data.num = CONTACTS_SEARCH_ADD_FRIEND;
            ret = write(socketfd, &send_data, sizeof(send_data));
            if(ret < 0) {
                printf("write:添加好友失败\r\n");
                break;
            }
            ret = read(socketfd, &send_data, sizeof(send_data));
            if(ret < 0) {
                printf("read:添加好友失败\r\n");
                break;
            }
            if(send_data.num == CONTACTS_SEARCH_ADD_FRIEND_SUCCESS) {
                lv_label_set_text(contacts_page.search_info.send_add_res.label, "The friend request was successfully sent!");
            }
            else if(send_data.num == CONTACTS_SEARCH_ADD_FRIEND_FAIL){
                lv_label_set_text(contacts_page.search_info.send_add_res.label, "Failed to send a friend request!");
            }
            else if(send_data.num == CONTACTS_SEARCH_ADD_FRIEND_ALREADY){
                lv_label_set_text(contacts_page.search_info.send_add_res.label, "You've already sent the friend request!");
            }
            else if(send_data.num == CONTACTS_SEARCH_ADD_FRIEND_FULL){
                lv_label_set_text(contacts_page.search_info.send_add_res.label, "The other friend has applied too much, please try again later!");
            }
            //显示发送好友申请结果的弹窗
            lv_obj_set_pos(contacts_page.search_info.send_add_res.cont, 230, 100);
            lv_obj_clear_flag(contacts_page.search_info.send_add_res.cont, LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

/*
    联系人页面好友申请结果弹窗中的确认按钮事件
*/
static void screen_main_contacts_add_res_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(contacts_page.search_info.send_add_res.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面搜索按钮事件
*/
static void screen_main_contacts_search_imagebtn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    client_data send_data = {0};
    char buf[64] = {0};
    int ret = 0; 
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            //获取备注并写在修改备注的输入框中
            strcpy(buf, lv_textarea_get_text(contacts_page.search_ta));
            if((strlen(buf) != 6) || (judge_id_format(buf) < 0)) {
                break;
            }
            send_data.num = CONTACTS_SEARCH_BY_ID;
            strcpy(send_data.id, buf);
            ret = write(socketfd, &send_data, sizeof(send_data));
            if(ret < 0) {
                printf("write:搜索好友失败\r\n");
                break;
            }
            ret = read(socketfd, &send_data, sizeof(send_data));
            if(ret < 0) {
                printf("read:搜索好友失败\r\n");
                break;
            }

            if (send_data.num == CONTACTS_SEARCH_SUCCESS) {
                lv_label_set_text(contacts_page.search_info.name_label, send_data.name);
                lv_label_set_text(contacts_page.search_info.id_label, send_data.id);
                lv_span_t * span_obj = lv_spangroup_get_child(contacts_page.search_info.flag_spangroup, 0);
                lv_span_set_text(span_obj, send_data.flag);//个性签名
                //显示搜索信息页面
                lv_obj_set_pos(contacts_page.search_cont, 205, 0);
                lv_obj_clear_flag(contacts_page.search_cont, LV_OBJ_FLAG_HIDDEN);
                break;
            }
            else if(send_data.num == CONTACTS_SEARCH_NO_FIND) {
                lv_label_set_text(contacts_page.search_res_cont.label, "no find the contacts!");
            }
            else {
                lv_label_set_text(contacts_page.search_res_cont.label, "fail:reason uknown!");
            }
            //显示搜索结果弹窗
            lv_obj_set_pos(contacts_page.search_res_cont.cont, 320, 100);
            lv_obj_clear_flag(contacts_page.search_res_cont.cont, LV_OBJ_FLAG_HIDDEN);
            
        }
            break;
        default:
            break;
	}
}

/*
    联系人页面搜索弹窗确认按钮事件
*/
static void screen_main_contacts_search_res_btn_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(contacts_page.search_res_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友列表中的item事件
*/
static void screen_main_contacts_friend_item_event_handler(lv_event_t *e)
{
    char buf1[256] = {0};
    char buf2[256] = {0};
    FRIEND_INFO * tem_friend_info =  NULL;//临时变量，用来记录好友信息
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_current_target(e);

	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        strcpy(buf1, lv_list_get_btn_text(contacts_page.friend_info.list, obj));
        //切换被点击按钮的颜色，以代表其被选中
        for(int i=0; i<contacts_page.friend_info.friend_count; i++){
            lv_obj_clear_state((contacts_page.friend_info.friend_item)[i].item, LV_STATE_FOCUSED);
        }
        lv_obj_add_state(obj, LV_STATE_FOCUSED);
		//清理原本好友相关信息容器中的内容
		lv_obj_clean(contacts_page.friend_cont);
        //查找相关的好友信息
        tem_friend_info = find_friend_info_by_name(buf1);
        if(tem_friend_info ==  NULL){
            printf("查无此人!\r\n");
            break;
        }
        //显示所有对象
        lv_obj_clear_flag(contacts_page.friend_info.delete_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.modify_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.flag_spangroup, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.head_image, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.id_label, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.name_label, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.remark_label, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.telphone_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(contacts_page.friend_info.message_btn, LV_OBJ_FLAG_HIDDEN);
        //显示对应得到信息
        lv_img_set_src(contacts_page.friend_info.head_image, &_4_2_alpha_80x80);              //头像
        lv_label_set_text(contacts_page.friend_info.name_label, tem_friend_info->name);     //昵称
        lv_label_set_text(contacts_page.friend_info.remark_label, tem_friend_info->remark); //备注
        lv_label_set_text(contacts_page.friend_info.id_label, tem_friend_info->id);         //账号
        lv_span_t * span_obj = lv_spangroup_get_child(contacts_page.friend_info.flag_spangroup, 0);
        lv_span_set_text(span_obj, tem_friend_info->flag);                                  //个性签名
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友信息容器中的修改备注按钮事件
*/
static void screen_main_contacts_friend_modify_remark_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        //获取备注并写在修改备注的输入框中
        lv_textarea_set_text(contacts_page.friend_info.modify_cont.remark_textarea, lv_label_get_text(contacts_page.friend_info.remark_label));
        //显示修改备注的弹窗
        lv_obj_set_pos(contacts_page.friend_info.modify_cont.cont, 230, 100);
		lv_obj_clear_flag(contacts_page.friend_info.modify_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友信息容器中的修改备注确定按钮事件
*/
static void screen_main_contacts_friend_modify_remark_yes_event_handler(lv_event_t *e)
{
    char buf[256] = {0};
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        strcmp(buf, lv_textarea_get_text(contacts_page.friend_info.modify_cont.remark_textarea));
        lv_label_set_text(contacts_page.friend_info.remark_label, buf);
        modify_remark_by_id(lv_label_get_text(contacts_page.friend_info.id_label), buf);
        //隐藏弹窗
		lv_obj_add_flag(contacts_page.friend_info.modify_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友信息容器中的修改备注取消按钮事件
*/
static void screen_main_contacts_friend_modify_remark_no_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        //隐藏弹窗
		lv_obj_add_flag(contacts_page.friend_info.modify_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友信息容器中的删除好友按钮事件
*/
static void screen_main_contacts_friend_delete_friend_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        lv_obj_set_pos(contacts_page.friend_info.delete_cont.cont, 230, 100);
		lv_obj_clear_flag(contacts_page.friend_info.delete_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友信息容器中的删除好友容器中的取消按钮事件
*/
static void screen_main_contacts_friend_delete_friend_no_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(contacts_page.friend_info.delete_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友信息容器中的删除好友容器中的确定按钮事件
*/
static void screen_main_contacts_friend_delete_friend_yes_event_handler(lv_event_t *e)
{
    int ret = 0;
    client_data data = {0};
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        //发送消息给服务器
        data.num = DELETE_FRIEND;
        strcpy(data.id, lv_label_get_text(contacts_page.friend_info.id_label));
        strcpy(data.name, lv_label_get_text(contacts_page.friend_info.name_label));
        ret = write(socketfd, &data, sizeof(data));
        if(ret < 0){
            perror("write");
            break;
        }
        ret = read(socketfd, &data, sizeof(data));
        if(ret < 0) {
            perror("read");
            break;
        }
        if(data.num == DELETE_FRIEND_SUCCESS){
            //删除链表中对应的节点
            del_friend_info_node(lv_label_get_text(contacts_page.friend_info.id_label));
            //寻找并删除列表中对应的item
            // lv_obj_del
            for(int i = 0;i < contacts_page.friend_info.friend_count;i++){
                lv_obj_t *tem_obj;
                tem_obj = lv_obj_get_child(contacts_page.friend_info.list, i);
                if(strcmp(lv_list_get_btn_text(contacts_page.friend_info.list, tem_obj), data.name) == 0 || \
                strcmp(lv_list_get_btn_text(contacts_page.friend_info.list, tem_obj), lv_label_get_text(contacts_page.friend_info.remark_label)) == 0) {
                    lv_obj_del(tem_obj);
                    break;
                }
            }
            //对整个好友信息容器进行清空(这里将所有的对应隐藏，代替清空效果)
            lv_obj_add_flag(contacts_page.friend_info.delete_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.modify_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.flag_spangroup, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.head_image, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.id_label, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.name_label, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.remark_label, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.telphone_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(contacts_page.friend_info.message_btn, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            printf("删除好友失败!\r\n");
        }
        //隐藏弹窗
		lv_obj_add_flag(contacts_page.friend_info.delete_cont.cont, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

/*
    联系人页面好友申请信息页面中查看详细申请信息的按钮事件
*/
static void screen_main_contacts_friend_look_apply_detail_info_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            char buf[512] = {0};
            char id[32] = {0};
            strcpy(id, (char *)lv_event_get_user_data(e));
            FRIEND_INFO *friend_info = find_friend_info_by_id(id);
            if(friend_info == NULL) {
                ERROR("find_friend_info_by_id");
                break;
            }
            lv_label_set_text(contacts_page.friend_apply_cont.apply_infor.name_label, friend_info->name);
            lv_label_set_text(contacts_page.friend_apply_cont.apply_infor.id_label, friend_info->id);
            lv_label_set_text(contacts_page.friend_apply_cont.apply_infor.flag_label, friend_info->flag);

            lv_obj_clear_flag(contacts_page.friend_apply_cont.apply_infor.cont, LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

/*
    联系人页面好友申请信息页面退出详细信息页面的按钮
*/
static void screen_main_contacts_quit_apply_detail_info_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            lv_obj_add_flag(contacts_page.friend_apply_cont.apply_infor.cont, LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

/*
    联系人页面好友申请信息页面同意好友申请按钮
*/
static void screen_main_contacts_agree_apply_friend_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            client_data data = {0};
            data.num = CONTACTS_AGREE_FRIEND_APPLY;
            strcpy(data.id, owner_info.id);
            lv_obj_t * child_obj = lv_event_get_target(e);
            lv_obj_t * parent_obj = lv_obj_get_parent(child_obj);
            int i = 0;
            while(contacts_page.friend_apply_cont.friend_apply[i].cont != NULL) {
                if(contacts_page.friend_apply_cont.friend_apply[i].cont == parent_obj) {
                    strcpy(data.name, contacts_page.friend_apply_cont.friend_apply[i].id);
                    break;
                }
                i++;
            }
            if(i == contacts_page.friend_apply_cont.apply_num) {
                if(parent_obj == contacts_page.friend_apply_cont.apply_infor.cont) {
                    strcpy(data.name, lv_label_get_text(contacts_page.friend_apply_cont.apply_infor.id_label));
                }
            }
            int ret = write(socketfd, &data, sizeof(client_data));
            if(ret < 0) {
                ERROR("write!\r\n");
            }
            lv_obj_add_flag(contacts_page.friend_apply_cont.apply_infor.cont, LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

/*
    联系人页面好友申请信息页面拒绝好友申请按钮
*/
static void screen_main_contacts_refuse_apply_friend_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            client_data data = {0};
            data.num = CONTACTS_REFUSE_FRIEND_APPLY;
            strcpy(data.id, owner_info.id);
            lv_obj_t * child_obj = lv_event_get_target(e);
            lv_obj_t * parent_obj = lv_obj_get_parent(child_obj);
            int i = 0;
            while(contacts_page.friend_apply_cont.friend_apply[i].cont != NULL) {
                if(contacts_page.friend_apply_cont.friend_apply[i].cont == parent_obj) {
                    strcpy(data.name, contacts_page.friend_apply_cont.friend_apply[i].id);
                    break;
                }
                i++;
            }
            if(i == contacts_page.friend_apply_cont.apply_num) {
                if(parent_obj == contacts_page.friend_apply_cont.apply_infor.cont) {
                    strcpy(data.name, lv_label_get_text(contacts_page.friend_apply_cont.apply_infor.id_label));
                }
            }
            int ret = write(socketfd, &data, sizeof(client_data));
            if(ret < 0) {
                ERROR("write!\r\n");
            }
            lv_obj_add_flag(contacts_page.friend_apply_cont.apply_infor.cont, LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

/*
    向好友申请信息页面添加一条好友申请信息
*/
void add_one_to_list(ONE_FEREND_APPLY *apply, USER_INFO *data) 
{
    //计算该条信息应在的位置
    int y = contacts_page.friend_apply_cont.apply_num *50+5;
    char apply_buf[512] = {0};
    sprintf(apply_buf, "%s(%s)apply!", data->name, data->id);
    
    //Write codes screen_friend_apply_list1
	apply->cont = lv_obj_create(contacts_page.friend_apply_cont.cont);
	lv_obj_set_pos(apply->cont, 0, y);
	lv_obj_set_size(apply->cont, 590, 50);
	lv_obj_set_scrollbar_mode(apply->cont, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_friend_apply_list1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(apply->cont, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(apply->cont, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(apply->cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(apply->cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(apply->cont, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(apply->cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(apply->cont, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(apply->cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(apply->cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_friend_line_1
	apply->top_line = lv_line_create(apply->cont);
	lv_obj_set_pos(apply->top_line, 5, 1);
	lv_obj_set_size(apply->top_line, 580, 10);
	lv_obj_set_scrollbar_mode(apply->top_line, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_friend_line_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_line_color(apply->top_line, lv_color_make(0x75, 0x75, 0x75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(apply->top_line, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(apply->top_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t screen_friend_line_1[] ={{0, 0},{590, 0},};
	lv_line_set_points(apply->top_line,screen_friend_line_1,2);

	//Write codes screen_friend_line_2
	apply->buttom_line = lv_line_create(apply->cont);
	lv_obj_set_pos(apply->buttom_line, 5, 49);
	lv_obj_set_size(apply->buttom_line, 580, 1);
	lv_obj_set_scrollbar_mode(apply->buttom_line, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_friend_line_2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_line_color(apply->buttom_line, lv_color_make(0x75, 0x75, 0x75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_width(apply->buttom_line, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(apply->buttom_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t screen_friend_line_2[] ={{0, 0},{590, 0},};
	lv_line_set_points(apply->buttom_line,screen_friend_line_2,2);

	//Write codes screen_friend_imgbtn_19
	apply->agree_imagebtn = lv_imgbtn_create(apply->cont);
	lv_obj_set_pos(apply->agree_imagebtn, 470, 10);
	lv_obj_set_size(apply->agree_imagebtn, 30, 30);
	lv_obj_set_scrollbar_mode(apply->agree_imagebtn, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_friend_imgbtn_19. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(apply->agree_imagebtn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(apply->agree_imagebtn, lv_color_make(0x75, 0x75, 0x75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(apply->agree_imagebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(apply->agree_imagebtn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(apply->agree_imagebtn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(apply->agree_imagebtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(apply->agree_imagebtn, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(apply->agree_imagebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Set style for screen_friend_imgbtn_19. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(apply->agree_imagebtn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(apply->agree_imagebtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(apply->agree_imagebtn, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(apply->agree_imagebtn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(apply->agree_imagebtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	//Set style for screen_friend_imgbtn_19. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(apply->agree_imagebtn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(apply->agree_imagebtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(apply->agree_imagebtn, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(apply->agree_imagebtn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(apply->agree_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(apply->agree_imagebtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(apply->agree_imagebtn, LV_IMGBTN_STATE_RELEASED, NULL, &_26_1_alpha_30x30, NULL);
	lv_imgbtn_set_src(apply->agree_imagebtn, LV_IMGBTN_STATE_PRESSED, NULL, &_26_2_alpha_30x30, NULL);
	lv_imgbtn_set_src(apply->agree_imagebtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_26_1_alpha_30x30, NULL);
	lv_imgbtn_set_src(apply->agree_imagebtn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_26_2_alpha_30x30, NULL);
	lv_obj_add_flag(apply->agree_imagebtn, LV_OBJ_FLAG_CHECKABLE);

	//Write codes screen_friend_btn_16
	apply->btn = lv_btn_create(apply->cont);
	lv_obj_set_pos(apply->btn, 1, 1);
	lv_obj_set_size(apply->btn, 450, 45);
	lv_obj_set_scrollbar_mode(apply->btn, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_friend_btn_16. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(apply->btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(apply->btn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(apply->btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(apply->btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(apply->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(apply->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(apply->btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(apply->btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(apply->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(apply->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(apply->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(apply->btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(apply->btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(apply->btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(apply->btn, lv_color_make(0x1c, 0x19, 0x19), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(apply->btn, &lv_font_arial_19, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(apply->btn, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	apply->btn_label = lv_label_create(apply->btn);
	lv_label_set_text(apply->btn_label, "    boy1(123456) apply!");
	lv_obj_set_style_pad_all(apply->btn, 0, LV_STATE_DEFAULT);
	lv_obj_align(apply->btn_label, LV_ALIGN_LEFT_MID, 0, 0);

	//Write codes screen_friend_imgbtn_20
	apply->refuse_imagebtn = lv_imgbtn_create(apply->cont);
	lv_obj_set_pos(apply->refuse_imagebtn, 520, 10);
	lv_obj_set_size(apply->refuse_imagebtn, 30, 30);
	lv_obj_set_scrollbar_mode(apply->refuse_imagebtn, LV_SCROLLBAR_MODE_OFF);
	//Set style for screen_friend_imgbtn_20. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(apply->refuse_imagebtn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(apply->refuse_imagebtn, lv_color_make(0x75, 0x75, 0x75), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(apply->refuse_imagebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(apply->refuse_imagebtn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(apply->refuse_imagebtn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(apply->refuse_imagebtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(apply->refuse_imagebtn, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(apply->refuse_imagebtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	//Set style for screen_friend_imgbtn_20. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(apply->refuse_imagebtn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(apply->refuse_imagebtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(apply->refuse_imagebtn, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(apply->refuse_imagebtn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(apply->refuse_imagebtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	//Set style for screen_friend_imgbtn_20. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(apply->refuse_imagebtn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(apply->refuse_imagebtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(apply->refuse_imagebtn, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(apply->refuse_imagebtn, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(apply->refuse_imagebtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(apply->refuse_imagebtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(apply->refuse_imagebtn, LV_IMGBTN_STATE_RELEASED, NULL, &_25_1_alpha_30x30, NULL);
	lv_imgbtn_set_src(apply->refuse_imagebtn, LV_IMGBTN_STATE_PRESSED, NULL, &_25_2_alpha_30x30, NULL);
	lv_imgbtn_set_src(apply->refuse_imagebtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_25_1_alpha_30x30, NULL);
	lv_imgbtn_set_src(apply->refuse_imagebtn, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_25_2_alpha_30x30, NULL);
	lv_obj_add_flag(apply->refuse_imagebtn, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_add_event_cb(apply->btn, screen_main_contacts_friend_look_apply_detail_info_handler, LV_EVENT_ALL, (void *)(apply->id));

    contacts_page.friend_apply_cont.apply_num++;
    strcpy(apply->id, data->id);

    return;
}