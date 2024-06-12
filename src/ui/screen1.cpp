#include "screen1.h"

lv_obj_t* screen1;
scr1_objs s1_all_obj;

void scr1_create(void)
{
    
    /*----------------网格区域----------------*/
    s1_all_obj.area_1_1 = lv_obj_create(screen1);
    s1_all_obj.area_2_1 = lv_obj_create(screen1);
    s1_all_obj.area_2_2 = lv_obj_create(screen1);
    /*----------------切屏按钮----------------*/
    s1_all_obj.btn_next = lv_btn_create(s1_all_obj.area_1_1);
    lv_obj_set_size(s1_all_obj.btn_next, 60, 30);
    lv_obj_align(s1_all_obj.btn_next, LV_ALIGN_CENTER, 0, 0);
    /*----------------Label以及长文本显示----------------*/
    s1_all_obj.label_main = lv_label_create(s1_all_obj.btn_next);
    /* long_mode函数必须要放在setSize前面 最后才用Size固定宽度*/
    /* 文字过长则循环展示模式 */
    lv_label_set_long_mode(s1_all_obj.label_main, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_size(s1_all_obj.label_main, 50, 20);
    lv_label_set_text(s1_all_obj.label_main, "HELLO!LVGLv8!");
    lv_obj_align(s1_all_obj.label_main, LV_ALIGN_CENTER, 0, 0);

    /*----------------网格布局----------------*/
    /* 分割为2x2区域 LV_GRID_FR(x) 表示该列或行占用可用空间的 x个分数单位*/
    static lv_coord_t grid_scr1_col_dsc[] = { LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST };
    static lv_coord_t grid_scr1_row_dsc[] = { LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST };
    lv_obj_set_grid_dsc_array(screen1, grid_scr1_col_dsc, grid_scr1_row_dsc);
    /* Area(1,1)占据两个单位在网格中坐标为(0,0) 占据两列一行 */
    lv_obj_set_grid_cell(s1_all_obj.area_1_1, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_grid_cell(s1_all_obj.area_2_1, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_cell(s1_all_obj.area_2_2, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    //static lv_coord_t grid
}


