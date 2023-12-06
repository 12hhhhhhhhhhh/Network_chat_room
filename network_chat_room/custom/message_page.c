#include "message_page.h"

/*
    消息页面列表中的item事件
*/
static void screen_main_message_item_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_current_target(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
        for(int i=0; i<cell_count; i++){
            lv_obj_clear_state(message_page_cell[i].list_item, LV_STATE_FOCUSED);
            if(message_page_cell[i].list_item == obj){
                lv_obj_add_state(message_page_cell[i].list_item, LV_STATE_FOCUSED);
                int j = 0;
                while(message_page_cell[i].info.news[j] != NULL){
                    
                }
            }
        }
	}
		break;
	default:
		break;
	}
}

/*
    初始化消息页面
*/
void message_page_init(void){
    char buf[256] = {0};
    FRIEND_NODE *temnode = NULL;
    //遍历好友信息链表
    temnode = head_friend_node;
    while(temnode->next){
        temnode = temnode->next;
        //如果有新消息，则将发送人添加至消息页面
        if(temnode->info.news != NULL){
            if(temnode->info.remark != NULL){
                sprintf(buf, "%s", temnode->info.remark); 
            }
            else{
                sprintf(buf, "%s", temnode->info.name); 
            }
            memcpy(&(message_page_cell[cell_count].info), &(temnode->info), sizeof(FRIEND_INFO)); 
            message_page_cell[cell_count].list_item = lv_list_add_btn(guider_ui.screen_main_friend_list_1, &_4_alpha_20x20, buf);
            cell_count++;
        }
    }
    
    
}