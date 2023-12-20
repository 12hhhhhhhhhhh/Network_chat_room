#include "contacts_page.h"

static void screen_main_contacts_friend_item_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_modify_remark_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_modify_remark_yes_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_modify_remark_no_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_delete_friend_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_delete_friend_no_event_handler(lv_event_t *e);
static void screen_main_contacts_friend_delete_friend_yes_event_handler(lv_event_t *e);

/*
    初始化联系人(好友、群聊)页面的相关信息
*/
void contacts_page_init(void){
    contacts_page.manage_btn = guider_ui.screen_main_imgbtn_manage_31;
    contacts_page.friend_btn = guider_ui.screen_main_imgbtn_friend_2;
    contacts_page.group_btn = guider_ui.screen_main_imgbtn_group_12;
    contacts_page.manage_cont = guider_ui.screen_main_group_infor_cont_1;
    contacts_page.friend_cont = guider_ui.screen_main_friend_infor_cont_1;
    contacts_page.manage_cont = guider_ui.screen_main_manage_fri_group_cont_1;
    //初始化好友页面
    contacts_page.friend_info.delete_btn = guider_ui.screen_main_imgbtn_11;
    contacts_page.friend_info.flag_spangroup = guider_ui.screen_main_spangroup_2;
    contacts_page.friend_info.head_image = guider_ui.screen_main_img_6;
    contacts_page.friend_info.id_label = guider_ui.screen_main_label_20;
    contacts_page.friend_info.list = guider_ui.screen_main_friend_list_1;
    contacts_page.friend_info.message_btn = guider_ui.screen_main_imgbtn_2;
    contacts_page.friend_info.modify_btn = guider_ui.screen_main_imgbtn_12;
    contacts_page.friend_info.name_label = guider_ui.screen_main_label_18;
    contacts_page.friend_info.remark_label = guider_ui.screen_main_label_21;
    contacts_page.friend_info.telphone_btn = guider_ui.screen_main_imgbtn_3;
    //删除好友弹窗
    contacts_page.friend_info.delete_cont.cont = guider_ui.screen_main_delete_friend_cont_5;
    contacts_page.friend_info.delete_cont.yes_btn = guider_ui.screen_main_imgbtn_4;
    contacts_page.friend_info.delete_cont.no_btn = guider_ui.screen_main_imgbtn_5;
    //修改好友备注弹窗
    contacts_page.friend_info.modify_cont.cont = guider_ui.screen_main_edit_remark_cont_5;
    contacts_page.friend_info.modify_cont.remark_textarea = guider_ui.screen_main_ta_8;
    contacts_page.friend_info.modify_cont.yes_btn = guider_ui.screen_main_btn_7;
    contacts_page.friend_info.modify_cont.no_btn = guider_ui.screen_main_btn_6;

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
        contacts_page.friend_info.friend_item[i].item = lv_list_add_btn(guider_ui.screen_main_friend_list_1, &_4_alpha_20x20, temnode->info.name);

        lv_obj_add_style(contacts_page.friend_info.friend_item[i].item, &(guider_ui.style_screen_main_friend_list_1_extra_btns_main_default), LV_PART_MAIN|LV_STATE_DEFAULT);
	    lv_obj_add_style(contacts_page.friend_info.friend_item[i].item, &(guider_ui.style_screen_main_friend_list_1_extra_btns_main_focused), LV_PART_MAIN|LV_STATE_FOCUSED);

        lv_obj_add_event_cb(contacts_page.friend_info.friend_item[i].item, screen_main_contacts_friend_item_event_handler, LV_EVENT_CLICKED, &guider_ui);
        contacts_page.friend_info.friend_count++;
        i++;
    }
    temnode = NULL;
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
        lv_img_set_src(contacts_page.friend_info.head_image, &_4_alpha_80x80);              //头像
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
        lv_obj_set_pos(guider_ui.screen_main_edit_remark_cont_5, 230, 100);
		lv_obj_clear_flag(guider_ui.screen_main_edit_remark_cont_5, LV_OBJ_FLAG_HIDDEN);
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
		lv_obj_add_flag(guider_ui.screen_main_edit_remark_cont_5, LV_OBJ_FLAG_HIDDEN);
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
		lv_obj_add_flag(guider_ui.screen_main_edit_remark_cont_5, LV_OBJ_FLAG_HIDDEN);
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
        lv_obj_set_pos(guider_ui.screen_main_delete_friend_cont_5, 230, 100);
		lv_obj_clear_flag(guider_ui.screen_main_delete_friend_cont_5, LV_OBJ_FLAG_HIDDEN);
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
		lv_obj_add_flag(guider_ui.screen_main_delete_friend_cont_5, LV_OBJ_FLAG_HIDDEN);
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
		lv_obj_add_flag(guider_ui.screen_main_delete_friend_cont_5, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}