#include <Arduino.h>
#include "Vector.h"
#include "screen1.h"
#include "task_info.h"
#define DATA_ARRAY_MAX 10



Vector<int> pc_data_vector;
int pc_data_array[DATA_ARRAY_MAX];

void lvgl_port_lock(int timeout_ms);
void lvgl_port_unlock(void);
void set_UI_Data( int* data_array );

void task_parser_serial_data(void* arg)
{
    uint8_t index = 0;
    for(;;)
    {
        
        while ( Serial.available() > 0 )
        {
            /* 读取一帧数据 */
            String number_str = Serial.readStringUntil(',');
            if ( number_str.indexOf("end") == -1 )
            {
                number_str.trim();
                int temp = number_str.toInt();
                pc_data_array[index] = temp;
                // Serial.printf("%s:%d\n", number_str.c_str(), pc_data_array[index]);
                index++;
            } else {
                // Serial.printf("manba out %d\n", index);
                Serial.flush();
                break;
            }

        }
        /* 修改UI */
        lvgl_port_lock(-1);
        if ( index != 0)
        {
            set_UI_Data(pc_data_array);
            memset(pc_data_array, 0, DATA_ARRAY_MAX);
            index = 0;
        } 

        lvgl_port_unlock();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void set_UI_Data( int* data_array )
{
    
    lv_label_set_text_fmt(s1_all.label_large_load_main, "%d", data_array[POS_CLOAD]);
    lv_label_set_text_fmt(s1_all.label_large_load_gpu,  "%d", data_array[POS_GLOAD]);
    lv_label_set_text_fmt(s1_all.label_large_load_ram,  "%d", data_array[POS_RLOAD]);
    lv_slider_set_value( s1_all.slider_main, data_array[POS_CLOAD], LV_ANIM_OFF );
    lv_slider_set_value( s1_all.slider_gpu,  data_array[POS_GLOAD], LV_ANIM_OFF );
    lv_slider_set_value( s1_all.slider_ram,  data_array[POS_RLOAD], LV_ANIM_OFF );

}