#ifndef _SCREEN_2_H
#define _SCREEN_2_H

#define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR

extern lv_obj_t* screen2;



//extern    lv_obj_t* scr2_btn_next;
//extern    lv_obj_t* label_main;
//extern    lv_obj_t* btn_style_test;

typedef struct
{
    lv_obj_t* chart_main;
    lv_obj_t* scr2_btn_next;
    lv_obj_t* label_main;
    lv_chart_series_t* ser1;
    lv_chart_series_t* ser2;
    lv_chart_series_t* ser3;
} s2_all_obj;

extern s2_all_obj s2_all;

void scr2_create(void);
#endif // !_SCREEN_2_H
