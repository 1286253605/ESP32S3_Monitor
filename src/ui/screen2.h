#ifndef _SCREEN_2_H
#define _SCREEN_2_H

#define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR

extern lv_obj_t* screen2;



extern    lv_obj_t* scr2_btn_next;
extern    lv_obj_t* label_main;
extern    lv_obj_t* btn_style_test;


void scr2_create(void);
#endif // !_SCREEN_2_H
