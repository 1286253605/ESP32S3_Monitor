#include "app.h"
#include "screen1.h"
#include "screen2.h"

void init_app(void)
{
    screen1 = lv_obj_create(NULL);
    screen2 = lv_obj_create(NULL);
}

void eventHandlerSwitchPage(lv_event_t* e)
{
    /* 获得用户传入的屏幕指针 */
    //lv_obj_t* next_page = (lv_obj_t*)lv_event_get_user_data(e);
    lv_obj_t* next_page = (lv_obj_t*)e->user_data;
    lv_scr_load_anim(next_page, LV_SCR_LOAD_ANIM_FADE_ON, 10, 0, false);
}

void add_callback(void)
{
    lv_obj_add_event_cb(btn_next, eventHandlerSwitchPage, LV_EVENT_CLICKED, screen2);
    lv_obj_add_event_cb(scr2_btn_next, eventHandlerSwitchPage, LV_EVENT_CLICKED, screen1);
}

void timer_callback(lv_timer_t* timer)
{

}
void timer_create(void)
{
    lv_timer_t* my_timer = lv_timer_create(timer_callback, 1000, NULL);
}

void start_app(void)
{
    init_app();
    scr1_create();
    scr2_create();
    add_callback();
    timer_create();

    lv_scr_load(screen1);
}
