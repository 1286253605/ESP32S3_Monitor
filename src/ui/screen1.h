#ifndef _SCREEN_1_H
#define _SCREEN_1_H

#define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR

extern lv_obj_t* screen1;

extern    lv_obj_t* btn_next;
extern    lv_obj_t* label_main;

extern    lv_obj_t* area_1_1;
extern    lv_obj_t* area_2_1;
extern    lv_obj_t* area_2_2;

extern    lv_obj_t* label_cpu_txt;
extern    lv_obj_t* label_cpu_temp;
extern    lv_obj_t* label_cpu_load;

extern    lv_obj_t* label_gpu_txt;
extern    lv_obj_t* label_gpu_temp;
extern    lv_obj_t* label_gpu_load;

extern    lv_obj_t* label_ram_txt;
extern    lv_obj_t* label_ram_temp;
extern    lv_obj_t* label_ram_load;

extern    lv_obj_t* slider_main;
extern    lv_obj_t* slider_gpu;
extern    lv_obj_t* slider_ram;





void scr1_create(void);
#endif // !_SCREEN_1_H

