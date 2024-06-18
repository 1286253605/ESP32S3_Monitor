#include "screen3.h"

lv_obj_t* screen3;
s3_all_obj s3_all;
bool circular;

void add_list_obj(const char* app_name, int index);
static void onScroll(lv_event_t* e);
static void onScroll_2(lv_event_t* e);
static void onScroll_3(lv_event_t* e);

void scr3_create(void)
{
    lv_obj_clear_flag(screen3, LV_OBJ_FLAG_SCROLLABLE);

    s3_all.app_list_obj = lv_obj_create(screen3);

    lv_obj_set_width(s3_all.app_list_obj, lv_pct(100));
    lv_obj_set_height(s3_all.app_list_obj, lv_pct(100));
    lv_obj_set_align(s3_all.app_list_obj, LV_ALIGN_TOP_MID);
    /* 弹性布局 子控件垂直（列）分布 */
    lv_obj_set_flex_flow(s3_all.app_list_obj, LV_FLEX_FLOW_COLUMN);
    /* 参数2 主轴(垂直轴)子控件的分布方式   参数3 交叉轴(水平轴)子控件分布方式 */
    /* 参数4 当子控件超出弹性容器的范围 会将多余的子控件移到新的一行 参数3用于规定该行对齐方式 */
    lv_obj_set_flex_align(s3_all.app_list_obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(s3_all.app_list_obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(s3_all.app_list_obj, LV_DIR_VER);

    lv_obj_set_style_radius(s3_all.app_list_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(s3_all.app_list_obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(s3_all.app_list_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(s3_all.app_list_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(s3_all.app_list_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(s3_all.app_list_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(s3_all.app_list_obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(s3_all.app_list_obj, 70, LV_PART_MAIN | LV_STATE_DEFAULT);

    add_list_obj("Notifications", 0);
    add_list_obj("Weather", 1);
    add_list_obj("APP Info", 2);
    add_list_obj("APP Info", 3);
    add_list_obj("APP Info", 4);
    add_list_obj("APP Info", 5);
    add_list_obj("APP Info", 6);
    add_list_obj("APP Info", 7);
    lv_obj_add_event_cb(s3_all.app_list_obj, onScroll, LV_EVENT_SCROLL, NULL);
    //lv_obj_scroll_by(s3_all.app_list_obj, 0, 10, LV_ANIM_OFF);
    //lv_obj_add_event_cb(screen3, onScroll_2, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(screen3, onScroll_3, LV_EVENT_SCREEN_LOADED, NULL);
    
    
}


void onAppListClicked(lv_event_t* e)
{
    lv_disp_t* display = lv_disp_get_default();
    lv_obj_t* actScr = lv_disp_get_scr_act(display);
    if (actScr != screen3)
    {
        return;
    }
    int index = (int)lv_event_get_user_data(e);
    //switch (index)
    //{
    //    case 0:
    //}
}

static void onScroll(lv_event_t* e)
{
    lv_obj_t* list = lv_event_get_target(e);

    lv_area_t list_a;
    lv_obj_get_coords(list, &list_a);
    lv_coord_t list_y_center = list_a.y1 + lv_area_get_height(&list_a) / 2;

    lv_coord_t r = lv_obj_get_height(list) * 7 / 10;
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(list);
    for (i = 0; i < child_cnt; i++)
    {
        lv_obj_t* child = lv_obj_get_child(list, i);
        lv_area_t child_a;
        lv_obj_get_coords(child, &child_a);

        lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;

        lv_coord_t diff_y = child_y_center - list_y_center;
        diff_y = LV_ABS(diff_y);

        /*Get the x of diff_y on a circle.*/
        lv_coord_t x;
        /*If diff_y is out of the circle use the last point of the circle (the radius)*/
        if (diff_y >= r)
        {
            x = r;
        }
        else
        {
            /*Use Pythagoras theorem to get x from radius and y*/
            uint32_t x_sqr = r * r - diff_y * diff_y;
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000); /*Use lvgl's built in sqrt root function*/
            x = r - res.i;
        }

        /*Translate the item by the calculated X coordinate*/
        lv_obj_set_style_translate_x(child, x, 0);

        /*Use some opacity with larger translations*/
        // lv_opa_t opa = lv_map(x, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
        // lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}
/* 弃用 */
static void onScroll_2(lv_event_t* e)
{
    lv_obj_t* list = s3_all.app_list_obj;
    lv_area_t list_a;
    lv_obj_get_coords(list, &list_a);
    lv_coord_t list_y_center = list_a.y1 + lv_area_get_height(&list_a) / 2;

    lv_coord_t r = lv_obj_get_height(list) * 7 / 10;
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(list);
    for (i = 0; i < child_cnt; i++)
    {
        lv_obj_t* child = lv_obj_get_child(list, i);
        lv_area_t child_a;
        lv_obj_get_coords(child, &child_a);

        lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;

        lv_coord_t diff_y = child_y_center - list_y_center;
        diff_y = LV_ABS(diff_y);

        /*Get the x of diff_y on a circle.*/
        lv_coord_t x;
        /*If diff_y is out of the circle use the last point of the circle (the radius)*/
        if (diff_y >= r)
        {
            x = r;
        }
        else
        {
            /*Use Pythagoras theorem to get x from radius and y*/
            uint32_t x_sqr = r * r - diff_y * diff_y;
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000); /*Use lvgl's built in sqrt root function*/
            x = r - res.i;
        }

        /*Translate the item by the calculated X coordinate*/
        lv_obj_set_style_translate_x(child, x, 0);

        /*Use some opacity with larger translations*/
        // lv_opa_t opa = lv_map(x, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
        // lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}
static void onScroll_3(lv_event_t* e)
{
    lv_obj_scroll_by(s3_all.app_list_obj, 0, 1, LV_ANIM_OFF);
}

void add_list_obj(const char* app_name, int index)
{
    lv_obj_t* ui_appListPanel = lv_obj_create(s3_all.app_list_obj);
    lv_obj_set_width(ui_appListPanel, 200);
    lv_obj_set_height(ui_appListPanel, 64);
    lv_obj_set_align(ui_appListPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_appListPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_appListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ui_appListPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_appListPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_appListPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_appListPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_appListPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_appListPanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_appListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_appListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_appListPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_appListPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_obj_t* ui_appListIcon = lv_img_create(ui_appListPanel);
    //lv_img_set_src(ui_appListIcon, img);
    //lv_obj_set_width(ui_appListIcon, LV_SIZE_CONTENT);  /// 1
    //lv_obj_set_height(ui_appListIcon, LV_SIZE_CONTENT); /// 1
    //lv_obj_set_x(ui_appListIcon, -74);
    //lv_obj_set_y(ui_appListIcon, 2);
    //lv_obj_set_align(ui_appListIcon, LV_ALIGN_CENTER);
    //lv_obj_add_flag(ui_appListIcon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    //lv_obj_clear_flag(ui_appListIcon, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    //lv_img_set_zoom(ui_appListIcon, 150);

    lv_obj_t* ui_appListLabel = lv_label_create(ui_appListPanel);
    lv_obj_set_width(ui_appListLabel, 160);
    lv_obj_set_height(ui_appListLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_appListLabel, 54);
    lv_obj_set_y(ui_appListLabel, 3);
    lv_obj_set_align(ui_appListLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_appListLabel, app_name);
    lv_label_set_long_mode(ui_appListLabel, LV_LABEL_LONG_CLIP);
    lv_obj_set_style_text_font(ui_appListLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_appListPanel, onAppListClicked, LV_EVENT_CLICKED, (void*)index);
}
