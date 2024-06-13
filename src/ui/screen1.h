#ifndef _SCREEN_1_H
#define _SCREEN_1_H

#define SIMULATOR
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

    lv_obj_t* label_cpu_txt;
    lv_obj_t* label_cpu_temp;
    lv_obj_t* label_cpu_load;

    lv_obj_t* label_gpu_txt;
    lv_obj_t* label_gpu_temp;
    lv_obj_t* label_gpu_load;

    lv_obj_t* label_ram_txt;
    lv_obj_t* label_ram_temp;
    lv_obj_t* label_ram_load;

    lv_obj_t* slider_main;
    lv_obj_t* slider_gpu;
    lv_obj_t* slider_ram;

    lv_obj_t* label_large_load_main;
    lv_obj_t* label_large_load_gpu;
    lv_obj_t* label_large_load_ram;
} s1_all_obj;

extern s1_all_obj s1_all;



void scr1_create(void);
#endif // !_SCREEN_1_H

