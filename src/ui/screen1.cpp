#include "screen1.h"

lv_obj_t* screen1;


void create_slider(lv_obj_t** slider, lv_obj_t* parent, lv_obj_t* align_txt);
void create_large_txt(lv_obj_t** label, lv_obj_t* parent, const char* name);
void create_temp_load(lv_obj_t** temp, lv_obj_t** load, lv_obj_t* parent, lv_obj_t* align_obj);
void create_large_Load( lv_obj_t** label_big, lv_obj_t* parent );
s1_all_obj s1_all;


void scr1_create(void)
{

    /*----------------网格区域----------------*/
    s1_all.area_1_1 = lv_obj_create(screen1);
    s1_all.area_2_1 = lv_obj_create(screen1);
    s1_all.area_2_2 = lv_obj_create(screen1);
    /*----------------切屏按钮----------------*/
    s1_all.btn_next = lv_btn_create(s1_all.area_2_2);
    lv_obj_set_size(s1_all.btn_next, 60, 30);
    lv_obj_align(s1_all.btn_next, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    /*----------------Label以及长文本显示----------------*/
    s1_all.label_main = lv_label_create(s1_all.btn_next);
    /* long_mode函数必须要放在setSize前面 最后才用Size固定宽度*/
    /* 文字过长则循环展示模式 */
    lv_label_set_long_mode(s1_all.label_main, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_size(s1_all.label_main, 50, 20);
    lv_label_set_text(s1_all.label_main, "HELLO!LVGLv8!");
    lv_obj_align(s1_all.label_main, LV_ALIGN_CENTER, 0, 0);

    /*----------------网格布局----------------*/
    /* 分割为2x2区域 LV_GRID_FR(x) 表示该列或行占用可用空间的 x个分数单位*/
    static lv_coord_t grid_scr1_col_dsc[] = { LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST };
    static lv_coord_t grid_scr1_row_dsc[] = { LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST };
    lv_obj_set_grid_dsc_array(screen1, grid_scr1_col_dsc, grid_scr1_row_dsc);
    /* Area(1,1)占据两个单位在网格中坐标为(0,0) 占据两列一行 */
    lv_obj_set_grid_cell(s1_all.area_1_1, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_grid_cell(s1_all.area_2_1, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_cell(s1_all.area_2_2, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);
    //static lv_coord_t grid

    /*----------------CPU部分----------------*/
    /* 大写显示 */
    create_large_txt(&s1_all.label_cpu_txt, s1_all.area_1_1, "CPU");
    create_temp_load(&s1_all.label_cpu_temp, &s1_all.label_cpu_load,
        s1_all.area_1_1, s1_all.slider_main);
    /* Slider CPU*/
    create_slider(&s1_all.slider_main, s1_all.area_1_1, s1_all.label_cpu_txt);
    /* 末尾的数显 */
    create_large_Load(&s1_all.label_large_load_main, s1_all.area_1_1);


    /*----------------GPU部分----------------*/
    /* 大写显示 */
    create_large_txt(&s1_all.label_gpu_txt, s1_all.area_2_1, "GPU");
    /* Slider GPU*/
    create_slider(&s1_all.slider_gpu, s1_all.area_2_1, s1_all.label_gpu_txt);
    create_temp_load(&s1_all.label_gpu_temp, &s1_all.label_gpu_load,
        s1_all.area_2_1, s1_all.slider_gpu);
    /* 末尾的数显 */
    create_large_Load(&s1_all.label_large_load_gpu, s1_all.area_2_1);


    /*----------------RAM部分----------------*/
    /* 大写显示 */
    create_large_txt(&s1_all.label_ram_txt, s1_all.area_2_2, "RAM");
    create_temp_load(&s1_all.label_ram_temp, &s1_all.label_ram_load,
        s1_all.area_2_2, s1_all.slider_ram);
    /* Slider RAM*/
    create_slider(&s1_all.slider_ram, s1_all.area_2_2, s1_all.label_ram_txt);
    /* 末尾的数显 */
    create_large_Load(&s1_all.label_large_load_ram, s1_all.area_2_2);
}

void create_slider(lv_obj_t** slider, lv_obj_t* parent, lv_obj_t* align_txt)
{
    static lv_style_t style_knob;
    static lv_style_t style_slider_main;
    lv_style_init(&style_knob);
    lv_style_init(&style_slider_main);
    lv_style_set_bg_opa(&style_knob, LV_OPA_0);
    *slider = lv_slider_create(parent);
    lv_obj_add_style(*slider, &style_knob, LV_PART_KNOB);

    lv_style_set_radius(&style_slider_main, 2);
    lv_obj_add_style(*slider, &style_slider_main, LV_PART_MAIN);
    lv_obj_add_style(*slider, &style_slider_main, LV_PART_INDICATOR);

    lv_obj_set_style_border_width(*slider, 2, LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(*slider,
        lv_palette_lighten(LV_PALETTE_BLUE_GREY, 2), LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(*slider, 5, LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(*slider, 5, LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(*slider, 10, LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(*slider, LV_OPA_40, LV_STATE_DEFAULT);
    lv_obj_set_size(*slider, 300, 50);
    //lv_obj_align_to(slider, align_txt, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_obj_center(*slider);
    lv_obj_clear_flag(*slider, LV_OBJ_FLAG_CLICKABLE);

    lv_slider_set_range(*slider, 0, 100);
    lv_slider_set_value(*slider, 50, LV_ANIM_OFF);
}


void create_large_txt(lv_obj_t** label, lv_obj_t* parent, const char* name)
{
    static lv_style_t style_cpu;
    lv_style_init(&style_cpu);
    lv_style_set_text_font(&style_cpu, &lv_font_montserrat_40);
    lv_style_set_text_color(&style_cpu, lv_palette_lighten(LV_PALETTE_BLUE, 2));
    lv_style_set_shadow_opa(&style_cpu, LV_OPA_40);
    *label = lv_label_create(parent);
    lv_obj_add_style(*label, &style_cpu, LV_STATE_DEFAULT);
    lv_label_set_text(*label, name);
    lv_obj_align(*label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_border_width(*label, 2, LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(*label,
        lv_palette_lighten(LV_PALETTE_BLUE_GREY, 2), LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(*label, 5, LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(*label, 5, LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(*label, 5, LV_STATE_DEFAULT);

}

void create_temp_load(lv_obj_t** temp, lv_obj_t** load, lv_obj_t* parent, lv_obj_t* align_obj)
{
    *temp = lv_label_create(parent);
    *load = lv_label_create(parent);

    //lv_obj_align_to(temp, align_obj, LV_ALIGN_OUT_LEFT_TOP, 0, 0);
    //lv_obj_align_to(load, align_obj, LV_ALIGN_OUT_LEFT_BOTTOM, 0, 0);
    lv_obj_align(*temp, LV_ALIGN_TOP_MID, -225, 30);
    lv_obj_align(*load, LV_ALIGN_TOP_MID, -225, 60);


    lv_label_set_text(*temp, "Temp:C");
    lv_label_set_text(*load, "Load:%");


}

void create_large_Load( lv_obj_t** label_big, lv_obj_t* parent )
{
    *label_big = lv_label_create(parent);
    static lv_style_t style_label;
    lv_style_init(&style_label);
    lv_style_set_text_font(&style_label, &lv_font_montserrat_48);
    lv_style_set_text_color(&style_label, lv_palette_lighten(LV_PALETTE_BLUE, 2));
    lv_obj_add_style(*label_big, &style_label, LV_STATE_DEFAULT);

    lv_obj_align(*label_big, LV_ALIGN_RIGHT_MID, -70, 0);
}
