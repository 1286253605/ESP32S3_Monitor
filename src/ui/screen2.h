#ifndef _SCREEN_2_H
#define _SCREEN_2_H

// #define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR

extern lv_obj_t* screen2;

typedef struct
{
    lv_obj_t* btn_next;
    lv_obj_t* label_main;
    lv_obj_t* btn_style_test;
} scr2_objs;

extern scr2_objs s2_all_obj;



void scr2_create(void);
#endif // !_SCREEN_2_H
