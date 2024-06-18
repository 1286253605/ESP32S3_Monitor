#include "app.h"
#include "screen1.h"
#include "screen2.h"
#include "screen3.h"

void event_screen1(lv_event_t* e);
void event_screen2(lv_event_t* e);
void event_screen3(lv_event_t* e);


void init_app(void)
{
    screen1 = lv_obj_create(NULL);
    screen2 = lv_obj_create(NULL);
    screen3 = lv_obj_create(NULL);
}

void eventHandlerSwitchPage(lv_event_t* e)
{
    /* 获得用户传入的屏幕指针 */
    //lv_obj_t* next_page = (lv_obj_t*)lv_event_get_user_data(e);
    lv_obj_t* next_page = (lv_obj_t*)e->user_data;
    lv_scr_load_anim(next_page, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
}

void add_callback(void)
{
    lv_obj_add_event_cb(s1_all.btn_next, eventHandlerSwitchPage, LV_EVENT_CLICKED, screen2);
    lv_obj_add_event_cb(s2_all.scr2_btn_next, eventHandlerSwitchPage, LV_EVENT_CLICKED, screen1);

    lv_obj_add_event_cb(screen1, event_screen1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(screen2, event_screen2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(screen3, event_screen3, LV_EVENT_ALL, NULL);
}


void start_app(void)
{
    init_app();
    scr1_create();
    scr2_create();
    scr3_create();
    add_callback();

    lv_scr_load(screen1);
}


/*************滑动屏幕回调触发切屏***************/
void event_screen1(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE &&
        lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        lv_scr_load_anim(screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
    }
}
void event_screen2(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE &&
        lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_scr_load_anim(screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, false);
    }
    else if (event_code == LV_EVENT_GESTURE &&
        lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT)
    {
        lv_scr_load_anim(screen3, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);
    }
}

void event_screen3(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE &&
        lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_scr_load_anim(screen2, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, false);
    }
}
