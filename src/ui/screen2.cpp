#include "screen2.h"

lv_obj_t* screen2;

lv_obj_t* scr2_btn_next;
lv_obj_t* scr2_label_main;
lv_obj_t* btn_style_test;


void scr2_create(void)
{
    /*----style----*/
    static lv_style_t btn_style;
    lv_style_init(&btn_style);
    lv_style_set_radius(&btn_style, 5);
    lv_style_set_shadow_width(&btn_style, 8);
    lv_style_set_shadow_ofs_x(&btn_style, 5);
    lv_style_set_shadow_ofs_y(&btn_style, 5);
    lv_style_set_border_width(&btn_style, 3);


    /* lv_palette_main用于获取调色板颜色 还可以用lv_palette_lighten 或 lv_palette_darken */
    lv_palette_t btn_border_color_lighten = LV_PALETTE_CYAN;
    lv_style_set_border_color(&btn_style,
        lv_palette_lighten(btn_border_color_lighten, 3));
    
    /*----component----*/
    scr2_btn_next = lv_btn_create(screen2);
    lv_obj_set_size(scr2_btn_next, 60, 30);
    lv_obj_align(scr2_btn_next, LV_ALIGN_CENTER, 0, 0);

    btn_style_test = lv_btn_create(screen2);
    lv_obj_set_size(btn_style_test, 60, 30);
    lv_obj_align_to(btn_style_test, scr2_btn_next,
        LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    /* 有组件部分和组件状态两种 可以使用位运算合并 如LV_STATE_DEFAULT | LV_PART_MAIN */
    lv_obj_add_style(btn_style_test, &btn_style, LV_STATE_DEFAULT);


}
