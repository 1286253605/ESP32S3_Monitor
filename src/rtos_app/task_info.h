#ifndef _RTOS_APP_H
#define _RTOS_APP_H
void task_parser_serial_data(void* arg);
extern int pc_data_array[];

enum BYTE_POS
{
    POS_CLOAD = 0, POS_CTEMP, POS_GLOAD, POS_GTEMP, POS_RLOAD
};

#endif