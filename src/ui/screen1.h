#ifndef _SCREEN_1_H
#define _SCREEN_1_H

// #define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR

extern lv_obj_t* screen1;

typedef struct
{
    lv_obj_t* btn_next;
    lv_obj_t* label_main;

    lv_obj_t* area_1_1;
    lv_obj_t* area_2_1;
    lv_obj_t* area_2_2;
} scr1_objs;

extern scr1_objs s1_all_obj;


void scr1_create(void);
#endif // !_SCREEN_1_H

