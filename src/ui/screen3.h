#ifndef _SCREEN_3_H
#define _SCREEN_3_H

#define SIMULATOR
#ifdef SIMULATOR
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif // SIMULATOR

typedef struct
{
    lv_obj_t* app_list_obj;
} s3_all_obj;

extern s3_all_obj s3_all;
extern lv_obj_t* screen3;


void scr3_create(void);
#endif // !_SCREEN_3_H

