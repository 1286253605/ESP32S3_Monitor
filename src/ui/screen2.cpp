#include "screen2.h"

lv_obj_t* screen2;

//lv_obj_t* scr2_btn_next;
//lv_obj_t* scr2_label_main;
//lv_obj_t* btn_style_test;
s2_all_obj s2_all;

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
    s2_all.scr2_btn_next = lv_btn_create(screen2);
    lv_obj_set_size(s2_all.scr2_btn_next, 60, 30);
    lv_obj_align(s2_all.scr2_btn_next, LV_ALIGN_BOTTOM_RIGHT, -30, -30);

    /* 有组件部分和组件状态两种 可以使用位运算合并 如LV_STATE_DEFAULT | LV_PART_MAIN */
    //lv_obj_add_style(btn_style_test, &btn_style, LV_STATE_DEFAULT);
    lv_obj_add_style(s2_all.scr2_btn_next, &btn_style, LV_STATE_DEFAULT);

    /*----chart----*/
    s2_all.chart_main = lv_chart_create(screen2);
    lv_obj_set_size(s2_all.chart_main, 700, 400);
    lv_obj_align(s2_all.chart_main, LV_ALIGN_CENTER, 0, -25);
    lv_chart_set_type(s2_all.chart_main, LV_CHART_TYPE_LINE);
    lv_chart_set_update_mode(s2_all.chart_main, LV_CHART_UPDATE_MODE_SHIFT);
    lv_chart_set_div_line_count(s2_all.chart_main, 30, 30);     /* 设置XY轴点数 */
    lv_chart_set_point_count(s2_all.chart_main, 30);            /* 设置一条数据线上有多少个点 */
    lv_chart_set_range(s2_all.chart_main, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_range(s2_all.chart_main, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_axis_tick(s2_all.chart_main, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 6, 2, true, 50);
    lv_chart_set_axis_tick(s2_all.chart_main, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 6, 2, true, 50);
    s2_all.ser1 = lv_chart_add_series(s2_all.chart_main,
        lv_color_hex(0x0000ff), LV_CHART_AXIS_PRIMARY_Y);
    s2_all.ser2 = lv_chart_add_series(s2_all.chart_main,
        lv_color_hex(0x229954), LV_CHART_AXIS_PRIMARY_Y);
    s2_all.ser3 = lv_chart_add_series(s2_all.chart_main,
        lv_color_hex(0xF4D03F), LV_CHART_AXIS_PRIMARY_Y);
    for (int i = 0; i < 50; i++)
    {
        lv_chart_set_next_value(s2_all.chart_main, s2_all.ser1, lv_rand(0,100));
        lv_chart_set_next_value(s2_all.chart_main, s2_all.ser2, lv_rand(0, 100));
        lv_chart_set_next_value(s2_all.chart_main, s2_all.ser3, lv_rand(0, 100));
    }

    s2_all.label_main = lv_label_create(screen2);
    lv_obj_align_to(s2_all.label_main, s2_all.chart_main, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_label_set_recolor(s2_all.label_main, true);
    lv_label_set_text(s2_all.label_main,
        "#0000ff ---CPU#     #229954 ---GPU#    #F4D03F ---RAM#");

    
}
