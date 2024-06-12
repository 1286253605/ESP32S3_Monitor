#include "screen2.h"

lv_obj_t* screen2;
scr2_objs s2_all_obj;

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
    s2_all_obj.btn_next = lv_btn_create(screen2);
    lv_obj_set_size(s2_all_obj.btn_next, 60, 30);
    lv_obj_align(s2_all_obj.btn_next, LV_ALIGN_CENTER, 0, 0);

    s2_all_obj.btn_style_test = lv_btn_create(screen2);
    lv_obj_set_size(s2_all_obj.btn_style_test, 60, 30);
    lv_obj_align_to(s2_all_obj.btn_style_test, s2_all_obj.btn_next,
        LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    /* 有组件部分和组件状态两种 可以使用位运算合并 如LV_STATE_DEFAULT | LV_PART_MAIN */
    lv_obj_add_style(s2_all_obj.btn_style_test, &btn_style, LV_STATE_DEFAULT);


}
